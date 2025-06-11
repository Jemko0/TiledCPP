#include "Engine.h"
#include "TWorld.h"
#include "TScene.h"
#include "Input.h"

int Engine::Init()
{
    InitWindow(m_ScreenWidth, m_ScreenHeight, "Tiled CPP");
    SetTargetFPS(144);

    Scene = TWorld::NewScene();

    while (!WindowShouldClose())
    {
        EngineLoop();
    }

    CloseWindow();
    return 0;
}

void Engine::EngineLoop()
{
    Input::HandleInput();

    Scene->Update(GetFrameTime());
}
