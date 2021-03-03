#ifndef PLAYER_H
#define PLAYER_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Player {//Definimos player

	Texture canasto;
	Sprite _canasto;
	Vector2f posicion;

public:
	Player() {//Cargamos player
		canasto.loadFromFile("canasto.png");
		_canasto.setTexture(canasto);
		_canasto.setScale(0.2f, 0.2f);
		_canasto.setPosition(347.0f, 480.0f);

		posicion.x = 350.0f;
		posicion.y = 480.0f;
	}

	Sprite get_cto() { return _canasto; }//creamos un sprite igual
	Vector2f get_pos() { return posicion; } //retornamos la posicion
	void set_pos(Vector2f position) { posicion = position; _canasto.setPosition(posicion); }//seteamos nueva posicion al canasto

	void Draw(RenderWindow* wind);//Dibujamos player
};
#endif