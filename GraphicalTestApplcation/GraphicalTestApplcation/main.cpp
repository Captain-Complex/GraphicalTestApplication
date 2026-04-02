#include <raylib.h>
#include <raymath.h>

#include <cmath>
#include <iostream>
#include<string>

#include "Game.h"
#include "SceneObject.h"
//here is my vector and matrix but i tried adding them which all worked well until it was time to draw so i went back to raylibs variables
#include "MyVector.hpp"
#include "MyMatrix.hpp"

//mainually adding my version of the raylib function to prove i can do basic collision
bool IsCircleCollision(Vector2 centre1, float radius1, Vector2 centre2, float radius2)
{
	float radTotal = radius1 + radius2;
	float distance = sqrtf((centre2.x - centre1.x) * (centre2.x - centre1.x) +
		(centre2.y - centre1.y) * (centre2.y - centre1.y));
	if (distance <= radTotal)
	{
		return true;
	}
	return false;
}

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
	vehicle = vehicleRotation *vehicleTranslation;

	Matrix turret = MatrixIdentity();
	Matrix turretTranslation = MatrixIdentity();

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

	bool collision = false;
	bool collision2 = false;
	bool collision3 = false;
	bool collision4 = false;
	bool collision5 = false;
	bool collision6 = false;
	bool collision7 = false;
	bool collision8 = false;

	float vehicleSpeed = 180.f;

	const int pointSize = sizeof(vehiclePoints) / sizeof(vehiclePoints[0]);
	const int turretSize = sizeof(turretPoints) / sizeof(turretPoints[0]);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		float deltaTime = GetFrameTime();

		collision = IsCircleCollision(bulletPos, 10, { screenWidth / 4, screenHeight / 2}, 15);
		collision2 = IsCircleCollision(bulletPos, 10, { (screenWidth / 4) * 3, screenHeight / 2 }, 20);
		collision3 = IsCircleCollision(bulletPos, 10, { screenWidth / 2, screenHeight / 4 }, 25);
		collision4 = IsCircleCollision(bulletPos, 10, { screenWidth / 2, (screenHeight / 4) * 3 }, 5);
		collision5 = IsCircleCollision(bulletPos, 10, { screenWidth / 4, screenHeight / 4 }, 10);
		collision6 = IsCircleCollision(bulletPos, 10, { (screenWidth / 4) * 3, screenHeight / 4 }, 30);
		collision7 = IsCircleCollision(bulletPos, 10, { screenWidth / 4, (screenHeight / 4) * 3 }, 35);
		collision8 = IsCircleCollision(bulletPos, 10, { (screenWidth / 4) * 3, (screenHeight / 4) * 3 }, 40);


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
			vehicle = vehicleRotation * vehicle;
		}
		if (IsKeyDown(KEY_S))
		{
			startMovement.y += 1;
		}
		if (IsKeyDown(KEY_D))
		{
			startMovement.x += 1;
			vehicleRotation = MatrixRotateZ((45 * (PI / 180)) * deltaTime);
			vehicle = (vehicleRotation) * vehicle;
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
			vehicle);
		turret = turretRotation * turret;
		Matrix combine = turret * vehicle;

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
				DARKBROWN
			);
		}

		DrawCircle(screenWidth / 4, screenHeight / 2, 15, VIOLET);
		DrawCircle((screenWidth / 4) * 3, screenHeight / 2, 20, MAROON);
		DrawCircle(screenWidth / 2, screenHeight / 4, 25, PINK);
		DrawCircle(screenWidth / 2, (screenHeight / 4) * 3, 5, BEIGE);
		DrawCircle(screenWidth / 4, screenHeight / 4, 10, BLUE);
		DrawCircle((screenWidth / 4) * 3, screenHeight / 4, 30, BLACK);
		DrawCircle(screenWidth / 4, (screenHeight / 4) * 3, 35, RED);
		DrawCircle((screenWidth / 4) * 3, (screenHeight / 4) * 3, 40, WHITE);

		if (IsKeyDown(KEY_SPACE))
		{
			fired = true;
			
			Vector2 turretEnd = { (updatedTurret[0].x + updatedTurret[3].x) / 2, updatedTurret[0].y };
			bulletPos = turretEnd;
			bulletMovement = Vector2Subtract(bulletPos, (updatedTurret[1] + updatedTurret[2]) / 2);
			bulletMovement = Vector2Normalize(bulletMovement);
			
		}
		if (fired == true)
			{
			bulletPos.y += bulletMovement.y * 900 * deltaTime;
			bulletPos.x += bulletMovement.x * 900 * deltaTime;

				DrawCircle(
					bulletPos.x,
					bulletPos.y,
					10,
					YELLOW
				);
				if (collision)
				{
					fired = false;
				}
				if (collision2)
				{
					fired = false;
				}
				if (collision3)
				{
					fired = false;
				}
				if (collision4)
				{
					fired = false;
				}
				if (collision5)
				{
					fired = false;
				}
				if (collision6)
				{
					fired = false;
				}
				if (collision7)
				{
					fired = false;
				}
				if (collision8)
				{
					fired = false;
				}
			}
		EndDrawing();
	}
	
	CloseWindow();
}