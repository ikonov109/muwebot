#pragma once
#include <Geode/Geode.hpp>

class SmartBot {
public:
    static bool isEnabled();
    static void setEnabled(bool enabled);
    static void reset();
    static void update(PlayLayer* playLayer, float dt);
};
