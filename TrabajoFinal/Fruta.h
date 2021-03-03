#ifndef FRUTA_H
#define FRUTA_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Fruta {//Definimos fruta

	Texture fruta[5];
	Sprite _fruta[5];
	Vector2f posicionfruta;
	Vector2f aceleracion;
	Vector2f velocidad;
	
public:
	Fruta() {//Cargamos player
		fruta[0].loadFromFile("fruta.png");
		_fruta[0].setTexture(fruta[0]);
		_fruta[0].setScale(0.70f, 0.70f);
		fruta[1].loadFromFile("fruta2.png");
		_fruta[1].setTexture(fruta[1]);
		_fruta[1].setScale(0.70f, 0.70f);
		fruta[2].loadFromFile("fruta3.png");
		_fruta[2].setTexture(fruta[2]);
		_fruta[2].setScale(0.70f, 0.70f);
		fruta[3].loadFromFile("fruta4.png");
		_fruta[3].setTexture(fruta[3]);
		_fruta[3].setScale(0.70f, 0.70f);
		fruta[4].loadFromFile("fruta.png");
		_fruta[4].setTexture(fruta[4]);
		_fruta[4].setScale(0.70f, 0.70f);
		posicionfruta.x = 150.0f;
		posicionfruta.y = 0.0f;
		velocidad.x = 0.0f;
		velocidad.y = 10.0f;
		aceleracion.x = 0.0f;
		aceleracion.y = 8.0f;
	}

	Sprite frutas() { return _fruta[0]; }//retornamos en un sprite aleatorio para el movimiento con teclado

	void Draw(RenderWindow* wind);//Dibujamos las frutas
	void Stop();//Detiene el movimientos de las frutas
	void Reactivar();//Restablece el movimiento las frutas 

	void Update_f(float dt);//Establecemos el movimiento de las frutas
	void Clear();//Elimina la fruta segun los distintos eventos
	void setPosicion(Vector2f pos) { posicionfruta = pos; }
	void setVelocidad(Vector2f vel) { velocidad = vel; }
	void SetAceleracion(Vector2f acc) { aceleracion = acc; }
};
#endif
