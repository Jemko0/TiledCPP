#pragma once

#include "Engine.h"

namespace DataTypes
{
	struct IntVector2
	{
	public:
		int x;
		int y;

		IntVector2(int x, int y)
		{
			this->x = x;
			this->y = y;
		}

		IntVector2()
		{
			x = 0;
			y = 0;
		}
	};

	struct Vector3
	{
	public:
		float x;
		float y;
		float z;
	};

	struct Vector4
	{
	public:
		float x;
		float y;
		float z;
		float w;
	};
}