#include <Geode/Geode.hpp>
#include <Geode/ui/TextInput.hpp>
#include <Geode/utils/web.hpp>
#include "Flikk2GDPopup.hpp"
#include "BlockMappings.hpp"
#include "Block.hpp"
#include "Param.hpp"
using namespace geode::prelude;

float lastBlockRotation = 0.f;

Flikk2GDPopup* Flikk2GDPopup::create() {
    auto ret = new Flikk2GDPopup();
    if (ret && ret->initAnchored(240.f, 190.f)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool Flikk2GDPopup::setup() {
    auto win = CCDirector::get()->getWinSize();
    
    auto menu = CCMenu::create();
    menu->ignoreAnchorPointForPosition(false);
    menu->setID("main-menu");

    auto importButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Select .flkk"),
        this,
        menu_selector(Flikk2GDPopup::importFromFile)
    );
    importButton->setPosition(CCPoint{ win.width / 2, win.height / 2 + 40 });
    importButton->setID("import-button");
    menu->addChild(importButton);

    auto spacerLeft = CCSprite::create("streakb_01_001.png");
    spacerLeft->setPosition(CCPoint{ win.width / 2 - 65, win.height / 2 });
    spacerLeft->setScaleX(11.175f);
    spacerLeft->setScaleY(0.275f);
    spacerLeft->setOpacity(67);
    spacerLeft->setID("spacer-left");
    menu->addChild(spacerLeft);

    auto spacerRight = CCSprite::create("streakb_01_001.png");
    spacerRight->setPosition(CCPoint{ win.width / 2 + 65, win.height / 2 });
    spacerRight->setScaleX(11.175f);
    spacerRight->setScaleY(0.275f);
    spacerRight->setOpacity(67);
    spacerLeft->setID("spacer-right");
    menu->addChild(spacerRight);

    auto text = CCLabelBMFont::create("or", "bigFont.fnt");
    text->setPosition(CCPoint{ win.width / 2, win.height / 2 + 2});
    text->setScale(0.55f);
    text->setID("spacer-text");
    menu->addChild(text);

    this->idField = TextInput::create(180, "Level ID", "bigFont.fnt");
    this->idField->setFilter("1234567890");
    this->idField->setPosition(CCPoint{ win.width / 2, win.height / 2 - 28 });
    this->idField->setID("id-field");
    menu->addChild(this->idField);

    auto idSearchButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Search"),
        this,
        menu_selector(Flikk2GDPopup::importFromID)
    );
    idSearchButton->setPosition(CCPoint{ win.width / 2, win.height / 2 - 67 });
    idSearchButton->setID("search-button");
    menu->addChild(idSearchButton);

    this->m_mainLayer->addChild(menu);
    return true;
}
void Flikk2GDPopup::importFromID(CCObject* sender) {
    log::info("Import from id (id={})", this->idField->getString());
    auto body = matjson::Value();
    body.set("level", std::stoi(this->idField->getString()));
    // oh no leaking debug account parameters whatever will I do
    body.set("username", "DEBUG");
    body.set("password", "debugpassword");
    auto* _this = this;

    web::AsyncWebRequest()
        .join("flikkDataRequest")
        .body(body)
        .post("https://flicc.xyz:1002/level/get/single/data")
        .text()
        .then([this](std::string& data) {
            // this also includes json stuff that needs to be erased
            data.erase(0, 11);
            data.erase(data.length() - 2, 2);
            this->convertFlikkFile(data);
        })
        .expect([this](std::string const& error) {
            if (error == "500 Internal Server Error")
                FLAlertLayer::create("Error", "bro the level doesnt exist :skull:", "silly billy")->show();
            else
                FLAlertLayer::create("Error", "idk man something went wrong", "oh no")->show();

            log::warn("web error: {}", error);

            return;
        });
}
void Flikk2GDPopup::importFromFile(CCObject* sender) {
    log::info("Import from file");
    utils::file::pickFile(file::PickMode::OpenFile, {}, [this](ghc::filesystem::path const& path) {
        if (!path.string().ends_with(".flkk")) {
            FLAlertLayer::create("Error", "that's not a .flkk file dumbass", "ok blud")->show();
            return;
        }

        try {
            // get a stream, convert it to a buffer and pass to *Flikk2GDPopup::convertFlikkFile
            std::ifstream stream(path);
            std::stringstream buffer;
            buffer << stream.rdbuf();

            std::string data = buffer.str();
            this->convertFlikkFile(data);
        } catch (...) {
            FLAlertLayer::create("Error", "idk man something went wrong", "ok blud")->show();
            return;
        }
    });
}

std::vector<std::string> Flikk2GDPopup::splitString(std::string str, char splitter) {
    std::vector<std::string> result;
    std::string current = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == splitter) {
            if (current != "") {
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += str[i];
    }
    if (current.size() != 0)
        result.push_back(current);
    return result;
}

void Flikk2GDPopup::convertFlikkFile(std::string data) {
    log::info("Converting flikk file (length={})", data.length());
    log::info("{}", data);

    auto blocks = Flikk2GDPopup::splitString(data, ':');

    log::info("{} blocks in level", blocks.size());

    // test for legacy
    bool isLegacyLevel = Flikk2GDPopup::splitString(blocks[0], ',').size() == 4;
    log::info("is legacy? {}", (isLegacyLevel ? "yeah" : "no"));

    auto editor = LevelEditorLayer::get();

    // *LevelEditorLayer->getLevelString is actually a TodoReturn (should be gd::string)
    //log::info("{}", editor->getLevelString());

    // half opacity alpha trigger
    editor->createObjectsFromString((new Block(1007))->set(Param::alphaTriggerSetup)->commit(-60, 0, 0), true, true);

    // setup level data
    editor->m_levelSettings->m_backgroundIndex = 13; // blank background
    editor->createObjectsFromString((new Block(899))->set(Param::backgroundColorTriggerSetup)->commit(-60, 30, 0), true, true); // white bg colour
    editor->createObjectsFromString((new Block(899))->set(Param::objectColorTriggerSetup)->commit(-90, 30, 0), true, true); // black object colour
    editor->createObjectsFromString((new Block(899))->set(Param::blackBlendingColorTriggerSetup)->commit(-120, 30, 0), true, true); // black blending colour (9)
    editor->m_levelSettings->m_platformerMode = true;

    // place all the blocks
    for (std::string block : blocks) {
        auto chunks = Flikk2GDPopup::splitString(block, ',');
        int blockID = std::stoi(chunks[0]);
        // add initial x and y here as well
        // and multiply by 30 since each block is 30 units large maybe
        float x = std::stof(chunks[1])*30;
        float y = std::stof(chunks[2])*30;
        float rot = std::stof(chunks[3]);

        // unity rotation is reverse from gd 
             if (rot == 270) rot = 90;
        else if (rot == 90) rot = 270;

        log::info("block {} at {},{} (rot={})", chunks[0], chunks[1], chunks[2], chunks[3]);

        std::string blockData = "";

        if (blockID < blockMappings.size()) blockData = blockMappings[blockID]->commit(x, y, rot);
        else {
            log::info("ok so there's a block at {}, {} that i dont have block id for yet", x, y);
            blockData = (new Block(3853))->commit(x, y, rot);
        }

        editor->createObjectsFromString(
            blockData,
            // disable undo, skip max objects popup
            true, true
        );
    };

    this->onClose(nullptr);
}
