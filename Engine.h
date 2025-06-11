#pragma once

#include "Common.h"
#include "raylib.h"

FORWARD_DECLARE(TWorld);
FORWARD_DECLARE(TScene);

class ENGINE_API Engine
{
private:
    int m_ScreenWidth = 480;
    int m_ScreenHeight = 360;

public:

    TScene* Scene;

    Engine() = default;
    ~Engine() = default;

    int Init();

private:
    void EngineLoop();
};