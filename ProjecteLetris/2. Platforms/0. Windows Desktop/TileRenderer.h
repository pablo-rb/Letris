#ifndef TILERENDERER_H
#define TILERENDERER_H
#include "../../0. C++ Code/Logic Game/joc.h"
#include "../../0. C++ Code/Graphic Lib/libreria.h"
#include <forward_list>


class TileRenderer
{
public:
	TileRenderer();
	~TileRenderer();

	void Render(int column, int row, int letter, bool isPressed);

private:
	Sprite m_aLetters_Normal[MAX_ALPHABET_ENGLISH];
	Sprite m_aLetters_Yellow[MAX_ALPHABET_ENGLISH];
};

#endif
