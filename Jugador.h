#pragma once
#include "Sprites.h"

class Jugador : public Sprites {
private:
	int vidas;

public:
	Jugador(int ancho, int alto) : Sprites(ancho, alto) {
		x = 388;
		y = 258;
		dx = dy = 3;
		vidas = 1;
	}

	~Jugador() {}

	void dibujarJugador(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.60, alto * 0.60);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void moverJugador(Graphics^ g, char indice) {
		switch (indice) {
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
			} break;

		case 'D':
			if (x + ancho * 0.60 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
			} break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
			} break;
		
		case 'S':
			if (y + alto * 0.60 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
			}break;
		}
		idx += 1;
		if (idx > 3) {
			idx = 0;
		}
	}

	int getVidas() { return vidas; }
	void setVidas(int v) { vidas = v; }
	void restarVidas() { vidas -= 1; }
	void ceroVidas() { vidas = 0; }
};