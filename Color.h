#pragma once

enum colors
{
	WHITE, RED, BLUE, GREEN, YELLOW
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
	}

	Color() {
		C[0] = C[1] = C[2] = C[3] = 1.0;
	}

	double* getColorChannels() {
		return C;
	}
};
