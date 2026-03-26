#include <raylib.h>
#include <raymath.h>

#include <cmath>
#include <iostream>
#include <numbers>
#include<string>

int main()
{
	int screenWidth = 1280;
	int screenHeight = 720;
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(1280, 720, "Demo");
	SetTargetFPS(60);

	Matrix vehicle = MatrixIdentity();
	Matrix vehicleRotation = MatrixRotateZ(45 * (PI / 180));
	Matrix vehicleTranslation = MatrixTranslate(screenWidth / 2, screenHeight / 2, 0);
	vehicle = MatrixMultiply(
	vehicleRotation,
	vehicleTranslation);

	Vector2 vehiclePoints[]
	{
		{-10.f, -15.f},
		{-10.f, 15.f},
		{10.f, 15.f},
		{10.f, -15.f},
	};
	const int pointSize = sizeof(vehiclePoints) / sizeof(vehiclePoints[0]);
	for (Vector2& point : vehiclePoints)
	{
		point = Vector2Transform(point, vehicle);
	}

	Vector2 lineStart{ 30, 30 };
	Vector2 lineEnd{ 0, 0 };
	//lineEnd = Vector2Transform(lineEnd, vehicle);
	//lineEnd = (lineEnd.x, lineEnd.y, 0, 1)

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

		for (int i = 0; i < pointSize; ++i)
		{
			DrawLineEx(
				vehiclePoints[i],
				vehiclePoints[(i + 1) % pointSize],
				4.f,
				RED
			);
		}

        //DrawLineEx(lineStart, lineEnd, 16.f, WHITE);
		DrawText(speedText.c_str(), 32, 32, 32, BLACK);


		EndDrawing();
	}

	CloseWindow();
}