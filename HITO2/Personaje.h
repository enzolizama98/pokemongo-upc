#pragma once
#include "ArrPokemones.h"
#include <ctime>
#include <cstdlib>
#define maxcolum 50
#define maxfilas 100

using namespace System::Drawing;
enum Direcciones{ Ninguna, Arriba, Abajo, Izquierda, Derecha };

class CPersonaje
{
private:
	int x;
	int y;
	int dx;
	int dy;
	Direcciones ultima;
	int alto;
	int ancho;
	int indiceX;
	int indiceY;
	bool pasarMapa;
	int ultimo_valor_matriz;
	bool conversar;
	int ncon;
	int num_pociones;
	char* equipo;
	char* pokincial;
	int num_pokebolas;
	int num_revivir;
	int num_monedaspokemon;
	int huevos;
	bool tomar_pokeparada;
	bool centropokemon;
	bool batallar;
	int pokemons;
	bool batallar2;
	bool batallar3;
	bool batallar4;
	bool batallar5;
	bool batallar6;
	bool batallar7;
	int marcapasos = 0;
public:
	CArrPokemones *misPokemones = new CArrPokemones();
	Direcciones direccion;
	CPersonaje(int x, int y);
	~CPersonaje();
	bool get_pasarMapa();
	void setpasarmapa(bool map);
	int get_UVM();
	void dibujar(BufferedGraphics ^buffer, Bitmap ^jugador, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	void mover(BufferedGraphics ^buffer, Bitmap ^jugador, int filas, int columnas, int matriz[maxfilas][maxcolum]);
	void setConversar(bool p);
	bool getConversar();
	int getnumconversa();
	char* get_equipo();
	char* get_pokeinicial();
	void set_equipo(char* e);
	void set_pokeinicial(char*p);
	int get_numpokebolas();
	int get_numpociones();
	void set_numpokebolas(int n);
	void set_numpociones(int n);
	void setPokeparada(bool p);
	bool getPokeparada();
	int get_num_revivir();
	int get_num_monedaspokemon();
	void set_numrevivir(int r);
	void set_nummonedaspokemon(int m);
	void set_centropokemon(bool cp);
	bool get_centropokemon();
	bool getBatallar();
	void setBatallar(bool b);
	int  getPokemons();
	bool getBatallar2();
	void setBatallar2(bool b);
	bool getBatallar3();
	void setBatallar3(bool b);
	bool getBatallar4();
	void setBatallar4(bool b);
	bool getBatallar5();
	void setBatallar5(bool b);
	bool getBatallar6();
	void setBatallar6(bool b);
	bool getBatallar7();
	void setBatallar7(bool b);
	int geth();
	void setH(int v);
	int getmarcapasos();
};

