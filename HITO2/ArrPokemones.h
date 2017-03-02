#pragma once
#include "Pokemones.h"
#include <vector>
#include <string>

using namespace std;

class CArrPokemones
{
	vector<CPokemones*> pokemones;
public:
	void agreagar(int id, int t, char* n);
	void eliminar(int pos);
	void restaurar_salud();
	void revivir_pokemon(int posicion);
	void dar_pocion(int posicion);
	vector<CPokemones*> get_arreglo();
	CArrPokemones();
	~CArrPokemones();
};

