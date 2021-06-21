#pragma once
////////////////////////////////////////////////////////
//Llibreria grafica
#include "../../0. C++ Code/Graphic Lib/libreria.h"
///////////////////////////////////////////////////////
#include <string>

using namespace std;

class RadioButton
{
public:
	typedef enum {
		NORMAL,
		PRESSED,
		NONE
	}RBState;

	RadioButton(const string& path_normal, const string& path_pressed, int posX, int posY, int width, int height);
	RadioButton();
	~RadioButton();

	bool Update(int mousePosX, int mousePosY, bool mouseIsPressed);//return if button has to change (return true if the button is pressed)
	void Render();

	void setOn(bool isOn);
	bool isOn() const;

	int getPosX() const { return m_iPosX; }
	int getPosY() const { return m_iPosY; }

private:
	Sprite m_oOff;
	Sprite m_oOn;
	bool m_bIsOn;
	int m_iPosX;
	int m_iPosY;
	int m_iWidth;
	int m_iHeight;
	RBState m_eCurrentState;
};