#include "bot.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static bool g_botEnabled = false;

bool SmartBot::isEnabled() { return g_botEnabled; }
void SmartBot::setEnabled(bool enabled) { g_botEnabled = enabled; }
void SmartBot::reset() { /* сброс */ }

void SmartBot::update(PlayLayer* layer, float dt) {
    if (!g_botEnabled || !layer || !layer->m_player1) return;
    // Логика бота будет здесь
}

class $modify(BotPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        SmartBot::update(this, dt);
    }
};
