#pragma once

#include "Engine.h"
#include "FTile.h"
#include "DataTypes.h"
#include "TObject.h"

class ENGINE_API TTileMap : public TObject
{
public:
    std::vector<std::vector<Tile::ETileType>> tiles;
    std::vector<std::vector<DataTypes::IntVector4>> tileFrames;
    std::vector<std::vector<int>> lightMap;

    TTileMap(int w, int h);

    int width, height;

    void Initialize(int w, int h);

    virtual void Cleanup() override;
    virtual void BeginDestroy() override;
    virtual void Update(float deltaTime) override;


    bool IsSolidTile(int x, int y);
};