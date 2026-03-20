#include <raylib.h>
#include <raymath.h>

#include<string>

int main()
{
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(1280, 720, "Demo");
	SetTargetFPS(60);

	Vector2 lineStart{30, 30};
	Vector2 lineEnd{ 200, 200 };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		float deltaTime = GetFrameTime();

		Vector2 startMovement{};
		if (IsKeyDown(KEY_W))
		{
			startMovement.y -= 1;
		}
		if (IsKeyDown(KEY_A))
		{
			startMovement.x -= 1;
		}
		if (IsKeyDown(KEY_S))
		{
			startMovement.y += 1;
		}
		if (IsKeyDown(KEY_D))
		{
			startMovement.x += 1;
		}
		//startMovement{{-1,0,1}, {-1,0,1}};
		startMovement = Vector2Normalize(startMovement);
		startMovement = Vector2Scale(startMovement, 80.f * deltaTime);

		//lineStart += startMovement;
		lineStart = Vector2Add(lineStart, startMovement);

		float angleDiff = Vector2Angle(Vector2Subtract(lineEnd, lineStart), { 1,1 });
		angleDiff *= 180 / 3.14159f;
		std::string speedText = std::to_string(angleDiff);

        DrawLineEx(lineStart, lineEnd, 16.f, WHITE);
		DrawText(speedText.c_str(), 32, 32, 32, BLACK);


		EndDrawing();
	}

	CloseWindow();
}