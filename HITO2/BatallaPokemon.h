#pragma once
enum DIRECCIONESBATALLA { ARRIBA, ABAJO, IZQUIERDA, DERECHA,NINGUNA };
#define maxfilas 100
#define maxcolum 50
#include "ArrBalas.h"

using namespace System::Drawing;

class CBatallaPokemon{
private:
	int x1, y1, dx1, dy1;
	int x2, y2, dx2, dy2;
	int ancho, alto;
	CArrBalas * balas = new CArrBalas();
	bool disparar;
	int numvid1, numvid2;
	bool acabo_la_batalla;
	bool ganaste;
	int bajarvidaamiga;
	int bajarvidaenemiga;
public:
	DIRECCIONESBATALLA DIRECCION;
	CBatallaPokemon(Bitmap^mipokemon , Bitmap ^pokemonrival);
	void dibujarBatalla(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	void moverMiPokemon(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	void moverEnemmigo(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	~CBatallaPokemon();
	bool get_disparar();
	void set_dispara(bool d);
	void mov_final(BufferedGraphics ^buffer, Bitmap ^jugador, Bitmap ^jugador2, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	bool get_acabo_la_batalla();
	bool get_ganaste();
	int get_nv1();
	int get_nv2();
	void set_nv1(int x);
	void set_nv2(int x);
	void set_bajarvidaamiga(int v);
	void set_bajarvidaenemiga(int v);
};

