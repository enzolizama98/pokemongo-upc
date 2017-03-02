#include "Bala.h"
#include <cstdlib>
#include <ctime>

CBala::CBala(int tipo, int x , int y)
{
	srand(time(NULL));
	this->tipo = tipo;
	this->x = x;
	this->y = y;
	dx = 8 + rand() % 20;
	dy = 8 + rand() % 20;
	r_lado = 10 + rand() % 15;
}


CBala::~CBala()
{
}


void CBala::dibujar(BufferedGraphics ^buffer){
	switch (tipo)
	{
	case 1:
		buffer->Graphics->FillEllipse(Brushes::Yellow, x, y, r_lado, r_lado);
		y += dy;
		break;
	case 2:
		buffer->Graphics->FillRectangle(Brushes::Red, x, y, r_lado, r_lado);
		y += (dy*-1);
		break;
	}
	
}

int CBala::gety(){ return y; }
int CBala::getx(){ return x; }