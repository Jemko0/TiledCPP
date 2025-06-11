#pragma once

#include "Common.h"
#include "raylib.h"

class ENGINE_API Engine
{
public:
    Engine()
    {

    }

    ~Engine()
    {

    }

    int Init()
    {
        while (!WindowShouldClose())
        {
            EngineLoop();
        }
    }

    int EngineLoop()
    {

    }
};