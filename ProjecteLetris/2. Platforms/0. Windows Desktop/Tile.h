#ifndef TILE_H
#define TILE_H

////////////////////////////////////////////////////////
//Llibreria grafica
#include "../../0. C++ Code/Graphic Lib/libreria.h"
#include "../../0. C++ Code/Logic Game/joc.h"
#include <string>

using namespace std;

class Tile
{
public:
	typedef enum {
		WHITE,
		YELLOW,
		NONE
	}CurrentState;

	Tile();
	Tile(const int random, const int column, const int row, const bool selected);
	~Tile();

	bool getSelected() const { return m_bSelected; }
	int getPosX() const { return m_iPosX; }
	int getPosY() const { return m_iPosY; }
	int getTile() const { return m_cLletra; }
	bool actualizaPosY(const float velocitat, int numeroLetras); //return true si la letra ha llegado abajo

	bool Update(int mousePosX, int mousePosY, bool mouseIsPressed);

	void setSprite(const int number);
	void setPosX(const int X) { m_iPosX = X; }
	void setPosY(const int Y) { m_iPosY = Y; }
	void setSelected(const bool selected) { m_bSelected = selected; }
	void setLletra(const char c) { m_cLletra = c; }

	bool operator!=(Tile& tile);

private:
	char m_cLletra;
	int m_iPosX;
	float m_iPosY;
	float m_fNovaPosicio;
	bool m_bSelected;
	CurrentState m_eCurrentState;

	// PARA REVISAR COSAS
	int contador = 0;
};


#endif