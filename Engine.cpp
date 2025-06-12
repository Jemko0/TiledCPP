#include "Engine.h"
#include "TWorld.h"
#include "TScene.h"
#include "Input.h"

Engine::Engine()
{
    GAssetManager = new AssetManager();
}

Engine::~Engine()
{
    delete GAssetManager;
}

int Engine::Init()
{
    InitWindow(m_ScreenWidth, m_ScreenHeight, "Tiled CPP");
    SetWindowTitle("Tiled Engine");
    SetTargetFPS(144);

    GScene = TWorld::NewScene();

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

    GScene->Update(GetFrameTime());
}
