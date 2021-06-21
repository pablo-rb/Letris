#ifndef PARAULACANDIDATA_H
#define PARAULACANDIDATA_H


#include <vector>
#include "Tile.h"
#include "TileRenderer.h"

class ParaulaCandidata
{
public:
	ParaulaCandidata();
	~ParaulaCandidata();

	void setNewTile(Tile& newTile);

	void inicialitzarParaula();
	void resetParaula();
	void dibuixaParaula();

	bool getPle() const { return m_bPle; }
	void setPle(bool b) { m_bPle = b; }
	int getNTiles() { return m_iNTiles; }
	char getTile(const int i) { return m_paraula[i].getTile(); }

private:
	static const int MAX = 8;
	vector<Tile> m_paraula;
	int m_iNTiles = 0;
	bool m_bPle;

	TileRenderer m_oTile;
};

#endif 
