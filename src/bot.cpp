#include "bot.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static bool g_botEnabled = false;

bool SmartBot::isEnabled() { return g_botEnabled; }
void SmartBot::setEnabled(bool enabled) { g_botEnabled = enabled; }

void SmartBot::update(PlayLayer* layer, float dt) {
    if (!g_botEnabled || !layer || !layer->m_player1) return;
    
    auto player = layer->m_player1;
    if (player->m_isDead) return;

    // ТЕСТ: Прыгаем каждые 2 секунды, если мы на земле.
    // Это нужно, чтобы проверить, работает ли вообще вызов прыжка.
    static float timer = 0.0f;
    timer += dt;
    
    if (timer > 2.0f) {
        timer = 0.0f;
        if (player->m_isOnGround) {
            player->pushButton(PlayerButton::Jump);
            player->releaseButton(PlayerButton::Jump);
            log::info("TEST JUMP!");
        }
    }
}

class $modify(BotPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        SmartBot::update(this, dt);
    }
};
