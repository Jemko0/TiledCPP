#include "TTileMap.h"

TTileMap::TTileMap(int w, int h)
{
    Initialize(w, h);
}

void TTileMap::Initialize(int w, int h)
{
    width = w;
    height = h;

    tiles.resize(width);

    for (int x = 0; x < width; x++) {
        tiles[x].resize(height);
    }
}

void TTileMap::Cleanup()
{
    tiles.clear();
    tileFrames.clear();
    lightMap.clear();
    Super::Cleanup();
}

void TTileMap::BeginDestroy()
{
    Super::BeginDestroy();
}

void TTileMap::Update(float deltaTime)
{
    Super::Update(deltaTime);
}

bool TTileMap::IsSolidTile(int x, int y)
{
    return tiles[x][y];
}
