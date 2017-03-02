#include "ArrPokemones.h"


CArrPokemones::CArrPokemones()
{
}


CArrPokemones::~CArrPokemones()
{
}


void CArrPokemones::agreagar(int id, int t , char* n){
	switch (id){
	case 1:
		t = 1;
		n = "CHARMANDER";
		break;
	case 2:
		t = 2;
		n = "SQUIRTLE";
		break;
	case 3:
		t = 3;
		n = "BULBASUR";
		break;
	case 4:
		t = 4;
		n = "PIKACHU";
		break;
	}
	CPokemones* nuevo = new CPokemones(id,t,n);
	pokemones.push_back(nuevo);
}

vector<CPokemones*> CArrPokemones::get_arreglo() { return pokemones; }

void CArrPokemones::eliminar(int pos){}

void CArrPokemones::restaurar_salud(){
	
	for (vector<CPokemones*>::iterator it = pokemones.begin(); it != pokemones.end(); it++){
		(*it)->set_salud(100);
	}

}

void CArrPokemones::revivir_pokemon(int posicion){}
void CArrPokemones::dar_pocion(int posicion){}