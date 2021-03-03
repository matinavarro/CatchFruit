#ifndef JUEGO_H
#define JUEGO_H
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Fruta.h"
#include <iostream>
#include <ctime>
using namespace sf;
using namespace std;

class Juego{
public:

	//métodos
	Juego();
	~Juego();
	void Loop();

private:
	//métodos
	void _Draw();//Dibujamos elementos distintos elementos del juego
	void _Update(float dt);//Controlamos las funciones del player y las frutas
	void _ProcessEvents();//procesamos los distintos eventos que ocurren 
	void JuntaFruta();//Procesamiento para la recoleccion de frutas
	void MostrarPuntaje();//Se muestra el puntaje en pantalla
	void Restart();//Funcionamiento del boton para reiniciar la partida
	int Puntaje();//Se determina el ganador o perdedor 
	//variables
	RenderWindow* wind;
	Player* player;
	Fruta* fruta;
	Texture fondo;
	Sprite _fondo;
	Texture fondo2;
	Sprite _fondo2;
	Texture info[5];
	Sprite _info[5];
	Text puntos;
	Font fuente;
	SoundBuffer buffer[3];
	Sound efecto[3];//establecemos efectos para los sucesos
	Music musica;//establecemos musica para el juego
	Clock tiempo;
	Time _tiempo;
	int puntaje=0;
	int puntajeloser=0;
};
#endif 
