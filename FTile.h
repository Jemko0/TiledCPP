#pragma once

#include "raylib.h"

namespace Tile
{
	enum ETileType
	{
		Air = 0,
		Dirt,
		Grass,
		Stone,
		ETileType_MAX,
	};

	struct FTile
	{
	public:
		bool render = true;
		Texture2D texture;
	};
}