#include "Fruta.h"
#include "Player.h"
#include "juego.h"
#include <ctime>

using namespace sf;
using namespace std;

void Fruta::Draw(RenderWindow* wind) {//Dibujamos el canasto
	wind->draw(_fruta[0]);
}

void Fruta::Reactivar() {
	velocidad.y = 10.0f;
	aceleracion.y = 8.0f;
}

void Fruta::Stop() {
	velocidad.y = 0.0f;
	aceleracion.y = 0.0f;
}

void Fruta::Update_f(float dt) {
	velocidad.y += aceleracion.y * dt;
	posicionfruta.y += velocidad.y * dt;
	_fruta[0].setPosition(posicionfruta);

	int numrandom;
	numrandom = rand() % 5;
	if (_fruta[0].getPosition().y >= 600.0f) {
		switch (numrandom) {
		case 0: {
			posicionfruta.x = 100.0f;
			posicionfruta.y = 0.0f;
			_fruta[0] = _fruta[rand() % 5];

			break;
		}
		case 1: {
			posicionfruta.x = 300.0f;
			posicionfruta.y = 0.0f;
			_fruta[0] = _fruta[rand() % 5];

			break;
		}
		case 2: {
			posicionfruta.x = 500.0f;
			posicionfruta.y = 0.0f;
			_fruta[0] = _fruta[rand() % 5];

			break;
		}
		case 3: {
			posicionfruta.x = 650.0f;
			posicionfruta.y = 0.0f;
			_fruta[0] = _fruta[rand() % 5];

			break;
		}
		case 4: {
			posicionfruta.x = 700.0f;
			posicionfruta.y = 0.0f;
			_fruta[0] = _fruta[rand() % 5];
			break;
		}
		default:break;
		}
	}
}

void Fruta::Clear() {
	posicionfruta.y = 1000.0f;
	posicionfruta.x = 1000.0f;
}
