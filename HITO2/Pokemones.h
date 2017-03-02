#pragma once
using namespace System::Drawing;
class CPokemones
{
private:
	char* nombre = new char[50];
	int salud;
	int fuerza_golpe_basico;
	int fuerza_ataque_especial;
	int tipo;
	int identificador;
	int puntos_cosmicos;
	int caramelos;
public:
	CPokemones(int id, int t, char* n);
	~CPokemones();
	char*	get_nombre();
	int		get_salud();
	void	set_salud(int s);
	int		get_fuerza_golpe_basico();
	void	set_fuerza_golpe_basico(int f);
	int		get_fuerza_ataque_especial();
	void	set_fuerza_ataque_especial(int f);
	int		get_tipo();
	int		get_identificador();
	int		get_puntos_cosmicos();
	void	set_puntos_cosmicos(int pc);
	int		get_caramelos();
	void	set_caramelos(int c);
};

