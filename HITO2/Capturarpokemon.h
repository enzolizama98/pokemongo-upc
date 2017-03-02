#pragma once
#define maxfilas 100
#define maxcolum 50


using namespace	System::Drawing;

class CCapturarpokemon
{
private:
	int x1, y1, dx1, dy1;//movimiento enemigo
	int x2, y2, dx2, dy2; //pokeball
	int ancho, alto;
	bool lanzarpoke;
	double a2, al2;
	int indx;
	int pokemons;
	bool atrapado;	
public:
	~CCapturarpokemon();
	CCapturarpokemon(Bitmap ^enemigo, Bitmap ^pokeball);
	void dibujarpokemons(BufferedGraphics ^buffer, Bitmap ^enemigo, Bitmap ^pokeball, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	void moverpokemonrival(BufferedGraphics ^buffer, Bitmap ^enemigo, Bitmap ^pokeball, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	bool get_coger_pokeball();
	void set_coger_pokeball(bool value);
	int get_pokemons();
	bool get_atrapado();
	void set_atrapado(bool g);
};

