#include "joc.h"
#include "../../2. Platforms/0. Windows Desktop/LetrisGame.h"
#include <time.h>

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(MIDA_X, MIDA_Y);
	//Mostrem la finestra grafica
	pantalla.show();

	//------------------------------------
	//-----Introducci— a la prˆctica -----
	//
	//  TODO:   Aqu’ heu de crear els sprites/fonts i
	//          totes les variables necessˆries per
	//          treballar en el bucle principal de
	//          sota (do...while).
	//
	//------------------------------------

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	LetrisGame mainGame;

	srand((int)(time(NULL)));

	do
	{
		// Temps del bucle normalitzat en segons
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
				
		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		bool mouseStatus = Mouse_getBtnLeft();
		bool mousePressed = Mouse_getButLeft();

		int mousePosX = Mouse_getX();
		int mousePosY = Mouse_getY();

		//------------------------------------
		//-----Introducci— a la prˆctica -----
		//
		//  TODO:   Aqu’ heu de cridar a draw dels sprites i
		//          les fonts, aix’ com fer les gestions
		//          necessˆries segons el temps i els events
		//          de mouse o teclat.
		//
		//------------------------------------
		mainGame.UpdateAndRender(mousePosX, mousePosY, mousePressed, mouseStatus, deltaTime);

		// Actualitza la pantalla
		pantalla.update();
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
	// Sortim del bucle si pressionem ESC
}
