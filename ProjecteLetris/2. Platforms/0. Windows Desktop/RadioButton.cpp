#include "RadioButton.h"

RadioButton::RadioButton(const string& path_normal, const string& path_pressed, int posX, int posY, int width, int height)
{
	m_oOff.create(path_normal.c_str());
	m_oOn.create(path_pressed.c_str());
	m_iPosX = posX;
	m_iPosY = posY;
	m_iWidth = width;
	m_iHeight = height;
	m_bIsOn = false;
	m_eCurrentState = NORMAL;
}

RadioButton::RadioButton()
{
}

RadioButton::~RadioButton()
{

}

bool RadioButton::Update(int mousePosX, int mousePosY, bool mouseIsPressed)
{
	bool l_bDoAction = false;
	if (mousePosX >= m_iPosX && mousePosX <= m_iPosX + m_iWidth && mousePosY >= m_iPosY && mousePosY <= m_iPosY + m_iHeight)
	{
		if (mouseIsPressed && m_eCurrentState != PRESSED)
		{
			m_eCurrentState = PRESSED;
			l_bDoAction = true;
		}
		else
		{
			if (mouseIsPressed && m_eCurrentState == PRESSED)
			{
				m_eCurrentState = NORMAL;
				l_bDoAction = true;
			}
		}
	}
	return l_bDoAction;
}

void RadioButton::Render()
{
	switch (m_eCurrentState)
	{
	case NORMAL:
		m_oOff.draw(m_iPosX, m_iPosY);
		break;
	case PRESSED:
		m_oOn.draw(m_iPosX, m_iPosY);
		break;
	case NONE:
		//Nothing to do
		break;
	}
}

void RadioButton::setOn(bool isOn)
{
	m_bIsOn = isOn;
	if (isOn)
	{
		m_eCurrentState = PRESSED;
	}
	else
	{
		if (!isOn)
		{
			m_eCurrentState = NORMAL;
		}
	}
}

bool RadioButton::isOn() const
{
	return m_bIsOn;
}