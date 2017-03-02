#include "Pokemones.h"


CPokemones::CPokemones(int id, int t, char* n){
	salud = 75;
	fuerza_golpe_basico = 10;
	fuerza_ataque_especial = 30;
	puntos_cosmicos = 0;
	caramelos = 2;
	identificador = id;
	tipo = t;
	nombre = n;
}



CPokemones::~CPokemones()
{
}

char*	CPokemones::get_nombre(){ return nombre; }
int		CPokemones::get_salud(){ return salud; }
void	CPokemones::set_salud(int s){ salud = s; }
int		CPokemones::get_fuerza_golpe_basico(){ return fuerza_golpe_basico; }
void	CPokemones::set_fuerza_golpe_basico(int f){ fuerza_golpe_basico = f; }
int		CPokemones::get_fuerza_ataque_especial(){ return fuerza_ataque_especial; }
void	CPokemones::set_fuerza_ataque_especial(int f){ fuerza_ataque_especial = f; }
int		CPokemones::get_tipo(){ return tipo; }
int		CPokemones::get_identificador(){ return identificador; }
int		CPokemones::get_puntos_cosmicos(){ return puntos_cosmicos; }
void	CPokemones::set_puntos_cosmicos(int pc){ puntos_cosmicos = pc; }
int		CPokemones::get_caramelos(){ return caramelos; }
void	CPokemones::set_caramelos(int c){ caramelos = c; }
