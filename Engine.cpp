#include "Engine.h"
#include "TWorld.h"
#include "TScene.h"
#include "Input.h"

Engine GEngine;

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
    GScene->Init();

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

    BeginDrawing();

    GScene->Update(GetFrameTime());
    GScene->Render();

    EndDrawing();
}
