#pragma once
using namespace System::Drawing;
class CBala
{
	int x;
	int y;
	int dx;
	int dy;
	int tipo;
	int r_lado;
public:
	CBala(int tipo, int x, int y);
	void dibujar(BufferedGraphics ^buffer);
	int gety();
	int getx();
	~CBala();
};

