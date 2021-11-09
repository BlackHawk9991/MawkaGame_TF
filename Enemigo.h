#pragma once
#include "Sprites.h"

class Enemigo : public Sprites {
private:
	int tipo;
public:
	Enemigo(int ancho, int alto, int tipo) : Sprites(ancho, alto) {
		this->tipo = tipo;
		x = rand() % 60 * 10;
		y = rand() % 30 * 10;
		dx = dy = 8;
	}

	~Enemigo() {}

	void dibujarEnemigo(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.60, alto * 0.60);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}


	void moverEnemigo(Graphics^ g) {
		switch (tipo) {
		case 1:
			if (x + ancho * 0.60 > g->VisibleClipBounds.Width || x < 0) {
				dx *= -1;
			}
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx; break;
		case 2:
			if (y + alto * 0.60 > g->VisibleClipBounds.Height || y < 0) {
				dy *= -1;
			}
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 3;
			}
			y += dy; break;
		}
		idx++;
		if (idx > 3) {
			idx = 0;
		}
	}
};