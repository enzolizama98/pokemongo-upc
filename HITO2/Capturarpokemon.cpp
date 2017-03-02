#include "Capturarpokemon.h"
#include <cstdlib>
#include <ctime>


CCapturarpokemon::CCapturarpokemon(Bitmap ^enemigo, Bitmap ^pokeball)
{
	srand(time(NULL));
	ancho = alto = 80;
	x1 = 320;
	y1 = 100;
	dx1 = 12;
	dy1 = 12;
	x2 = 320;
	y2 = 500;
	dx2 = 0;
	dy2 = -13;
	a2 = 62.25;
	al2 = 63;
	lanzarpoke = false;
	indx = 0;
}


CCapturarpokemon::~CCapturarpokemon()
{
}

void CCapturarpokemon::dibujarpokemons(BufferedGraphics ^buffer, Bitmap ^enemigo, Bitmap ^pokeball, int filas, int columnas, int matriz[maxfilas][maxcolum]){
	int X = 0;
	int Y = 0;
	Rectangle CD = Rectangle(x1 +  dx1, y1 , ancho , alto);
	buffer->Graphics->DrawRectangle(Pens::Red, CD);
	Rectangle CA = Rectangle(x1 + 1 + dx1, y1 + 12 + dy1, (ancho / 2), (alto / 2));

	Rectangle CD2 = Rectangle(x2 + 1 + dx2, y2 + 12, (ancho / 2), (alto / 2));
	Rectangle CA2 = Rectangle(x2 + dx2, y2+ dy2, ancho , alto );

	buffer->Graphics->DrawRectangle(Pens::Red, CD);
	buffer->Graphics->DrawRectangle(Pens::Red, CA2);
	if (CD.IntersectsWith(CA2)){
		atrapado = true;
	}

	Rectangle porcionAUsar = Rectangle(0, 0, ancho, alto);
	Rectangle redimensionar = Rectangle(x1, y1, ancho*2.5, alto*2.5);
	buffer->Graphics->DrawImage(enemigo, redimensionar, porcionAUsar, GraphicsUnit::Pixel);
	Rectangle porcionAUsarx = Rectangle(ancho*indx, 0, a2, al2);
	Rectangle redimensionarx = Rectangle(x2, y2, a2*1.1, al2*1.1);
	buffer->Graphics->DrawImage(pokeball, redimensionarx, porcionAUsarx, GraphicsUnit::Pixel);
}
int numeroaleatorio;

void CCapturarpokemon::moverpokemonrival(BufferedGraphics ^buffer, Bitmap ^enemigo, Bitmap ^pokeball, int filas, int columnas, int matriz[maxfilas][maxcolum]) {
	//srand(time(NULL));
	//numeroaleatorio = 0 + rand() % 100;
	if (x1 < 0 || x1 + ancho > 600){
		dx1 *= -1;
	}
	x1 += dx1;
	if (lanzarpoke == true){
		y2 += dy2;
		indx++;
		if (indx>8)
			indx = 0;

	}
	if (y2 < 0 ){
		lanzarpoke = false;
		indx = 0;
		x2 = 320;
		y2 = 500;
		Rectangle porcionAUsarx = Rectangle(ancho*indx, 0, a2, al2);
		Rectangle redimensionarx = Rectangle(x2, y2, a2*1.1, al2*1.1);
		buffer->Graphics->DrawImage(pokeball, redimensionarx, porcionAUsarx, GraphicsUnit::Pixel);
	}
	//y1 += dy1;
	dibujarpokemons(buffer, enemigo, pokeball, filas, columnas, matriz);
}



bool CCapturarpokemon::get_coger_pokeball() { return lanzarpoke; }
void CCapturarpokemon::set_coger_pokeball(bool value) { lanzarpoke = value; }
bool CCapturarpokemon::get_atrapado(){ return atrapado; }
void CCapturarpokemon::set_atrapado(bool g){ atrapado = g; }