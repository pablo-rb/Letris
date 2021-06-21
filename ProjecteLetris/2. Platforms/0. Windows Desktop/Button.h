
////////////////////////////////////////////////////////
//Llibreria grafica
#include "../../0. C++ Code/Graphic Lib/libreria.h"
///////////////////////////////////////////////////////
#include <string>

using namespace std;

class Button
{
public:
	typedef enum {
		NORMAL = 0,
		PRESSED,
		NONE
	} ButtonState;

	
	Button(const string& path_normal, const string& path_pressed, int posX, int posY, int width, int height);
	Button();
	~Button();

	//Consultors
	int getWidth() const { return m_iWidth; } 
	int getHeight() const { return m_iHeight; } 
	int getPosX() const { return m_iPosX; }
	int getPosY() const { return m_iPosY; }

	bool Update(int mousePosX, int mousePosY, bool mouseIsPressed); //return if button has to change (return true if the button is relief and the action starts)
	void Render(); //draw the button either normal or pressed

private:
	ButtonState m_eCurrentState;
	int m_iPosX;
	int m_iPosY;
	int m_iWidth;
	int m_iHeight;
	Sprite m_oNormal;
	Sprite m_pPressed;
};