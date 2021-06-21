#include "TileRenderer.h"

TileRenderer::TileRenderer()
{
	m_aLetters_Normal[0].create("./data/Letters/white_0.png");
	m_aLetters_Yellow[0].create("./data/Letters/yellow_0.png");
	m_aLetters_Normal[1].create("./data/Letters/white_1.png");
	m_aLetters_Yellow[1].create("./data/Letters/yellow_1.png");
	m_aLetters_Normal[2].create("./data/Letters/white_2.png");
	m_aLetters_Yellow[2].create("./data/Letters/yellow_2.png");
	m_aLetters_Normal[3].create("./data/Letters/white_3.png");
	m_aLetters_Yellow[3].create("./data/Letters/yellow_3.png");
	m_aLetters_Normal[4].create("./data/Letters/white_4.png");
	m_aLetters_Yellow[4].create("./data/Letters/yellow_4.png");
	m_aLetters_Normal[5].create("./data/Letters/white_5.png");
	m_aLetters_Yellow[5].create("./data/Letters/yellow_5.png");
	m_aLetters_Normal[6].create("./data/Letters/white_6.png");
	m_aLetters_Yellow[6].create("./data/Letters/yellow_6.png");
	m_aLetters_Normal[7].create("./data/Letters/white_7.png");
	m_aLetters_Yellow[7].create("./data/Letters/yellow_7.png");
	m_aLetters_Normal[8].create("./data/Letters/white_8.png");
	m_aLetters_Yellow[8].create("./data/Letters/yellow_8.png");
	m_aLetters_Normal[9].create("./data/Letters/white_9.png");
	m_aLetters_Yellow[9].create("./data/Letters/yellow_9.png");
	m_aLetters_Normal[10].create("./data/Letters/white_10.png");
	m_aLetters_Yellow[10].create("./data/Letters/yellow_10.png");
	m_aLetters_Normal[11].create("./data/Letters/white_11.png");
	m_aLetters_Yellow[11].create("./data/Letters/yellow_11.png");
	m_aLetters_Normal[12].create("./data/Letters/white_12.png");
	m_aLetters_Yellow[12].create("./data/Letters/yellow_12.png");
	m_aLetters_Normal[13].create("./data/Letters/white_13.png");
	m_aLetters_Yellow[13].create("./data/Letters/yellow_13.png");
	m_aLetters_Normal[14].create("./data/Letters/white_14.png");
	m_aLetters_Yellow[14].create("./data/Letters/yellow_14.png");
	m_aLetters_Normal[15].create("./data/Letters/white_15.png");
	m_aLetters_Yellow[15].create("./data/Letters/yellow_15.png");
	m_aLetters_Normal[16].create("./data/Letters/white_16.png");
	m_aLetters_Yellow[16].create("./data/Letters/yellow_16.png");
	m_aLetters_Normal[17].create("./data/Letters/white_17.png");
	m_aLetters_Yellow[17].create("./data/Letters/yellow_17.png");
	m_aLetters_Normal[18].create("./data/Letters/white_18.png");
	m_aLetters_Yellow[18].create("./data/Letters/yellow_18.png");
	m_aLetters_Normal[19].create("./data/Letters/white_19.png");
	m_aLetters_Yellow[19].create("./data/Letters/yellow_19.png");
	m_aLetters_Normal[20].create("./data/Letters/white_20.png");
	m_aLetters_Yellow[20].create("./data/Letters/yellow_20.png");
	m_aLetters_Normal[21].create("./data/Letters/white_21.png");
	m_aLetters_Yellow[21].create("./data/Letters/yellow_21.png");
	m_aLetters_Normal[22].create("./data/Letters/white_22.png");
	m_aLetters_Yellow[22].create("./data/Letters/yellow_22.png");
	m_aLetters_Normal[23].create("./data/Letters/white_23.png");
	m_aLetters_Yellow[23].create("./data/Letters/yellow_23.png");
	m_aLetters_Normal[24].create("./data/Letters/white_24.png");
	m_aLetters_Yellow[24].create("./data/Letters/yellow_24.png");
	m_aLetters_Normal[25].create("./data/Letters/white_25.png");
	m_aLetters_Yellow[25].create("./data/Letters/yellow_25.png");
}

TileRenderer::~TileRenderer()
{
}

void TileRenderer::Render(int column, int row, int letter, bool isPressed)
{
	int i = letter;
	if (isPressed)
		m_aLetters_Yellow[i - 97].draw(column, row);
	else
		m_aLetters_Normal[i - 97].draw(column, row);
}
