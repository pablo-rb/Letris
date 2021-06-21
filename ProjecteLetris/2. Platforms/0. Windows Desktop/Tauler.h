
#include <vector>
#include "Tile.h"
#include "TileRenderer.h"
#include "ParaulaCandidata.h"
#include "Dictionary.h"

class Tauler
{
public:

	Tauler() { m_iNumTiles = 0; start = true; m_bTaulerPle = false; m_bNoPausa = true; }
	~Tauler();

	void resetTauler();

	//Post: genera una nova lletra a l'atzar
	Tile* generaTile(int columna);
	Tile* getLletraCaient() { return m_teclaCaient; };
	//Post: selecciona la columna amb menys lletres
	int seleccionaColumna();
	int getNumTiles() { return m_iNumTiles; }
	//Post: return true, si la lletra ha arribat abaix, false, en cas contrari
	bool arribatFinal(Tile* t,const float velocitat, int columna);
	//Post: retur true, si el tauler esta ple de lletres
	bool comprovaTauler();

	//Post: gestiona el tauler; lletres, putuacio, velocitat, diccionari...
	void actualitzaTauler(float velocitat, int mousePosX, int mousePosY, bool mouseIsPressed, int idioma, int& puntuacion);
	//Post: dibuixa el tauler y va gestionant la paraula que es vol seleccionar
	void dibuixaTauler();
	void dibuixarLletraCaient(Tile* t);
	//Post: gestiona el esborrat de les lletres seleccionades
	void borraLletres();

	//Post: totes les lletres sense clicar i varies inicialitzacions
	void whiteAll();
	void setAllWhite(const bool num) { m_bAllWhite = num; }
	void setPause(const bool num) { m_bNoPausa = num; }
	void setCheck(bool b) { m_bCheckPressed = b; }
	bool getCheck() { return m_bCheckPressed; }
	int getLletresPulsades(const int columna);


private:
	static const int MAX = 101;
	vector<Tile> m_tauler[BOARD_COLS];
	int m_iNumTiles;
	bool m_bGenerarTile; // Cuando llega abajo la m_teclaCaient se pone en true para generar otra
	bool start;
	bool m_bTaulerPle;
	bool m_bNoPausa;
	int m_columna;

	Tile* m_teclaCaient;
	bool m_bAllWhite;

	TileRenderer m_oTileRenderer;

	//PARAULA QUE ES VOL CHECKEAR
	ParaulaCandidata m_oNovaParaula;
	bool m_bNovaParaula = true;
	bool m_bDibuixaParaula = true;
	bool m_bParaulaPlena = false;
	Tile anterior;

	//CORRECCIO DE PARAULA
	bool m_bCheckPressed = false;
	int diccionariNParaules;
	Dictionary diccionari;

	// PARA REVISAR COSAS
	int contador = 0;
};