#include "Juego.h"
#include "Fruta.h"
#include "Player.h"
#include <ctime>

using namespace sf;
using namespace std;

Juego::Juego(){
	wind = new RenderWindow(VideoMode(800, 600), "Catch Fruit");
	player = new Player;
	fruta = new Fruta;
	fondo.loadFromFile("Paisaje.jpg");
	_fondo.setTexture(fondo);
	_fondo.setScale(1.0f, 1.0f);
	fondo2.loadFromFile("arbusto.png");
	_fondo2.setTexture(fondo2);
	_fondo2.setScale(1.0f, 1.0f);
	info[0].loadFromFile("info.png");
	_info[0].setTexture(info[0]);
	_info[0].setScale(1.0f, 1.0f);
	_info[0].setPosition(10.0f, 555.0f);
	info[1].loadFromFile("ganaste.png");
	_info[1].setTexture(info[1]);
	_info[1].setScale(1.0f, 1.0f);
	_info[1].setPosition(200.0f, 75.0f);
	info[2].loadFromFile("perdiste.png");
	_info[2].setTexture(info[2]);
	_info[2].setScale(1.0f, 1.0f);
	_info[2].setPosition(200.0f, 75.0f);
	info[3].loadFromFile("restart.png");
	_info[3].setTexture(info[3]);
	_info[3].setScale(0.05f, 0.05f);
	_info[3].setPosition(384.0f, 420.0f);
	info[4].loadFromFile("presentacion.jpg");
	_info[4].setTexture(info[4]);
	_info[4].setScale(1.0f, 1.0f);
	puntos.setPosition(748, 565);
	puntos.setCharacterSize(23);
	puntos.setFont(fuente);
	fuente.loadFromFile("Adventure.otf");
	buffer[0].loadFromFile("atrapafruta.wav");
	efecto[0].setBuffer(buffer[0]);
	buffer[1].loadFromFile("restart.wav");
	efecto[1].setBuffer(buffer[1]);
	buffer[2].loadFromFile("golpeasuelo.wav");
	efecto[2].setBuffer(buffer[2]);
	musica.openFromFile("musica.ogg");
	musica.setVolume(20);
}

Juego::~Juego(){
	delete wind;
	delete player;
	delete fruta;
}

void Juego::Loop() {
	Clock clock;
	clock.restart();
	float dt;
	musica.play();

	while (wind->isOpen()) {
		float dt = clock.restart().asSeconds();
		wind->setFramerateLimit(60);//controlamos los frames del juego;
		_ProcessEvents();
		_Update(dt);
		_Draw();
	}
}

int Juego::Puntaje(){
	int num = 0;
	if (puntaje == 20) {
		wind->draw(_info[1]);
		wind->draw(_info[3]);
		fruta->Stop();
			return 1;
	}
	if (puntajeloser == 10) {
		wind->draw(_info[2]);
		wind->draw(_info[3]);
		fruta->Stop();
		return 0;
	}
}

void Juego::_Draw(){
	wind->clear();
	wind->draw(_fondo);
	fruta->Draw(wind);
	wind->draw(_fondo2);
	player->Draw(wind);
	wind->draw(_info[0]);
	Puntaje();
	wind->draw(puntos);
	_tiempo = tiempo.getElapsedTime();//colocamos pantalla de inicio por un lapso de tiempo
	if (_tiempo.asSeconds() < 4) {
		wind->draw(_info[4]);
	}
	wind->display();
}

void Juego::Restart(){
	puntaje = 0;
	puntajeloser = 0;
	fruta->Reactivar();
	musica.play();
}

void Juego::MostrarPuntaje(){
	String Puntaje;
	Puntaje = to_string(puntaje);
	puntos.setString(Puntaje);
}

void Juego::JuntaFruta(){
	int num = 0;
	if (fruta->frutas().getGlobalBounds().intersects(player->get_cto().getGlobalBounds())) {
		fruta->Clear();
		while (num !=1) {
			num = 1;
			puntaje++;
			efecto[0].play();
		}
	}
	else {
		if (fruta->frutas().getGlobalBounds().intersects(_info[0].getGlobalBounds())) {
			fruta->Clear();
			while (num != 1) {
				num = 1;
				puntajeloser++;
				efecto[2].play();
			}
		}
	}
	
}

void Juego::_Update(float dt){
	fruta->Update_f(dt);
	JuntaFruta(); 
	MostrarPuntaje();
}

void Juego::_ProcessEvents(){
	Event evt;
	while (wind->pollEvent(evt)) {
		switch (evt.type) {//Proceso los eventos
		case Event::Closed://Controlo si se cerró la ventana
			wind->close();//cierro aplicacion
			break;
		case Event::KeyPressed://Movimientos Player
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player->set_pos(Vector2f(player->get_pos().x - 20, player->get_pos().y));

			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player->set_pos(Vector2f(player->get_pos().x + 20, player->get_pos().y));
			}
			break;
		case Event::MouseButtonPressed://Si presiono el boton izquiero del mouse y colisiona con el boton, reseteo juego.
			if (evt.mouseButton.button == Mouse::Button::Left) {
				Vector2i mousepos = Mouse::getPosition(*wind);
				if (_info[3].getGlobalBounds().contains(mousepos.x, mousepos.y)) {
					efecto[1].play();
					Restart();
				}
			}
			break;
		}
	}
}
