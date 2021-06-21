#include "Tauler.h"


Tauler::~Tauler()
{
	if (m_teclaCaient != nullptr)
	{
		delete m_teclaCaient;
		m_teclaCaient = nullptr;
	}
}

void Tauler::resetTauler()
{
	m_iNumTiles = 0; 
	start = true; 
	m_bTaulerPle = false; 
	m_bNoPausa = true;
	for (int i = 0; i < BOARD_COLS; ++i)
	{
		m_tauler[i].clear();
	}
	diccionari.resetDictionary();
	whiteAll();
}

Tile* Tauler::generaTile(int columna)
{
	int randNumber = rand() % MAX;
	Tile* t = new Tile(randNumber, columna, 0, 0);
	return t;
}

int Tauler::seleccionaColumna() // Columna con menos valores
{
	int i = 0;
	int minim = m_tauler[i].size();
	int columna = i;
	for (i + 1; i < BOARD_COLS; i++) {
		if (m_tauler[i].size() < minim) {
			minim = m_tauler[i].size();
			columna = i;
		}
	}
	return columna;
}

bool Tauler::arribatFinal(Tile* t,const float velocitat, int columna)
{
	bool arribat = false;
	if (t->actualizaPosY(velocitat, m_tauler[columna].size())) {

		m_tauler[columna].push_back(*t);
		arribat = true;
		m_iNumTiles++;

	}
	return arribat;
}

bool Tauler::comprovaTauler() //retorna true si esta ple
{
	bool ple = false;
	if (m_iNumTiles == 80) {
		ple = true;
	}
	return ple;
}

void Tauler::actualitzaTauler(float velocitat, int mousePosX, int mousePosY, bool mouseIsPressed, int idioma, int& puntuacion)
{
	//Creacion y seleccion de columna
	if (start) {
		m_columna = seleccionaColumna();
		m_teclaCaient = generaTile(m_columna);
		start = false;
		diccionari.setDictionary(idioma);
		diccionari.loadDictionary(idioma);
	}
	else if (m_bGenerarTile && !m_bTaulerPle) {
		m_columna = seleccionaColumna();
		m_teclaCaient = generaTile(m_columna);
		m_bGenerarTile = false;
	}

	//Si le damos a la X
	if (m_bAllWhite) {
		whiteAll();
		m_bAllWhite = false;
	}

	if (m_bCheckPressed)
	{
		string comprovaParaula;
		comprovaParaula.resize(m_oNovaParaula.getNTiles());
		for (int i = 0; i < m_oNovaParaula.getNTiles(); ++i)
		{
			comprovaParaula[i] = m_oNovaParaula.getTile(i);
		}
		if (diccionari.checkWord(comprovaParaula))
		{
			borraLletres();
			whiteAll();
			puntuacion += (m_oNovaParaula.getNTiles() * 10);
		}
		else
		{
			whiteAll();
			puntuacion -= (m_oNovaParaula.getNTiles() * 5);
			if (puntuacion < 0)
				puntuacion = 0;
		}
	}

	dibuixaTauler();
	m_bGenerarTile = arribatFinal(m_teclaCaient, velocitat, m_columna);
	dibuixarLletraCaient(m_teclaCaient);
}

void Tauler::dibuixaTauler() // Dubuja el tablero
{
	vector<Tile>::iterator actual;
	for (int i = 0; i < BOARD_COLS; ++i)
	{
		for (actual = m_tauler[i].begin(); actual != m_tauler[i].end(); ++actual)
		{
			if (m_bNoPausa)
			{
				if (!m_oNovaParaula.getPle())
				{
					if (actual->Update(Mouse_getX(), Mouse_getY(), Mouse_getBtnLeft()))
					{
						if (m_bNovaParaula)
						{
							m_oNovaParaula.inicialitzarParaula();
							m_bNovaParaula = false;
						}
						if (*actual != anterior)
						{
							m_oNovaParaula.setNewTile(*actual);
							anterior.setLletra(actual->getTile());
							anterior.setPosX(actual->getPosX());
							anterior.setPosY(actual->getPosY());
						}
						m_bDibuixaParaula = true;
					}
				}
			}
			if (m_bDibuixaParaula)
			{
				m_oNovaParaula.dibuixaParaula();
			}
			m_oTileRenderer.Render(actual->getPosX(), actual->getPosY(), actual->getTile(), actual->getSelected());
		}
	}
}

void Tauler::dibuixarLletraCaient(Tile* t)
{
	m_oTileRenderer.Render(t->getPosX(), t->getPosY(), t->getTile(), t->getSelected());
}

void Tauler::borraLletres()
{
	for (int i = 0; i < BOARD_COLS; ++i)
	{
		int lletres = getLletresPulsades(i);
		for (int k = 0; k < lletres; ++k)
		{
			vector<Tile>::iterator actual = m_tauler[i].begin();
			bool trobat = false;
			while (!trobat && actual != m_tauler[i].end())
			{
				if (actual->getSelected())
				{
					trobat = true;
				}
				else
				{
					++actual;
				}
			}
			if (trobat)
			{
				vector<Tile>::iterator aux = m_tauler[i].begin() + (m_tauler[i].size() - 1);
				for (aux; aux > actual; --aux)
				{
					aux->setPosY(((aux - 1)->getPosY()));
				}
				m_tauler[i].erase(actual); //implicitamente hace un resize
				m_iNumTiles--;
			}
		}
	}
}

void Tauler::whiteAll()
{
	vector<Tile>::iterator actual;
	for (int i = 0; i < BOARD_COLS; ++i)
	{
		for (actual = m_tauler[i].begin(); actual != m_tauler[i].end(); ++actual)
		{
			if(actual->getSelected())
				actual->setSelected(false);
		}
	}
	m_bCheckPressed = false;
	m_bDibuixaParaula = false;
	m_bNovaParaula = true;
	m_oNovaParaula.setPle(false);
	anterior.setPosX(0);
	anterior.setPosY(0);
}

int Tauler::getLletresPulsades(const int columna)
{
	vector<Tile>::iterator actual;
	int contador = 0;
	for (actual = m_tauler[columna].begin(); actual != m_tauler[columna].end(); ++actual)
	{
		if (actual->getSelected())
		{
			++contador;
		}
	}
	return contador;
}

