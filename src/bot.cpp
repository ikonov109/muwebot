#include "bot.hpp"
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

static bool g_botEnabled = false;

bool SmartBot::isEnabled() { return g_botEnabled; }
void SmartBot::setEnabled(bool enabled) { g_botEnabled = enabled; }

void SmartBot::update(PlayLayer* layer, float dt) {
    // Если бот выключен или мы мертвы — ничего не делаем
    if (!g_botEnabled || !layer || !layer->m_player1) return;
    if (layer->m_player1->m_isDead) return;

    // В тестовом режиме просто ждем, пока ты нажмешь кнопку на экране.
    // Для реального бота здесь будет проверка шипов.
}

class $modify(BotPlayLayer, PlayLayer) {
    // Хукаем нажатие кнопок в игре
    void handleButton(bool down, int button, bool isPlayer1) {
        PlayLayer::handleButton(down, button, isPlayer1);

        // Если бот включен и нажата кнопка прыжка (button == 1)
        if (g_botEnabled && down && button == 1 && isPlayer1) {
            // Вместо стандартного прыжка, мы можем симулировать свой,
            // но пока просто логируем, чтобы проверить, что хук работает.
            log::info("Bot intercepted a jump!");
        }
    }
};
