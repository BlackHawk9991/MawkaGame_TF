#pragma once
#include <iostream>

using namespace	System::Drawing;

class Sprites {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	bool visible;

public:
	Sprites(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		visible = true;
	}

	~Sprites() {}

	int getX() { return x; }
	int getY() { return y; }
	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.6, alto * 0.6);
	}
};