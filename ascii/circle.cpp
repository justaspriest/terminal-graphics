#include <iostream>
#include <utility>
#include <cmath>

#define DEFAULT_WIDTH 32;
#define DEFAULT_HEIGHT 32;
#define DEFAULT_PIXEL_CHAR '@';

std::pair<int, int> getScreenSize(int argc, char* argv[]) {
	int width = 32;
	int height = 32;

	if (argc > 2) {
		width = std::atoi(argv[1]);
		height = std::atoi(argv[2]);
	}

	if (width == 0) {
		width = DEFAULT_WIDTH;
	}

	if (height == 0) {
		height = DEFAULT_HEIGHT;
	}

	return std::make_pair(width, height); 
}

std::pair<float, float> getPoint(int i, int j, std::pair<int, int> size) {
	int width = size.first;
	int height = size.second;

	float x = 2.0f * (float) i / width - 1.0f;
	float y = 2.0f * (float) j / height - 1.0f;

	return std::make_pair(x, y);
}

char* renderCircle(std::pair<int, int> screenSize) {
	int width = screenSize.first;
	int height = screenSize.second;

	// Получаем отношение ширины к высоте - необходимо для масштабирования координат, чтобы придать координатной плоскости соотношение 1:1
	float aspect = (float) width / height;

	// Учитываем соотношение сторон символа (высота больше ширины)
	float pixelAspect = ;

	// Размер экрана больше на один символ - индикатор конца экрана \0 
	char* screen = new char[width * height + 1];
	screen[width * height] = '\0';

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::pair<float, float> point = getPoint(i, j, screenSize);
			float x = point.first * aspect;
			float y = point.second;

			char pixelChar = ' ';

			bool isPointInsideCircle = x * x + y * y < 0.5;
			if (isPointInsideCircle) {
				pixelChar = DEFAULT_PIXEL_CHAR;
			}

			screen[i + j * width] = pixelChar;
		}
	}

	return screen;
}

int main(int argc, char* argv[]) {
	std::pair<int, int> screenSize = getScreenSize(argc, argv);
	char* circle = renderCircle(screenSize);

	printf(circle);

	return 0;
}

