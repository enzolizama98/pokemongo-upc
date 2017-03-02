#include "BatallaPokemon.h"
#include <cstdlib>
#include <ctime>

CBatallaPokemon::CBatallaPokemon(Bitmap ^ j1 , Bitmap ^j2){
	srand(time(NULL));
	ancho = alto = 80;
	x1 = 320;
	y1 = 500;
	x2 = 320;
	y2 = 100;
	dx1 = 0;
	dy1 = 0;
	dx2 = 12;
	dy2 = 12;
	disparar = false;
	numvid1 = 75;
	numvid2 = 75;
	ganaste = false;
	acabo_la_batalla = false;
	bajarvidaamiga = 2;
	bajarvidaenemiga = 2;
}


CBatallaPokemon::~CBatallaPokemon()
{
}


void CBatallaPokemon::dibujarBatalla(BufferedGraphics ^buffer, Bitmap ^mipkmn, Bitmap ^pkmnrival, int filas, int columnas, int matriz[maxfilas][maxcolum]){

	int X = 0;
	int Y = 0;
	
	
	Rectangle CA = Rectangle(x1 + 1 + dx1, y1 + 12 + dy1, (ancho / 2), (alto / 2));

	Rectangle CD2 = Rectangle(x2 + 1 + dx2, y2 + 12, (ancho / 2), (alto / 2));


	Rectangle CD = Rectangle(x1 + 12, y1 + 10, (ancho / 1.2), (alto / 1.2));
	Rectangle CA2 = Rectangle(x2 + 12, y2 + 10, (ancho / 1.2), (alto / 1.2));

	buffer->Graphics->DrawRectangle(Pens::Blue, CD);
	buffer->Graphics->DrawRectangle(Pens::Pink, CA2);


	for (int i = 0; i < filas; i++){
		X = 0;
		for (int j = 0; j < columnas; j++){
			Rectangle CuadradoJ = Rectangle(X, Y, 32, 32);
			if (matriz[i][j] == 0) {

				//buffer->Graphics->FillRectangle(Brushes::Orange, X, Y, 32, 32);

				}
			if (matriz[i][j] == 1){

				//buffer->Graphics->FillRectangle(Brushes::Green, X, Y, 32, 32);
				if (CD.IntersectsWith(CuadradoJ)){ dx1 = 0; }
				if (CA.IntersectsWith(CuadradoJ)) { dy1 = 0; }

				}

			X += 32;
		}
		Y += 32;
	}
	Rectangle porcionAUsar = Rectangle(0, 0, ancho, alto);
	Rectangle redimensionar = Rectangle(x1, y1, ancho*1.1, alto*1.1);
	buffer->Graphics->DrawImage(mipkmn, redimensionar, porcionAUsar, GraphicsUnit::Pixel);
	Rectangle porcionAUsarx = Rectangle(0, 0, ancho, alto);
	Rectangle redimensionarx = Rectangle(x2, y2, ancho*1.1, alto*1.1);
	buffer->Graphics->DrawImage(pkmnrival, redimensionarx, porcionAUsarx, GraphicsUnit::Pixel);
	
	
}


void CBatallaPokemon::moverMiPokemon(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]){

	Rectangle CD = Rectangle(x1 + 12, y1 + 10, (ancho / 1.2), (alto / 1.2));
	Rectangle CA2 = Rectangle(x2 + 12, y2 + 10, (ancho / 1.2), (alto / 1.2));

	switch (DIRECCION){
	case DIRECCIONESBATALLA::ABAJO:

		dx1 = 0;
		dy1 = 10;
		break;
	case DIRECCIONESBATALLA::ARRIBA:

		dx1 = 0;
		dy1 = -10;
		break;
	case DIRECCIONESBATALLA::DERECHA:

		dx1 = 10;
		dy1 = 0;
		break;
	case DIRECCIONESBATALLA::IZQUIERDA:

		dx1 = -10;
		dy1 = 0;
		break;
	case DIRECCIONESBATALLA::NINGUNA:
		dx1 = dy1 = 0;
	}


	if (disparar==true){
		balas->agregar(2, x1+(ancho/2), y1);
		disparar = false;
	}

	balas->eliminar();
	balas->mover(buffer);
	balas->colisiones(CD, CA2);

	if (balas->getCA() == true){
		numvid1-=bajarvidaamiga;
		balas->setCA(false);
	}
	if (balas->getCE() == true){
		numvid2-=bajarvidaenemiga;
		balas->setCE(false);
	}
	/*
	if (numvid1 == 0 || numvid2 == 0){
		acabo_la_batalla = true;

		if (numvid1 > 0) ganaste = true;
		else ganaste = false;
	}*/

	x1 += dx1;
	y1 += dy1;

	dibujarBatalla(buffer, jugador,jugador2, filas, columnas, matriz);

}

int numeroalea;

void CBatallaPokemon::moverEnemmigo(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]){
	Rectangle CD = Rectangle(x1 + 12, y1 + 10, (ancho / 1.2), (alto / 1.2));
	Rectangle CA2 = Rectangle(x2 + 12, y2 + 10, (ancho / 1.2), (alto / 1.2));
	
	srand(time(NULL));
	numeroalea = 0 + rand() % 100;
	if (x2 < 0 || x2 + ancho > buffer->Graphics->VisibleClipBounds.Width)
		dx2 *= -1;
	if (y2 + alto >( buffer->Graphics->VisibleClipBounds.Height) / 2 || y2 < 0)
		dy2 *= -1;

	if (numeroalea % 3 == 0){
		balas->agregar(1,x2+(ancho/2),y2+alto);
	}
	balas->eliminar();
	balas->mover(buffer);

	/*balas->colisiones(CD, CA2);

	if (balas->getCE() == true){
		numvid2--;
		balas->setCE(false);
	}*/

	x2 += dx2;
	y2 += dy2;
	dibujarBatalla(buffer, jugador, jugador2, filas, columnas, matriz);

}


bool CBatallaPokemon::get_disparar(){ return disparar; }
void CBatallaPokemon::set_dispara(bool d){ disparar = d; }
void CBatallaPokemon::mov_final(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]){
	moverEnemmigo(buffer,jugador,jugador2,20,20,matriz);
	moverMiPokemon(buffer, jugador, jugador2, 20, 20, matriz);
}

bool CBatallaPokemon::get_acabo_la_batalla(){ return acabo_la_batalla; }
bool CBatallaPokemon::get_ganaste(){ return ganaste; }


int		CBatallaPokemon::get_nv1(){ return numvid1; }
int		CBatallaPokemon::get_nv2(){ return numvid2; }
void	CBatallaPokemon::set_nv1(int x){ numvid1 = x; }
void	CBatallaPokemon::set_nv2(int x){ numvid2 = x; }

void CBatallaPokemon::set_bajarvidaamiga(int v){ bajarvidaamiga = v; }
void CBatallaPokemon::set_bajarvidaenemiga(int v){ bajarvidaenemiga = v; }