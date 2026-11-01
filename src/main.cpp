#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "bot.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Bot ON/OFF"),
            this,
            menu_selector(MyMenuLayer::onToggleBot)
        );
        
        if (auto menu = this->getChildByID("bottom-menu")) {
            menu->addChild(btn);
        }
        return true;
    }

    void onToggleBot(CCObject* sender) {
        bool newState = !SmartBot::isEnabled();
        SmartBot::setEnabled(newState);
        log::info("Bot state: {}", newState ? "ON" : "OFF");
        
        // Меняем текст на кнопке
        auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(sender);
        if (btn) {
            if (auto spr = typeinfo_cast<ButtonSprite*>(btn->getNormalImage())) {
                spr->setString(newState ? "Bot: ON" : "Bot: OFF");
            }
        }
    }
};

$on_mod(Loaded) {
    log::info("MuWe Bot loaded");
}
