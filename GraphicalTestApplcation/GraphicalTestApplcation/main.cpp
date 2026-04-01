#include <raylib.h>
#include <raymath.h>

#include <cmath>
#include <iostream>
#include<string>

#include "Game.h"
#include "SceneObject.h"

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;
	SetTraceLogLevel(LOG_ERROR);
	InitWindow(1280, 720, "Demo");
	SetTargetFPS(60);

	Matrix vehicle = MatrixIdentity();
	Matrix vehicleRotation = MatrixRotateZ(45 * (PI / 180));
	Matrix vehicleTranslation = MatrixTranslate(screenWidth / 2, screenHeight / 2, 0);
	vehicle = MatrixMultiply(
		vehicleRotation,
		vehicleTranslation);

	Matrix turret = MatrixIdentity();
	Matrix turretTranslation = MatrixIdentity();

	Matrix bullet = MatrixIdentity();

	Vector2 bulletMovement{};

	Vector2 vehiclePoints[]
	{
		{-10.f, -15.f},
		{-10.f, 15.f},
		{10.f, 15.f},
		{10.f, -15.f},
	};
	
	Vector2 turretPoints[]
	{
		{-5.f, -30.f},
		{-5.f, 10.f},
		{5.f, 10.f},
		{5.f, -30.f},
	};
	Vector2 bulletPos{ 0, -30.f };
	
	bool fired = false;

	float vehicleSpeed = 180.f;

	const int pointSize = sizeof(vehiclePoints) / sizeof(vehiclePoints[0]);
	const int turretSize = sizeof(turretPoints) / sizeof(turretPoints[0]);

	Vector2 lineStart{ 30, 30 };
	Vector2 lineEnd{ 0, 0 };

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		float deltaTime = GetFrameTime();
		
		Vector2 startMovement{};
		
		Matrix turretRotation = MatrixIdentity();

		if (IsKeyDown(KEY_W))
		{
			startMovement.y -= 1;
		}
		if (IsKeyDown(KEY_A))
		{
			startMovement.x -= 1;
			vehicleRotation = MatrixRotateZ((-45 * (PI / 180)) * deltaTime);
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
		if (IsKeyDown(KEY_Q))
		{
			turretRotation = MatrixRotateZ((-45 * (PI / 180)) * deltaTime);

		}
		if (IsKeyDown(KEY_E))
		{
			turretRotation = MatrixRotateZ((45 * (PI / 180)) * deltaTime);

		}
		

		startMovement = Vector2Normalize(startMovement);
		vehicle = MatrixMultiply(
			MatrixTranslate(0, startMovement.y * vehicleSpeed * deltaTime, 0),
			vehicle
		);
		turret = MatrixMultiply(turretRotation, turret);
		Matrix combine = MatrixMultiply(turret, vehicle);

		Vector2 updatedPoints[pointSize]{};
		Vector2 updatedTurret[turretSize]{};
		
		for (int i = 0; i < pointSize; ++i)
		{
			updatedPoints[i] = Vector2Transform(vehiclePoints[i], vehicle);
		}
		for (int i = 0; i < pointSize; ++i)
		{
			updatedTurret[i] = Vector2Transform(turretPoints[i], combine);
		}

		for (int i = 0; i < pointSize; ++i)
		{
			DrawLineEx(
				updatedPoints[i],
				updatedPoints[(i + 1) % pointSize],
				4.f,
				DARKGREEN
			);
		}

		for (int i = 0; i < pointSize; ++i)
		{
			DrawLineEx(
				updatedTurret[i],
				updatedTurret[(i + 1) % pointSize],
				4.f,
				BROWN
			);
		}

		if (IsKeyDown(KEY_SPACE))
		{
			fired = true;
			
			Vector2 turretEnd = { (updatedTurret[0].x + updatedTurret[3].x) / 2, updatedTurret[0].y };
			bulletPos = turretEnd;
			
			
		}
		if (fired == true)
			{
				DrawCircle(
					bulletPos.x,
					bulletPos.y,
					10,
					YELLOW
				);
				bulletMovement = bulletPos;
			}
		EndDrawing();
	}
	
	CloseWindow();
}