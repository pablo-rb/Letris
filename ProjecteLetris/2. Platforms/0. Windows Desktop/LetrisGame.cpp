#include "LetrisGame.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

LetrisGame::LetrisGame()
{
	m_oMainMenu_BG.create("./data/GUI/MainMenu_BG.png");								//Fons MAIN_MENU
	m_oGameOver.create("./data/GUI/GameOver.png");
	m_oTimerBar.create("./data/GUI/Time_Bar.png");

	m_oBackGround_Main.create("./data/GUI/background_main.png");
	m_oBackGround_Playing.create("./data/GUI/background_play.png");

	m_oPuntuacio.create("./data/GUI/Button_Normal.png");

	m_eCurrentState = MAIN_MENU;
}

LetrisGame::~LetrisGame()
{

}

void LetrisGame::UpdateAndRender(int mousePosX, int mousePosY, bool mouseIsPressed, bool mouseStatus, float deltaTime)
{
	if (m_eCurrentState == PLAYING || m_eCurrentState == GAME_OVER || m_eCurrentState == WAIT_SCORE)
	{
		m_fTimer += deltaTime;
	}
	else if (m_eCurrentState == MAIN_MENU)
	{
		m_fTimer = 0;
		m_cPuntuacio = 0;
	}

	switch (m_eCurrentState)
	{
	case MAIN_MENU:

		m_oBackGround_Main.draw(0, 0);
		m_oMainMenu_BG.draw(0, 0);
		m_oStartButton.Render();
		m_oFont.draw(290, 205, NFont::Scale(0.70f), "%s", "MAX SCORE");
		getMaxScore();
		m_oFont.draw(300, 230, NFont::Scale(0.70f), "%d", int(m_iMaxScore));
		m_oFont.draw(165, 770, NFont::Scale(1.5f), "%s", "START");

		/*m_oMusic.Render();
		if (m_oMusic.Update(mousePosX, mousePosY, mouseIsPressed))
		{
			if (m_oMusic.isOn())
			{
				m_oMusic.setOn(false);
			}
			else
			{
				m_oMusic.setOn(true);
			}
		}*/

		m_oEnglishRadioButton.Render();
		m_oSpanishRadioButton.Render();
		m_oCatalanRadioButton.Render();

		m_oFont.draw(80, m_oEnglishRadioButton.getPosY(), NFont::Scale(0.75f), "%s", "English");
		m_oFont.draw(80, m_oSpanishRadioButton.getPosY(), NFont::Scale(0.75f), "%s", "Spanish");
		m_oFont.draw(80, m_oCatalanRadioButton.getPosY(), NFont::Scale(0.75f), "%s", "Catalan");

		if (m_oStartButton.Update(mousePosX, mousePosY, mouseIsPressed) && m_bCanStart)
		{
			m_eCurrentState = PLAYING; 
		}
		else
		{
			if (m_oEnglishRadioButton.Update(mousePosX, mousePosY, mouseIsPressed))
			{
				m_oEnglishRadioButton.setOn(true);
				m_oSpanishRadioButton.setOn(false);
				m_oCatalanRadioButton.setOn(false);
				m_iIdioma = 0;
				m_bCanStart = true;
			}
			if (m_oSpanishRadioButton.Update(mousePosX, mousePosY, mouseIsPressed))
			{
				m_oEnglishRadioButton.setOn(false);
				m_oSpanishRadioButton.setOn(true);
				m_oCatalanRadioButton.setOn(false);
				m_iIdioma = 2;
				m_bCanStart = true;
			}
			if (m_oCatalanRadioButton.Update(mousePosX, mousePosY, mouseIsPressed))
			{
				m_oEnglishRadioButton.setOn(false);
				m_oSpanishRadioButton.setOn(false);
				m_oCatalanRadioButton.setOn(true);
				m_iIdioma = 1;
				m_bCanStart = true;
			}
		}

		break;

	case PLAYING:

		m_oBackGround_Playing.draw(0, 0);
		m_oTimerBar.draw(125, 15);
		m_oPauseRadioButton.Render();
		m_oCheckButton.Render();
		m_oDeleteWordButton.Render();
		m_oFont_Black.draw(247, 36, NFont::Scale(0.9f), "%d", int(m_fTimer));
		m_oFont.draw(165, 770, NFont::Scale(1.5f), "%s", "CHECK");

		if(!showRanking)
			m_oRanking.Render();

		if (m_fTimer >= 103)
		{
			m_eCurrentState = WAIT_SCORE;
			tiempo = m_fTimer;
		}
		else
		{
			if (m_oPauseRadioButton.Update(mousePosX, mousePosY, mouseIsPressed))
			{
				m_eCurrentState = PAUSE;
				m_oTauler.setPause(false);
			}
			else
			{
				if (m_oDeleteWordButton.Update(mousePosX, mousePosY, mouseIsPressed))
				{
					m_oTauler.setAllWhite(true);
				}
				if (m_oCheckButton.Update(mousePosX, mousePosY, mouseIsPressed))
				{
					m_oTauler.setCheck(true);
				}
				if (m_oRanking.Update(mousePosX, mousePosY, mouseIsPressed))
				{
					if (!showRanking)
					{
						showRanking = true;
					}
					else
					{
						showRanking = false;
					}
				}
				if (showRanking)
				{
					m_oPuntuacio.setScale(0.6f);
					m_oPuntuacio.draw(8, 24);
					m_oFont_Black.draw(40, 33, NFont::Scale(0.9f), "%d", m_cPuntuacio);
				}
				if (!m_oTauler.comprovaTauler())
				{
					if (m_oTauler.getNumTiles() % 10 == 0) {
						modificaVelocitat(m_fVelocitat, m_fTimer, m_oTauler.getNumTiles());
					}
					m_oTauler.actualitzaTauler(m_fVelocitat, mousePosX, mousePosY, mouseIsPressed, m_iIdioma, m_cPuntuacio);
				}
				else
				{
					m_eCurrentState = WAIT_SCORE;
					tiempo = m_fTimer;
				}
			}
		}
		break;

	case GAME_OVER:
		if (m_fTimer > tiempo + 2)
		{
			m_eCurrentState = MAIN_MENU;
			m_oTauler.resetTauler();
			showRanking = false;
		}
		else
		{
			m_oGameOver.draw(3, 100);
		}
		break;

	case PAUSE:
		m_fTimer = m_fTimer;
		m_oBackGround_Playing.draw(0, 0);
		m_oPauseRadioButton.Render();
		m_oTimerBar.draw(125, 15);
		m_oFont_Black.draw(247, 36, NFont::Scale(0.9f), "%d", int(m_fTimer));
		m_oCheckButton.Render();
		m_oFont.draw(165, 770, NFont::Scale(1.5f), "CHECK");
		m_oDeleteWordButton.Render();

		if (!showRanking)
		{
			m_oRanking.Render();
		}
		else
		{
			m_oPuntuacio.setScale(0.6f);
			m_oPuntuacio.draw(8, 24);
			m_oFont_Black.draw(40, 33, NFont::Scale(0.9f), "%d", m_cPuntuacio);
		}
		
		if (m_oRanking.Update(mousePosX, mousePosY, mouseIsPressed))
		{
			if (!showRanking)
			{
				showRanking = true;
			}
			else
			{
				showRanking = false;
			}
		}

		if (m_oPauseRadioButton.Update(mousePosX, mousePosY, mouseIsPressed))
		{
			m_eCurrentState = PLAYING;
			m_oTauler.setPause(true);
		}
		m_oTauler.dibuixaTauler();
		m_oTauler.dibuixarLletraCaient(m_oTauler.getLletraCaient());
		break;

	case WAIT_SCORE:
		if (m_fTimer > tiempo + 5)
		{
			m_eCurrentState = GAME_OVER;
			tiempo = m_fTimer;
		}
		else
		{
			m_oBackGround_Main.draw(0, 0);

			m_oPuntuacio.setScale(1.0f);
			m_oPuntuacio.draw(145, 320);
			m_oFont_Black.draw(154, 235, NFont::Scale(1.5f), "%s", "SCORE");
			m_oFont_Black.draw(200, 334, NFont::Scale(1.5f), "%d", m_cPuntuacio);
			if (m_cPuntuacio > m_iMaxScore)
			{
				m_oFont_Black.draw(156, 420, NFont::Scale(0.75f), "%s", "New Max Score!");
				m_oFont_Black.draw(260, 450, NFont::Scale(0.75f), "%d", m_cPuntuacio);
				setMaxScore(m_cPuntuacio);
			}
		}
		break;

	case NONE:
		break;
	}
	//end of switch
}

void LetrisGame::modificaVelocitat(float velocitat, float timer, int nTiles) 
{
	m_fVelocitat = m_fVelocitatInicial + nTiles * 0.01;
	if (m_fVelocitat > 1)
		m_fVelocitat = 1;
}

void LetrisGame::getMaxScore()
{
	ifstream maxScore;
	maxScore.open("./data/Scores/MaxScore.txt");
	if (maxScore.is_open())
	{
		int n;
		maxScore >> n;
		if (n >= 0)
		{
			m_iMaxScore = n;
		}
		else
		{
			m_iMaxScore = 0;
		}
		maxScore.close();
	}
}

void LetrisGame::setMaxScore(int n)
{
	ofstream maxScore;
	maxScore.open("./data/Scores/MaxScore.txt");
	if (maxScore.is_open())
	{
		maxScore << n;
		maxScore.close();
	}
}

