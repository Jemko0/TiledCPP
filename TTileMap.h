#pragma once

#include "Engine.h"
#include "FTile.h"
#include "DataTypes.h"
#include "TObject.h"

class ENGINE_API TTileMap : TObject
{
    TTileMap(int w, int h);

public:
    std::vector<std::vector<Tile::ETileType>> tiles;
    std::vector<std::vector<DataTypes::IVector2>> tileFrames;
    std::vector<std::vector<int>> lightMap;

    int width, height;

    void Initialize(int w, int h);
};