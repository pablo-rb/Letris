#include "ParaulaCandidata.h"


ParaulaCandidata::ParaulaCandidata()
{
	m_iNTiles = 0;
	m_bPle = false;
}

ParaulaCandidata::~ParaulaCandidata()
{
}

void ParaulaCandidata::setNewTile(Tile& newTile)
{

	m_paraula.push_back(newTile);
	++m_iNTiles;

	if (m_iNTiles == MAX)
		m_bPle = true;

}


void ParaulaCandidata::inicialitzarParaula()
{
	m_paraula.resize(0);
	m_iNTiles = 0;
}

void ParaulaCandidata::resetParaula()
{
	m_paraula.clear();
	m_paraula.resize(0);
}

void ParaulaCandidata::dibuixaParaula()
{
	vector<Tile>::iterator actual;
	int contador = 0;
	for (actual = m_paraula.begin(); actual != m_paraula.end(); ++actual)
	{
		m_oTile.Render( contador * (TILE_WIDTH + 1) + (BOARD_INIT_X - 3), 12 * (TILE_HEIGHT + 1) + BOARD_INIT_Y - 12, actual->getTile(), false);
		++contador;
	}
}
