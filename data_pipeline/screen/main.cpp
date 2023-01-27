#include "raylib.h"

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "SBU Motorsports");
	SetTargetFPS(60);
	Texture2D texture = LoadTexture("resources/SBMLogo.png");
	Font fontTtf = LoadFontEx("resources/font.ttf", 32, 0, 250);

	#ifdef __arm__
	if (!IsWindowFullscreen()){
		ToggleFullscreen();
	}
	#endif

	while (!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextEx(fontTtf, "hello12345", (Vector2){0.0f,0.0f}, 30.0f, 2, WHITE);
		DrawTexture(texture, 0, screenHeight - texture.height, WHITE);
		EndDrawing();
	}

	UnloadTexture(texture);
	UnloadFont(fontTtf);
	CloseWindow();
	return 0;
}
