#include "Player.h"
#include "juego.h"
#include "Fruta.h"
#include <ctime>

using namespace sf;
using namespace std;

void Player::Draw(RenderWindow* wind){//Dibujamos el canasto
	wind->draw(get_cto());
}
