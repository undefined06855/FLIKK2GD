#include <Geode/ui/TextInput.hpp>

using namespace geode::prelude;

class Flikk2GDPopup : public geode::Popup<> {
private:
    static std::vector<std::string> splitString(std::string str, char splitter);
    void convertFlikkFile(std::string data);

protected:
    void importFromID(CCObject* sender);
    void importFromFile(CCObject* sender);
    bool setup() override;

    TextInput* idField = nullptr;
public:
    static Flikk2GDPopup* create();
};
