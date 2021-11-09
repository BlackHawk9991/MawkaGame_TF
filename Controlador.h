#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include <vector>

using namespace std;

class Controlador {
private:
	Jugador* jugador;
	vector<Enemigo*> enemigos;
public:
	Controlador(Bitmap^ bmpJugador, Bitmap^ bmpEnemigo) {
		jugador = new Jugador(bmpJugador->Width / 4, bmpJugador->Height / 4);
		enemigos.push_back(new Enemigo(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 2));
	}

	~Controlador() {}

	void dibujarTodo(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo) {
		jugador->dibujarJugador(g, bmpJugador);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->dibujarEnemigo(g, bmpEnemigo);
		}
	}

	void moverTodo(Graphics^ g) {
		
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->moverEnemigo(g);
		}
	}

	void colision() {
		//Verificar
		for (int i = 0; i < enemigos.size(); i++) {
			if (jugador->getRectangle().IntersectsWith(enemigos[i]->getRectangle())) {
				jugador->restarVidas();
				enemigos[i]->setVisible(false);
			}
		}
		//Eliminar
		for (int i = 0; i < enemigos.size(); i++) {
			if (!enemigos[i]->getVisible()) {
				enemigos.erase(enemigos.begin() + i);
			}
		}
	}

	Jugador* getJugador() { return jugador; }
};