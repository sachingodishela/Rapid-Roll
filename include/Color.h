#pragma once
#include<iso646.h>
enum colors
{
	WHITE, RED, BLUE, GREEN, YELLOW, BLACK
};

class Color {
private:
	double C[4];
public:
	Color(colors myColor) {
		C[0] = C[1] = C[2] = C[3] = 1.0;
		if (myColor == colors::RED) {
			C[1] = 0.0;
			C[2] = 0.0;
		}
		else if (myColor == colors::BLUE) {
			C[0] = 0;
			C[1] = 0;
		}
		else if (myColor == colors::BLACK) {
			C[0] = 0;
			C[1] = 0;
			C[2] = 0;
		}
	}

	Color() {
		C[0] = C[1] = C[2] = C[3] = 1.0;
	}

	double* getColorChannels() {
		return C;
	}
};
