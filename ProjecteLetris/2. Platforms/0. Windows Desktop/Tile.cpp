#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(const int random, const int column, const int row, const bool selected)
{
	setSprite(random);
	m_iPosX = column * (TILE_WIDTH + 1) + (BOARD_INIT_X - 3);
	m_fNovaPosicio = m_iPosY = row * (TILE_HEIGHT + 1) + (BOARD_INIT_Y - 20);
	m_bSelected = selected;
	m_eCurrentState = WHITE;
}

Tile::~Tile()
{
}

bool Tile::actualizaPosY(const float velocitat, int numeroLetras)
{
	m_iPosY = m_fNovaPosicio;
	m_fNovaPosicio = m_fNovaPosicio + velocitat;
	float alturaVector = (10 - numeroLetras) * (TILE_HEIGHT + 1) + BOARD_INIT_Y - 4;

	if (m_fNovaPosicio >= alturaVector) {
		m_iPosY = alturaVector;
		return true;
	}
	return false;
}

bool Tile::Update(int mousePosX, int mousePosY, bool mouseIsPressed)
{
	bool l_bDoAction = false;
	if (mouseIsPressed && (mousePosX >= m_iPosX && mousePosX <= m_iPosX + TILE_WIDTH && mousePosY >= m_iPosY && mousePosY <= m_iPosY + TILE_WIDTH))
	{
		m_eCurrentState = YELLOW;
		m_bSelected = true;
		l_bDoAction = true;
	}
	return l_bDoAction;
}

void Tile::setSprite(const int number)
{
	if (number <= 45) { // VOCALES
		int randNumber = rand() % MAX_ALPHABET_ENGLISH_VOWELS;
		switch (randNumber) {
		case 0:	m_cLletra = 'a';
			break;
		case 1: m_cLletra = 'e';
			break;
		case 2: m_cLletra = 'i';
			break;
		case 3: m_cLletra = 'o';
			break;
		case 4: m_cLletra = 'u';
			break;
		}
	}
	else { // CONSONANTES
		int randNumber = rand() % MAX_ALPHABET_ENGLISH_CONSONANTS;
		switch (randNumber) {
		case 0:		 m_cLletra = 'b';
			break;
		case 1:		 m_cLletra = 'c';
			break;
		case 2:		 m_cLletra = 'd';
			break;
		case 3:		 m_cLletra = 'f';
			break;
		case 4:		 m_cLletra = 'g';
			break;
		case 5:		 m_cLletra = 'h';
			break;
		case 6:		 m_cLletra = 'j';
			break;
		case 7:		 m_cLletra = 'k';
			break;
		case 8:		 m_cLletra = 'l';
			break;
		case 9:		 m_cLletra = 'm';
			break;
		case 10:	 m_cLletra = 'n';
			break;
		case 11:	 m_cLletra = 'p';
			break;
		case 12:	 m_cLletra = 'q';
			break;
		case 13:	 m_cLletra = 'r';
			break;
		case 14:	 m_cLletra = 's';
			break;
		case 15:	 m_cLletra = 't';
			break;
		case 16:	 m_cLletra = 'v';
			break;
		case 17:	 m_cLletra = 'w';
			break;
		case 18:	 m_cLletra = 'x';
			break;
		case 19:	 m_cLletra = 'y';
			break;
		case 20:	 m_cLletra = 'z';
			break;
		}
	}
}

bool Tile::operator!=(Tile& tile)
{
	return (getTile() != tile.getTile() || (getTile() == tile.getTile() && getPosX() != tile.getPosX() && getPosY() != tile.getPosY()) || (getTile() == tile.getTile() && (getPosX() == tile.getPosX() && getPosY() != tile.getPosY())) || (getTile() == tile.getTile() && (getPosX() != tile.getPosX() && getPosY() == tile.getPosY())));
}

