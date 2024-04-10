#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include "Flikk2GDPopup.hpp"

using namespace geode::prelude;

class $modify(FlikkedEditorUI, EditorUI) {
	void onFlikkImport(CCObject*) {
		CCScene::get()->addChild(Flikk2GDPopup::create());
	}

	void createMoveMenu() {
		EditorUI::createMoveMenu();

		auto* btn = this->getSpriteButton(
			"flikkman.png"_spr,
			menu_selector(FlikkedEditorUI::onFlikkImport),
			nullptr,
			0.9f
		);

		this->m_editButtonBar->m_buttonArray->addObject(btn);

		int rows = GameManager::sharedState()->getIntGameVariable("0049");
		int cols = GameManager::sharedState()->getIntGameVariable("0050");
		this->m_editButtonBar->reloadItems(rows, cols);
	}
};
