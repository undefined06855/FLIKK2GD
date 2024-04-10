#pragma once
#include "Block.hpp"
#include "Param.hpp"
using namespace geode::prelude;

class BlockGroup {
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
    std::vector<Block*> blocks = {};
    std::string blockStringAdditions = "";
    bool isHSVException = false;

    BlockGroup* add(Block* block) {
        this->blocks.push_back(block);
        return this;
    }

    BlockGroup* set(std::string blockString) {
        if (blockString.empty()) log::info("empty blockString!!!!!");
        if (blockString == Param::forceHSVException) {
            log::info("Force HSV exception!");
            this->isHSVException = true;
            return this;
        }

        if (this->isHSVException) {
            blockString = BlockGroup::replaceAll(blockString, "42", "41");
            blockString = BlockGroup::replaceAll(blockString, "44", "43");
        }

        log::info("adding to BlockGroup's blockString with {}", blockString);
        this->blockStringAdditions += blockString;
        return this;
    }

    std::string commit(float x, float y, float rotation) {
        std::string ret = "";
        log::info("Committing BlockGroup with {} blocks (additions={})", this->blocks.size(), this->blockStringAdditions);
        for (Block* block : this->blocks) {
            block->set(this->blockStringAdditions);
            ret += block->commit(x, y, rotation);
        }
        return ret;
    }
};
