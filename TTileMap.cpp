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
