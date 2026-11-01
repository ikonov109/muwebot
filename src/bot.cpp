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

    // Работаем только если игрок на земле (для куба)
    if (!player->m_isOnGround) return;

    // Получаем координаты игрока
    float pX = player->getPositionX();
    float pY = player->getPositionY();

    // Ищем препятствия впереди (в радиусе 100 пикселей)
    bool dangerAhead = false;
    
    if (layer->m_objects) {
        for (GameObject* obj : geode::cocos::CCArrayExt<GameObject*>(layer->m_objects)) {
            // Пропускаем пустые объекты и те, сквозь которые можно пройти
            if (!obj || obj->m_isPassable) continue;

            float objX = obj->getPositionX();
            float objY = obj->getPositionY();

            // Если объект впереди нас, но не слишком далеко
            if (objX > pX && objX < pX + 100.0f) {
                // Если объект на уровне ног или чуть выше
                if (objY >= pY - 15.0f && objY <= pY + 40.0f) {
                    dangerAhead = true;
                    break;
                }
            }
        }
    }

    // Если впереди опасность — прыгаем
    if (dangerAhead) {
        player->pushButton(PlayerButton::Jump);
        player->releaseButton(PlayerButton::Jump);
    }
}

class $modify(BotPlayLayer, PlayLayer) {
    void update(float dt) {
        PlayLayer::update(dt);
        SmartBot::update(this, dt);
    }
};
