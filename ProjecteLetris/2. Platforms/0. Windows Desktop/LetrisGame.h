#include "../../0. C++ Code/Logic Game/joc.h"
#include "Button.h"
#include "RadioButton.h"
//#include "TileRenderer.h"
#include "Tile.h"
#include "Tauler.h"
#include "Dictionary.h"
#include "../../0. C++ Code/Graphic Lib/sound.h"

////////////////////////////////////////////////////////
//Llibreria grafica
#include "../../0. C++ Code/Graphic Lib/libreria.h"
#include "../../0. C++ Code/Graphic Lib/NFont/NFont.h"
#include "TileRenderer.h"
///////////////////////////////////////////////////////

class LetrisGame
{
public:
	typedef enum {
		MAIN_MENU = 0,
		PLAYING,
		GAME_OVER,
		PAUSE,
		WAIT_SCORE,
		NONE
	}GameState;

	LetrisGame();
	~LetrisGame();

	void UpdateAndRender(int mousePosX, int mousePosY, bool mouseIsPressed, bool mouseStatus, float deltaTime);

	void modificaVelocitat(float velocitat, float timer, int nTiles);
	void getMaxScore();
	void setMaxScore(int n);


private:
	static const int MAX = 101;
	//UI ELEMENTS
	Button m_oCheckButton = Button("./data/GUI/Button_Normal.png", "./data/GUI/Button_Pressed.png", 148, 755, 194, 85);
	Button m_oStartButton = Button("./data/GUI/Button_Normal.png", "./data/GUI/Button_Pressed.png", 148, 755, 194, 85);
	Button m_oDeleteWordButton = Button("./data/GUI/Btn_Circle_Close_1_Normal.png", "./data/GUI/Btn_Circle_Close_3_Pressed.png", 380, 755, 90, 90);
	RadioButton m_oPauseRadioButton = RadioButton("./data/GUI/Btn_Circle_Pause_1_Normal.png", "./data/GUI/Btn_Circle_Play_1_Normal.png", 380, 10, 90, 90);
	RadioButton m_oSpanishRadioButton = RadioButton("./data/GUI/Checkbox_Disabled.png", "./data/GUI/Checkbox_Enabled.png", 50, 245, 27, 28);
	RadioButton m_oEnglishRadioButton = RadioButton("./data/GUI/Checkbox_Disabled.png", "./data/GUI/Checkbox_Enabled.png", 50, 205, 27, 28);
	RadioButton m_oCatalanRadioButton = RadioButton("./data/GUI/Checkbox_Disabled.png", "./data/GUI/Checkbox_Enabled.png", 50, 285, 27, 28);
	Sprite m_oTimerBar;
	Sprite m_oMainMenu_BG;
	Sprite m_oGameOver;
	NFont m_oFont = NFont("./data/Fonts/FreeSans.ttf", 30, NFont::Color(255, 255, 255, 255)); //White Letters
	NFont m_oFont_Black = NFont("./data/Fonts/FreeSans.ttf", 30, NFont::Color(0, 0, 0, 255)); //Black Letters

	//EXTRAS
	Sprite m_oBackGround_Main;
	Sprite m_oBackGround_Playing;
	bool m_bCanStart;
	bool m_bShowGameBoard;

	//LOGIC COMPONENTS
	GameState m_eCurrentState;
	TileRenderer m_oTileRenderer;
	float m_fTimer;
	float m_fVelocitat = 0.8;
	float m_fVelocitatInicial = 0.5;
	Tauler m_oTauler;

	//GESTION DE RANKING
	Button m_oRanking = Button("./data/GUI/Btn_Circle_Ranking1_1_Normal.png", "./data/GUI/Btn_Circle_Ranking1_1_Normal.png", 17, 3, 90, 90);
	bool showRanking = false;
	Sprite m_oPuntuacio;
	int m_cPuntuacio;
	int m_iMaxScore;

	//GESTION MUSICA
	//RadioButton m_oMusic = RadioButton("./data/GUI/Music_Off.png","./data/GUI/Music_On.png", 372, 40, 72, 38);



	//GESTION DICCIONARIO Y TIEMPO
	float tiempo;
	int m_iIdioma;
	Dictionary diccionari;

	//FOR TESTING PURPOSES
	//bool m_bDrawTiles;
};