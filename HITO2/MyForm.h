#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include "mapas.h"
#include "Personaje.h"
#include "BatallaPokemon.h"
#include "Capturarpokemon.h"
#include "Mochila.h"
#include "MyForm1.h"
#include "Pokeparada.h"
#include "MyForm2.h"
#include "iostream"
using namespace std;

namespace HITO2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Media;
	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
		CPersonaje *Vladimir = new CPersonaje(200, 200);
		CBatallaPokemon * batalla;
		CCapturarpokemon *atrapar;
		Bitmap^ bitmap_jugador = gcnew Bitmap("personaje.png");
		Bitmap ^mapaPrincipal = gcnew Bitmap("mapo.png");
		Bitmap ^ligapokemon = gcnew Bitmap("map.png");
	private: System::Windows::Forms::Timer^  timer1;
			 Bitmap ^mapaCasa = gcnew Bitmap("mp.png");
			 Bitmap ^mapaB = gcnew Bitmap("fondo.png");
			 Bitmap ^charmander = gcnew Bitmap("4.png");
			 Bitmap ^bulbasur = gcnew Bitmap("1.png");
			 Bitmap ^escuero = gcnew Bitmap("7.png");
			 Bitmap ^pikachu = gcnew Bitmap("25.png");
			 Bitmap ^pokeball = gcnew Bitmap("pokeballsprite.png");
			 Bitmap ^escenario = gcnew Bitmap("escenario.png");
			 Bitmap ^maputo = gcnew Bitmap("maputo.png");
			 Mochila ^mochilapokemon = gcnew Mochila;
			 MyForm2 ^imagen = gcnew MyForm2;
			 SoundPlayer ^musica3 = gcnew SoundPlayer("C:pokemonbatalla.wav");
			 SoundPlayer ^musica = gcnew SoundPlayer("C:pokemon.wav");
			 SoundPlayer ^musica2 = gcnew SoundPlayer("C:pokemonsalvaje.wav");
			 SoundPlayer ^musica5 = gcnew SoundPlayer("C:ultimojugador.wav");
			/* Bitmap ^pokepa = gcnew Bitmap("pokeparada.png");*/

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  timer4;



			 Bitmap ^mapaCentro = gcnew Bitmap("centropokemon.png");
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pokeball->MakeTransparent(pokeball->GetPixel(1, 1));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </s1ummary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(13, 495);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(79, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"SQUIRTLE";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(343, 495);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(83, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"BULBASUR";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(495, 495);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(102, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"CHARMANDER";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(192, 537);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(247, 91);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(595, 33);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ESCOGE TU POKEMON INICIAL VLADIMIR";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(27, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(543, 304);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(160, 495);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(72, 17);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"PIKACHU";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1, 618);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			this->label3->Visible = false;
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(640, 640);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String ^equipo;
		String ^pi;
		void conversaciones(int i){
			switch (i){
			case 1:
				equipo = gcnew String(Vladimir->get_equipo());
				pi = gcnew String(Vladimir->get_pokeinicial());
				MessageBox::Show("Vladimir : Papa quiero ser maestro pokemon");
				MessageBox::Show("Padre: Veo que eres del equipo " + equipo);
				MessageBox::Show("Madre : Y tu pokemon incial es " + pi + ",buena eleccion lince");
				MessageBox::Show("Vladimir : :v ");
				MessageBox::Show("Todos : :v");
				break;
			}
		}

		int nuevpociones;
		int nuevpokebolas;
		int nuevrevivir;

		void mostrar_pokemones(){
			String ^ x = "Pokemones :\n";
			vector<CPokemones*> aux = Vladimir->misPokemones->get_arreglo();
			for (int i = 0; i < aux.size(); i++){
				String ^ name = gcnew String(aux[i]->get_nombre());
				String ^aum = name + "	salud: " + aux[i]->get_salud() + "\n";
				x += aum;
			}
			MessageBox::Show(x);
		}

		char*n = new char[50];
		int id;
		int tipe;
		int h;
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 srand(time(NULL));

				 Graphics ^g = this->CreateGraphics();
				 BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
				 BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
				 Rectangle porcionAUsar = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
				 Rectangle redimension = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
				 Mochila ^formulario2 = gcnew Mochila;
				 MyForm1 ^pokedex = gcnew MyForm1;
				 Pokeparada ^pokeparada = gcnew Pokeparada;
				 switch (e->KeyCode){
				 case Keys::Up:
					 if (timer2->Enabled == true){
						 batalla->DIRECCION = DIRECCIONESBATALLA::ARRIBA;
					 }
					 if (timer1->Enabled == true){
						 Vladimir->direccion = Direcciones::Arriba;
					 }
					 break;
				 case Keys::Left:
					 if (timer2->Enabled == true){
						 batalla->DIRECCION = DIRECCIONESBATALLA::IZQUIERDA;
					 }
					 if (timer1->Enabled == true){
						 Vladimir->direccion = Direcciones::Izquierda;
					 }
					 break;
				 case Keys::Right:
					 if (timer2->Enabled == true){
						 batalla->DIRECCION = DIRECCIONESBATALLA::DERECHA;
					 }
					 if (timer1->Enabled == true){
						 Vladimir->direccion = Direcciones::Derecha;
					 }
					 break;
				 case Keys::Down:
					 if (timer2->Enabled == true){
						 batalla->DIRECCION = DIRECCIONESBATALLA::ABAJO;
					 }
					 if (timer1->Enabled == true){
						 Vladimir->direccion = Direcciones::Abajo;
					 }

					 break;
				 case Keys::C:
					 if (Vladimir->getConversar() == true){
						 conversaciones(Vladimir->getnumconversa());
					 }
					 Vladimir->setConversar(false);
					 break;
				 case Keys::F:
					 mochilapokemon->Visible = true;
					 MessageBox::Show("Pokebolas :" + Vladimir->get_numpokebolas() + "\nPociones: " + Vladimir->get_numpociones() + "\nRevivir: " +
						 Vladimir->get_num_revivir() +  "\nMarcapasos: "+Vladimir->getmarcapasos() + "\nHuevos: "+Vladimir->geth() + "\nMonedas: "+Vladimir->get_num_monedaspokemon());
					 mochilapokemon->Visible = false;
					 break;
				 case Keys::T:
					 if (Vladimir->getPokeparada() == true){
						 nuevpociones = 0 + rand() % 5;
						 nuevpokebolas = 0 + rand() % 5;
						 nuevrevivir = 0 + rand() % 5;
						 h = 0 + rand() % 2;
						 pokeparada->Visible = true;
						 MessageBox::Show("Has conseguido " + nuevpociones + " pociones , " + nuevpokebolas + " pokebolas , " + nuevrevivir + " revivir y "+h+ " huevos");
						 pokeparada->Visible = false;
						 Vladimir->set_numpokebolas(Vladimir->get_numpokebolas() + nuevpokebolas);
						 Vladimir->set_numpociones(Vladimir->get_numpociones() + nuevpociones);
						 Vladimir->set_numrevivir(Vladimir->get_num_revivir() + nuevrevivir);
						 Vladimir->setH(Vladimir->geth() + h);
					 }
					 Vladimir->setPokeparada(false);
					 break;
				 case Keys::P:
					 pokedex->Visible = true;
					 mostrar_pokemones();
					 pokedex->Visible = false;
					 break;
				 case Keys::I:
					 MessageBox::Show("Movimiento: Flechas Direccionales\nInstrucciones: I \nVer pokemones actuales: P \nMochila: M \nConversar: C \nPokeparadas : T \nRestaurar en CP : S\nAgregar Pokemon (por ahora): L");
					 break;
				 case Keys::S:
					 if (Vladimir->get_centropokemon() == true){
						 Vladimir->misPokemones->restaurar_salud();
						 MessageBox::Show("Todos tus pokemones han sido curados");
					 }
					 Vladimir->set_centropokemon(false);
					 break;
				 case Keys::L:
					 id = 1 + rand() % 4;
					 Vladimir->misPokemones->agreagar(id, tipe, n);
					 break;
				 case Keys::B:
					 if (Vladimir->getBatallar() == true){
						 MessageBox::Show("Usted quiere ser un maestro pokemon ");
						 MessageBox::Show("Veamos vladimir si puedes con eso en una batalla pokemon!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(2);
							 batalla->set_bajarvidaenemiga(2);
							 musica3->Play();
						 }
						
					 }	
					 if (Vladimir->getBatallar2() == true){
						 MessageBox::Show("Bienvenido a la Liga Pokemon ");
						 MessageBox::Show("Soy 1 de la Elite four ");
						 MessageBox::Show("Si quiere ser el mejor luchador pokemon tiene que ganarle a todos los de la sala");
						 MessageBox::Show("Pues empezemos !!!!!! ");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, bulbasur);
							 batalla->set_bajarvidaamiga(1);
							 batalla->set_bajarvidaenemiga(4);
							 musica3->Play();
						 }
					 }
					
					 if (Vladimir->getBatallar3() == true){
						 Vladimir->setBatallar2(false);
						 MessageBox::Show("Soy 2 de la Elite four ");
						 MessageBox::Show("Veo que ya superaste a 1 , bueno es hora que me superes a mi");
						 MessageBox::Show("Luchemos !!!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, escuero);
							 batalla->set_bajarvidaamiga(1);
							 batalla->set_bajarvidaenemiga(4);
							 musica3->Play();
						 }
					 }
					
					 if (Vladimir->getBatallar4() == true){
						 MessageBox::Show("Soy 3 de la Elite four");
						 MessageBox::Show("Veo que superaste a 2 , bueno es hora que me ganaste a mi");
						 MessageBox::Show("Comencemos!!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(2);
							 batalla->set_bajarvidaenemiga(2);
							 musica3->Play();
						 }
						 
					 }
					 if (Vladimir->getBatallar4() == true){
						 MessageBox::Show("Soy 4 de la Elite four ");
						 MessageBox::Show("Veo que superaste a 3 , bueno es hora que me combatas conmigo");
						 MessageBox::Show("Adelante!!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(3);
							 batalla->set_bajarvidaenemiga(3);
							 musica3->Play();
						 }
	
					 }
					 if (Vladimir->getBatallar5() == true){
						 MessageBox::Show("Soy 5 de la Elite four ");
						 MessageBox::Show("Veo que superaste a 4 , ya te estas acercando a ser un maestro pokemon");
						 MessageBox::Show("Empecemos!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(3);
							 batalla->set_bajarvidaenemiga(3);
							 musica3->Play();
						 }

					 }
					 if (Vladimir->getBatallar6() == true){
						 MessageBox::Show("Soy 6 de la Elite four ");
						 MessageBox::Show("Veo que superaste a 5 ,soy el ultimo en la elite four , si quieres vencer al campeon debes vencerme a mi");
						 MessageBox::Show("Comencemos!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(3);
							 batalla->set_bajarvidaenemiga(3);
							 musica3->Play();
						 }

					 }
					 if (Vladimir->getBatallar7() == true){
						 MessageBox::Show("¿Hola que tal? ");
						 MessageBox::Show("Soy Luis Vives campeon de la liga pokemon");
						 MessageBox::Show("Veo que ya derrotaste a los 6 lideres del gimansio de la elite four, bueno ahora si quieres ser campeon debes vencerme a mi");
						 MessageBox::Show("Que empiece la batalla!!!!!!!!!!!!!!");
						 timer1->Enabled = false;
						 timer2->Enabled = true;

						 if (timer2->Enabled == true){
							 batalla = new CBatallaPokemon(charmander, pikachu);
							 batalla->set_bajarvidaamiga(3);
							 batalla->set_bajarvidaenemiga(3);
							 musica5->Play();
						 }

					 }
					 Vladimir->set_centropokemon(false);
					 break;
				 case Keys::K:
					 if (timer2->Enabled == true){
						 timer2->Enabled = false;
						 timer1->Enabled = true;
					 }
					 if (timer3->Enabled == true){
						 MessageBox::Show("El pokemon ha huido");
						 timer3->Enabled = false;
						 timer1->Enabled = true;
					 }
					 break;
				 case Keys::J:
					 if (timer2->Enabled == true){
						 batalla->set_nv1(batalla->get_nv1() - 1);
						 
					 }
					 break;
				 case Keys::Y:
					 if (timer2->Enabled == true){
						 batalla->set_nv2(batalla->get_nv2() - 1);
						 
					 }
					 break;
				 case Keys::O:
					 MessageBox::Show("Encontraste un pokemon");
					 atrapar = new CCapturarpokemon(escuero, pokeball);
					 timer1->Enabled = false;
					 timer3->Enabled = true;
					 break;
				 case Keys::Q:
					 if (timer3->Enabled == true){
						 MessageBox::Show("Pokemon atrapado");
						 Vladimir->misPokemones->agreagar(2, tipe, n);
						 timer3->Enabled = false;
						 timer1->Enabled = true;
					 }
				 }
	}

			 int x = 0; int y = 0;
			 int aleatorio;
			 int a;
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 srand(time(NULL));
				 musica5->Stop();
				 
				 aleatorio = 0 + rand() % 90;
				 Graphics ^g = this->CreateGraphics();
				 BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
				 BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
				 Rectangle porcionAUsar = Rectangle(x, y, this->ClientRectangle.Width, this->ClientRectangle.Height);
				 Rectangle redimension = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

				 label2->Visible = false;
				 label3->Visible = false;

				 switch (Vladimir->get_UVM()){
				 case 0:
					 buffer->Graphics->DrawImage(mapaPrincipal, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 20, 20, mapa1);
					 musica->Play();
					 break;
				 case 2:

					 buffer->Graphics->DrawImage(mapaCasa, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 15, 20, mapa2);
					 musica->Play();
					 break;
				 case 3:

					 buffer->Graphics->DrawImage(mapaCentro, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 24, 21, mapa3);
					 musica->Play();
					 break;
				 case 4:

					 buffer->Graphics->DrawImage(mapaPrincipal, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 20, 20, mapa1);
					 musica->Play();
					 break;
				 case 5:

					 buffer->Graphics->DrawImage(mapaPrincipal, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 20, 20, mapa1);
					 musica->Play();
					 break;

				//arreglar
				 case 6:
					 buffer->Graphics->DrawImage(maputo, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 20, 20, maputa);
					 
					 break;
					 //-----------------------------------------------
				 case 15:
					 buffer->Graphics->DrawImage(ligapokemon, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 32, 20, mapaligaPokemon);
				/*	 musica4->Play();*/

					 break;
				 case 16:

					 buffer->Graphics->DrawImage(mapaPrincipal, redimension, porcionAUsar, GraphicsUnit::Pixel);
					 Vladimir->mover(buffer, bitmap_jugador, 20, 20, mapa1);
					 musica->Play();
				 }
				  
				 if (Vladimir->getmarcapasos() % 1000 == 0 && Vladimir->geth() > 0){
					 timer1->Enabled = false;
					 MessageBox::Show("Uno de tus huevos a reventado, te ganaste un pokemon extra");
					 a = 1 + rand() % 5;
					 Vladimir->misPokemones->agreagar(a, a, "Huevito");
					 Vladimir->setH(Vladimir->geth() - 1);
					 timer1->Enabled = true;
				 }


				 if (Vladimir->get_num_monedaspokemon() >= 1000){
					 timer1->Enabled = false;
					 MessageBox::Show("YA ERES UN MAESTRO POKEMON HAS GANADO EL JUEGO");
					 this->Hide();
				 }


				 buffer->Render(g);
				 

	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if (timer1->Enabled == true)
					Vladimir->direccion = Direcciones::Ninguna;
				 if (timer2->Enabled == true)
					 batalla->DIRECCION = DIRECCIONESBATALLA::NINGUNA;

	}
			 int c = 0;
			 char *equip = new char[20];
			 char *pokemon_inicial = new char[20];
			 int id_ini;
			 int t;


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 c++;

				 if (c == 1){
					 radioButton4->Hide();
					 radioButton4->Enabled = false;
					 this->radioButton2->Location = System::Drawing::Point(270, 495);
					 label1->Text = "ESCOGE UN EQUIPO VLADI";
					 radioButton1->Text = "INSTINTO";
					 radioButton2->Text = "MISTICO";
					 radioButton3->Text = "VALOR";


				 }

				 if (c == 2){
					 pictureBox1->Hide();
					 pictureBox1->Enabled = false;
					 radioButton1->Hide();
					 radioButton1->Enabled = false;
					 radioButton2->Hide();
					 radioButton2->Enabled = false;
					 radioButton3->Hide();
					 radioButton3->Enabled = false;
					 label1->Hide();
					 label1->Enabled = false;
					 button1->Hide();
					 button1->Enabled = false;
					 Vladimir->set_equipo(equip);
					 Vladimir->set_pokeinicial(pokemon_inicial);
					 Vladimir->misPokemones->agreagar(id_ini, t, pokemon_inicial);
					 timer1->Enabled = true;
					 musica->Play();
				 }
	}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (c == 0){
				 pictureBox1->Image = System::Drawing::Image::FromFile("squirtle.gif");
				 pokemon_inicial = "SQUIRTLE";
				 id_ini = 2;
			 }
			 if (c == 1){
				 pictureBox1->Image = System::Drawing::Image::FromFile("tin.jpg");
				 equip = "INSTINTO";
			 }
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (c == 0){
				 pictureBox1->Image = System::Drawing::Image::FromFile("pikachu.gif");
				 pokemon_inicial = "PIKACHU";
				 id_ini = 4;
			 }

}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (c == 0){
				 pictureBox1->Image = System::Drawing::Image::FromFile("bulbasur.gif");
				 pokemon_inicial = "BULBASUR";
				 
				 id_ini = 3;
			 }
			 if (c == 1){
				 pictureBox1->Image = System::Drawing::Image::FromFile("tmy.jpg");
				 equip = "MISTICO";
			 }
}

private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (c == 0){
				 
				 cout << "    "; pictureBox1->Image = System::Drawing::Image::FromFile("charmander.gif");
				 pokemon_inicial = "CHARMANDER";
				 id_ini = 1;
			 }
			 if (c == 1){
				 pictureBox1->Image = System::Drawing::Image::FromFile("tva.jpg");
				 equip = "VALOR";
			 }
}

private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {

				 Graphics ^g = this->CreateGraphics();
				 BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
				 BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
				 Rectangle porcionAUsar = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
				 Rectangle redimension = Rectangle(0, 0, this->ClientRectangle.Width*(640.0/240.0), this->ClientRectangle.Height*4);
				 buffer->Graphics->DrawImage(escenario, redimension, porcionAUsar, GraphicsUnit::Pixel);
				 if (id_ini == 1){
					 batalla->mov_final(buffer, charmander,pikachu, 20, 20, mapabatalla);
				 }
				 if (id_ini == 2){

					 batalla->mov_final(buffer, escuero, pikachu, 20, 20, mapabatalla);
					 batalla->set_bajarvidaamiga(4);
					 batalla->set_bajarvidaenemiga(1);
				 }
				 if (id_ini == 3){

					 batalla->mov_final(buffer,  bulbasur, pikachu, 20, 20, mapabatalla);
				 }
				 if (id_ini == 4){

					 batalla->mov_final(buffer, pikachu, pikachu, 20, 20, mapabatalla);
				 }
				 label2->Visible = true;
				 label3->Visible = true;
				 label2->Text = "Vidas : " + batalla->get_nv2();
				 label3->Text = "Vidas : " + batalla->get_nv1();

				 if (batalla->get_nv1() <= 0 || batalla->get_nv2() <= 0 ){

					 timer2->Enabled = false;
					 timer1->Enabled = true;
					 if (batalla->get_nv2() <= 0){ MessageBox::Show("ganaste xdxdxd"); Vladimir->set_nummonedaspokemon(Vladimir->get_num_monedaspokemon() + 50); }
					 if (batalla->get_nv1() <= 0){ MessageBox::Show("perdiste"); }
				 }

				 buffer->Render(g);
				 
	}
	private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (timer2->Enabled == true){
					 batalla->set_dispara(true);
				 }
				 if (timer3->Enabled == true){
					 atrapar->set_coger_pokeball(true);
					 Vladimir->set_numpokebolas(Vladimir->get_numpokebolas() - 1);
				 }
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		         musica2->Play();
				 Graphics ^g = this->CreateGraphics();
				 BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
				 BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
				 Rectangle porcionAUsar = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
				 Rectangle redimension = Rectangle(0, 0, this->ClientRectangle.Width*(640.0 / 240.0), this->ClientRectangle.Height * 4);
				 buffer->Graphics->DrawImage(mapaB, redimension, porcionAUsar, GraphicsUnit::Pixel);
				 atrapar->moverpokemonrival(buffer, escuero, pokeball, 20, 20, mapabatalla);
				 label3->Visible = true;
				 label3->Text="Nro de pokebolas: " + Vladimir->get_numpokebolas();
				 if (atrapar->get_atrapado() == true){
					 timer3->Enabled = false;
					 timer1->Enabled = true;
					 MessageBox::Show("Pokemon atrapado");
					 atrapar->set_atrapado(false);
					 Vladimir->misPokemones->agreagar(2, 2, "");
				 }
				 buffer->Render(g);
				
	}
	

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	imagen->Visible = true;
	MessageBox::Show("Bienvenido al mundo pokemon");
	MessageBox::Show("Tu eres vladimir, un chico que deseas ser el mejor maestro pokemon");
	MessageBox::Show("Es por eso que te decidiste a combatir a cualquiera que se te oponga");
	MessageBox::Show("Muy bien , empecemos escogiendo tu pokemon");
	imagen->Visible = false;
	musica->Play();
}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Mujer_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
