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
	
	float vehicleSpeed = 180.f;

	const int pointSize = sizeof(vehiclePoints) / sizeof(vehiclePoints[0]);
	

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
			vehicleRotation = MatrixRotateZ(( - 45 * (PI / 180)) * deltaTime);
			vehicle = MatrixMultiply(vehicleRotation, vehicle);
		}
		if (IsKeyDown(KEY_S))
		{
			startMovement.y += 1;
		}
		if (IsKeyDown(KEY_D))
		{
			startMovement.x += 1;
			vehicleRotation = MatrixRotateZ((45 * (PI / 180)) * deltaTime);
			vehicle = MatrixMultiply((vehicleRotation), vehicle);
		}
		//startMovement{{-1,0,1}, {-1,0,1}};
		startMovement = Vector2Normalize(startMovement);
		vehicle = MatrixMultiply(
			MatrixTranslate(0, startMovement.y * vehicleSpeed * deltaTime, 0),
			vehicle
		);

		Vector2 updatedPoints[pointSize]{};

		
		for (int i = 0; i < pointSize; ++i)
		{
			updatedPoints[i] = Vector2Transform(vehiclePoints[i], vehicle);
		}
		/*for (Vector2& point : vehiclePoints)
		{
			point = Vector2Transform(point, vehicle);
		}*/

		for (int i = 0; i < pointSize; ++i)
		{
			DrawLineEx(
				updatedPoints[i],
				updatedPoints[(i + 1) % pointSize],
				4.f,
				RED
			);
		}

		EndDrawing();
	}

	CloseWindow();
}