#include "raylib.h"

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "SBU Motorsports");
	SetTargetFPS(60);
	while (!WindowShouldClose()){

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Congrats! You created your first window!", 190, 200, 20, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
