#include "raylib.h"
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// #define CUSTOM_FONT
#define TEST_MODE

class Data {
public:
	int mph;
	int fbp;
	int rbp;
	int throttle;
	int brake;
	int steer;
	int cvtTemp;
	int engineTemp;
	void init();
	#ifdef TEST_MODE
	void randomize();
	#endif
private:
	vector<int*> datapoints;
} testData;
void updateData();

void text(char* text, Vector2 pos);
void text(char* text, Vector2 pos, int size);

#ifdef CUSTOM_FONT
Font font;
#endif
const int fontSize = 30;
const int spacing = 2;
char* bottomText = "SBU Motorsports";
const int bottomFontSize = 50;

int main(void) {
	SetRandomSeed(0);
	const int screenWidth = 800;
	const int screenHeight = 480;

	InitWindow(screenWidth, screenHeight, "SBU Motorsports");
	SetTargetFPS(60);

	Texture2D texture = LoadTexture("resources/SBMLogo.png");
	#ifdef CUSTOM_FONT
	font = LoadFontEx("resources/font.ttf", fontSize, 0, 250);
	Vector2 bottomSize = MeasureTextEx(font, bottomText, bottomFontSize, spacing);
	#else
	Vector2 bottomSize = (Vector2){ MeasureText(bottomText, bottomFontSize),bottomFontSize };
	#endif

	testData.init();

	#ifdef __arm__
	if (!IsWindowFullscreen()) {
		ToggleFullscreen();
	}
	#endif

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(0, 0);
		DrawTexture(texture, 0, screenHeight - texture.height - bottomSize.y, WHITE);
		text(bottomText, (Vector2) { (screenWidth - bottomSize.x) / 2, screenHeight - bottomSize.y }, bottomFontSize);
		text(bottomText, (Vector2) { 0, 0 });
		EndDrawing();
		updateData();
	}

	UnloadTexture(texture);
	#ifdef CUSTOM_FONT
	UnloadFont(font);
	#endif
	CloseWindow();
	return 0;
}

void updateData() {
	testData;
}

void text(char* inText, Vector2 pos, int size) {
	#ifdef CUSTOM_FONT
	DrawTextEx(font, inText, pos, size, spacing, WHITE);
	#else
	DrawText(inText, pos.x, pos.y, size, WHITE);
	#endif
}

void text(char* inText, Vector2 pos) {
	text(inText, pos, fontSize);
}

void Data::init() {
	datapoints = { &mph, &fbp, &rbp, &throttle, &brake, &steer, &cvtTemp, &engineTemp };
	for (int i = 0; i < datapoints.size(); i++) {
		*datapoints.at(i) = 0;
	}
}

void Data::randomize() {
	for (int i = 0; i < datapoints.size(); i++) {
		*datapoints.at(i) = clamp(*datapoints.at(i) + GetRandomValue(-1, 1), 0, 30);
	}
}