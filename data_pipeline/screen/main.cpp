#include "raylib.h"

void updateData();

int main(void) {
	const int screenWidth = 800;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "SBU Motorsports");
	SetTargetFPS(60);
	Texture2D texture = LoadTexture("resources/SBMLogo.png");
	const int fontSize = 50;
	Font font = LoadFontEx("resources/font.ttf", fontSize, 0, 250);
	const int spacing = 2;
	const char* bottomText = "SBU Motorsports";
	Vector2 bottomSize = MeasureTextEx(font, bottomText, fontSize, spacing);

	#ifdef __arm__
	if (!IsWindowFullscreen()) {
		ToggleFullscreen();
	}
	#endif

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(texture, 0, screenHeight - texture.height - bottomSize.y, WHITE);
		DrawTextEx(font, bottomText, (Vector2) { (screenWidth - bottomSize.x) / 2, screenHeight - bottomSize.y }, fontSize, spacing, WHITE);
		EndDrawing();
	}

	UnloadTexture(texture);
	UnloadFont(font);
	CloseWindow();
	return 0;
}

void updateData(){
	
}