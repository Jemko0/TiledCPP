#include "Input.h"
#include "raylib.h"

void Input::HandleInput()
{
	PollInputEvents();

	if (IsKeyDown(KEY_A))
	{
		lr = -1;
	}

	if (IsKeyDown(KEY_D))
	{
		lr = 1;
	}

	if (IsKeyDown(KEY_W))
	{
		ud = 1;
	}

	if (IsKeyDown(KEY_S))
	{
		ud = -1;
	}
}