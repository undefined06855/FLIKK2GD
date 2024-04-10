#pragma once
#include "Param.hpp"
using namespace geode::prelude;

class Block {
private:
    static std::string replaceAll(std::string str, const std::string& find, const std::string& replace) {
        size_t start_pos = 0;
        while ((start_pos = str.find(find, start_pos)) != std::string::npos) {
            str.replace(start_pos, find.length(), replace);
            start_pos += replace.length(); // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }

public:
    std::string blockString;
    bool isHSVException = false;
    bool needsToHaveBothHSVs = false;
    bool needsToBeHalfSpacedUpwards = false;

    Block(int id) {
        if (id == 211)
            this->isHSVException = true;
        if (id == 1153 || id == 1594 || id == 1144)
            this->needsToHaveBothHSVs = true;
        if (id == 468)
            this->needsToBeHalfSpacedUpwards = true;

        this->blockString = fmt::format("1,{},2,__X_POS,3,__Y_POS,6,__ROTATION,", id);
    }

    Block* set(std::string blockString) {
        std::string oldBlockString = blockString;

        if (blockString == Param::forceHSVException) {
            log::info("Force HSV Exception (block)");
            this->isHSVException = true;
            return this;
        }

        // HSVException applies the HSVs to the first colour instead of second
        if (this->isHSVException || this->needsToHaveBothHSVs) {
            blockString = Block::replaceAll(blockString, "42", "41");
            blockString = Block::replaceAll(blockString, "44", "43");
        }

        if (needsToHaveBothHSVs)
            this->blockString += oldBlockString;
        this->blockString += blockString;

        return this;
    }

    std::string commit(float x, float y, float rotation) {
        if (this->needsToBeHalfSpacedUpwards) y += 15;

        // for some reason flikk blocks are offset by half a block
        x += 15;
        y += 15;

        std::string newBlockString = this->blockString;
        newBlockString = Block::replaceAll(newBlockString, "__X_POS", std::to_string(x));
        newBlockString = Block::replaceAll(newBlockString, "__Y_POS", std::to_string(y));
        newBlockString = Block::replaceAll(newBlockString, "__ROTATION", std::to_string(rotation));
        newBlockString.pop_back(); // remove trailing comma
        log::info("Committing Block with blockString {}", newBlockString);
        return newBlockString + ";";
    }
};
