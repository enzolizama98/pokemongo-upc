#include "Personaje.h"



using namespace System::Media;

CPersonaje::CPersonaje(int x, int y){
	this->x = x;
	this->y = y;
	dx = dy = 0;
	ultima = Direcciones::Abajo;
	ancho = alto = 64;
	indiceX = indiceY = 0;
	direccion = Direcciones::Ninguna;
	ultimo_valor_matriz = 0;
	conversar = false;
	num_pociones = 3;
	num_pokebolas = 3;
	num_monedaspokemon = 100;
	num_revivir = 1;
	huevos = 0;
}


CPersonaje::~CPersonaje()
{
}


bool CPersonaje::get_pasarMapa(){ return pasarMapa; }

int a = 9 , b = 9 ;

void CPersonaje::dibujar(BufferedGraphics ^buffer, Bitmap ^jugador, int filas, int columnas, int matriz[maxfilas][maxcolum]){
	Bitmap ^coin = gcnew Bitmap("coin.png");
	srand(time(NULL));
	int X = 0;
	int Y = 0;
	
	Rectangle CD = Rectangle(x + 1 + dx, y + 12, (ancho / 2), (alto / 2));
	buffer->Graphics->DrawRectangle(Pens::Red, CD);
	Rectangle CA = Rectangle(x + 1 + dx, y + 12 + dy, (ancho / 2), (alto / 2));
	buffer->Graphics->DrawRectangle(Pens::Yellow, CA);
	for (int i = 0; i < filas; i++){
		X = 0;
		for (int j = 0; j < columnas; j++){
			Rectangle CuadradoJ = Rectangle(X, Y, 14, 14);
			if (matriz[i][j] == 0) {

				/*buffer->Graphics->FillRectangle(Brushes::Orange, X, Y, 10, 10);*/

			}
			if (matriz[i][j] == 1){

				/*buffer->Graphics->FillRectangle(Brushes::Green, X, Y, 10, 10);*/
				if (CD.IntersectsWith(CuadradoJ)){ dx = 0; }
				if (CA.IntersectsWith(CuadradoJ)) { dy = 0; }
			}

			if (matriz[i][j] == 2 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){
				
				
				ultimo_valor_matriz = 2;
				buffer->Graphics->FillRectangle(Brushes::RoyalBlue, X, Y, 32, 32);
				
				x = 220;
				y = 200;


			}
			if (matriz[i][j] == 3 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Orange, X, Y, 32, 32);
				
				ultimo_valor_matriz = 3;
				x = 320;
				y = 500;
			}

			if (matriz[i][j] == 4 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Pink, X, Y, 32, 32);
				
				ultimo_valor_matriz = 4;
				x = 200;
				y = 200;
			}

			if (matriz[i][j] == 5 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Purple, X, Y, 32, 32);
				
				ultimo_valor_matriz = 5;
				x = 500;
				y = 180;
			}

			if (matriz[i][j] == 6 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Yellow, X, Y, 32, 32);

				dx = dy = 0;
			
				
			}

			if (matriz[i][j] == 8 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				//POKEPARADA//
				buffer->Graphics->FillRectangle(Brushes::Red, X, Y, 32, 32);
				//dx = dy = 0;
				tomar_pokeparada = true;

			}

			if (matriz[i][j] == 9 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::LightBlue, X, Y, 32, 32);

				dx = dy = 0;
				conversar = true;
				ncon = 1;

				
			}

			if (matriz[i][j] == 10 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Yellow, X, Y, 32, 32);
				centropokemon = true;
				dx = dy = 0;


			}

			if (matriz[i][j] == 11 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar = true;

			}
			if (matriz[i][j] == 12 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){
				ultimo_valor_matriz = 6;
				//buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				
				x = 320;
				y = 200;
			}

			if (matriz[i][j] == 70 ){
				buffer->Graphics->DrawImage(coin,32*(X),32*(Y));
				buffer->Graphics->FillRectangle(Brushes::Yellow, X, Y, 32, 32);
			}

			if (matriz[i][j] == 70 && CD.IntersectsWith(CuadradoJ)){
				//buffer->Graphics->DrawImage(coin, 32 * i, 32 * j);
				matriz[a][b] = 0;
				num_monedaspokemon += 10;
				
					a = 2 + rand() % 19;
					b = 2 + rand() % 18;
		
				matriz[a][b] = 70;
			}

			

			if (matriz[i][j] == 15 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){
				SoundPlayer ^musica4 = gcnew SoundPlayer("C:liga.wav");
				ultimo_valor_matriz = 15;
				buffer->Graphics->FillRectangle(Brushes::AliceBlue, X, Y, 32, 32);
				dx = dy = 0;
				musica4->Play();
			}
			if (matriz[i][j] == 21 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar2 = true;

			}
			if (matriz[i][j] == 22 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar3 = true;

			}
			if (matriz[i][j] == 23 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar4 = true;

			}
			if (matriz[i][j] == 24 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar5 = true;

			}
			if (matriz[i][j] == 25 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;
				batallar6 = true;

			}
			if (matriz[i][j] == 26 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){

				buffer->Graphics->FillRectangle(Brushes::Aquamarine, X, Y, 32, 32);
				dx = dy = 0;
				batallar7 = true;

			}
			if (matriz[i][j] == 31 && CD.IntersectsWith(CuadradoJ) && CA.IntersectsWith(CuadradoJ)){
				ultimo_valor_matriz = 16;
				//buffer->Graphics->FillRectangle(Brushes::White, X, Y, 32, 32);
				dx = dy = 0;

			}

			X += 32;
		}
		Y += 32;
	}
	Rectangle porcionAUsar = Rectangle(ancho*indiceX, alto*indiceY, ancho, alto);
	Rectangle redimensionar = Rectangle(x, y, ancho / 1.5, alto / 1.5);
	buffer->Graphics->DrawImage(jugador, redimensionar, porcionAUsar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;

}


//ULTIMO VALOR MATRIZ SEGUN LAS COLISIONES PARA CAMBIAR DE MAPA : 2,3,4,5,6,7,8,... 
//POKEBOLA DAR UN BOOLEANO DE POKEBOLA TOMADA Y SI ES TRUE DIBUJAR GRASS
//EN CASO CONTRARIO HACER MUCHOS MAPAS


void CPersonaje::mover(BufferedGraphics ^buffer, Bitmap ^jugador, int filas, int columnas, int matriz[maxfilas][maxcolum]){

	switch (direccion){
	case Direcciones::Abajo:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 4){
			indiceX++;
			if (indiceX>3)
				indiceX = 0;
		}
		marcapasos++;
		dx = 0;
		dy = 10;
		ultima = Abajo;
		break;
	case Direcciones::Arriba:
		indiceY = 3;
		if (indiceX >= 0 && indiceX < 4){
			indiceX++;
			if (indiceX>3)
				indiceX = 0;
		}
		marcapasos++;
		dx = 0;
		dy = -10;
		ultima = Arriba;
		break;
	case Direcciones::Derecha:
		indiceY = 2;
		if (indiceX >= 0 && indiceX < 4){
			indiceX++;
			if (indiceX>3)
				indiceX = 0;
		}
		marcapasos++;
		dx = 10;
		dy = 0;
		ultima = Derecha;
		break;
	case Direcciones::Izquierda:

		indiceY = 1;
		if (indiceX >= 0 && indiceX < 4){
			indiceX++;
			if (indiceX>3)
				indiceX = 0;
		}
		marcapasos++;
		dx = -10;
		dy = 0;
		ultima = Izquierda;
		break;
	case Direcciones::Ninguna:
		dx = dy = 0;
		switch (ultima) //LAST CHANGE
		{
		case Direcciones::Abajo:
			indiceX = 0;
			indiceY = 0;
			break;
		case Direcciones::Arriba:
			indiceX = 0;
			indiceY = 3;
			break;
		case Direcciones::Izquierda:
			indiceX = 0;
			indiceY = 1;
			break;
		case Direcciones::Derecha:
			indiceX = 0;
			indiceY = 2;
			break;
		}
	}

	dibujar(buffer, jugador, filas, columnas, matriz);


}

int CPersonaje::get_UVM(){ return ultimo_valor_matriz; }

void CPersonaje::setConversar(bool p){ conversar = p; }
void CPersonaje::setpasarmapa(bool map){ pasarMapa = map; }
bool CPersonaje::getConversar(){ return conversar; }
int CPersonaje::getnumconversa(){ return ncon; }
char*	CPersonaje::get_equipo(){ return equipo; }
char*	CPersonaje::get_pokeinicial(){ return pokincial; }
void	CPersonaje::set_equipo(char* e){ equipo = e; }
void	CPersonaje::set_pokeinicial(char*p){ pokincial = p; }
int		CPersonaje::get_numpokebolas(){ return num_pokebolas; }
int		CPersonaje::get_numpociones(){ return num_pociones; }
void	CPersonaje::set_numpokebolas(int n){ num_pokebolas = n; }
void	CPersonaje::set_numpociones(int n){ num_pociones = n; }
void	CPersonaje::setPokeparada(bool p){ tomar_pokeparada = p; }
bool	CPersonaje::getPokeparada(){ return tomar_pokeparada; }
int		CPersonaje::get_num_revivir(){ return num_revivir; }
int		CPersonaje::get_num_monedaspokemon(){ return num_monedaspokemon; }
void	CPersonaje::set_numrevivir(int r){ num_revivir = r; }
void	CPersonaje::set_nummonedaspokemon(int m){ num_monedaspokemon = m; }
void CPersonaje::set_centropokemon(bool cp){ centropokemon = cp; }
bool CPersonaje::get_centropokemon(){ return centropokemon; }
bool CPersonaje::getBatallar(){ return batallar; }
void CPersonaje::setBatallar(bool b){ batallar = b; }
int CPersonaje::getPokemons(){ return pokemons; }
bool CPersonaje::getBatallar2(){ return batallar2; }
void CPersonaje::setBatallar2(bool b){ batallar2 = b; }
bool CPersonaje::getBatallar3(){ return batallar3; }
void CPersonaje::setBatallar3(bool b){ batallar3 = b; }
bool CPersonaje::getBatallar4(){ return batallar4; }
void CPersonaje::setBatallar4(bool b){ batallar4 = b; }
bool CPersonaje::getBatallar5(){ return batallar5; }
void CPersonaje::setBatallar5(bool b){ batallar5 = b; }
bool CPersonaje::getBatallar6(){ return batallar6; }
void CPersonaje::setBatallar6(bool b){ batallar6 = b; }
bool CPersonaje::getBatallar7(){ return batallar7; }
void CPersonaje::setBatallar7(bool b){ batallar7 = b; }

int		CPersonaje::geth(){ return huevos; }
void	CPersonaje::setH(int v){ huevos = v; }
int CPersonaje::getmarcapasos(){ return marcapasos; }