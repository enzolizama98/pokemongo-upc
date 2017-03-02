#include "ArrBalas.h"


CArrBalas::CArrBalas()
{
}


CArrBalas::~CArrBalas()
{
}


void CArrBalas::agregar(int tipo, int x, int y){
	CBala * nuevo = new CBala(tipo,x,y);
	balas.push_back(nuevo);
}

void CArrBalas::eliminar(){
	for (int i = 0; i < balas.size(); i++){
		if (balas[i]->gety() > 640){
			balas.erase(balas.begin() + i);
		}
	}
}
void CArrBalas::mover(BufferedGraphics ^buffer){
	for (int i = 0; i < balas.size(); i++){
		balas[i]->dibujar(buffer);
	}
}

void CArrBalas::colisiones(Rectangle r1, Rectangle r2){
	for (int i = 0; i < balas.size(); i++){
		if (balas[i]->getx() > r1.X && balas[i]->getx() < r1.X + r1.Width && balas[i]->gety() > r1.Y && balas[i]->gety() < r1.Y + r1.Width ){
			choqueamigo = true;
		}
		if (balas[i]->getx() > r2.X && balas[i]->getx() < r2.X + r2.Width && balas[i]->gety() > r2.Y && balas[i]->gety() < r2.Y + r2.Width){
			choqueenemigo = true;
		}
	}
}

bool CArrBalas::getCA(){ return choqueamigo; }
bool CArrBalas::getCE(){ return choqueenemigo; }
void CArrBalas::setCA(bool v){ choqueamigo = v; }
void CArrBalas::setCE(bool v){ choqueenemigo = v; }