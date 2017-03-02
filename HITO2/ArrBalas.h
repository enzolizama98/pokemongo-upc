#pragma once
#include <vector>
#include "Bala.h"
using namespace std;
using namespace System::Drawing;

class CArrBalas
{
	vector<CBala*>balas;
	bool choqueamigo;
	bool choqueenemigo;
public:
	void agregar(int tipo, int x, int y);
	void eliminar();
	void colisiones(Rectangle pkm , Rectangle enemigo);
	void mover(BufferedGraphics ^buffer);
	bool getCA();
	bool getCE();
	void setCA(bool v);
	void setCE(bool v);
	CArrBalas();
	~CArrBalas();
};

