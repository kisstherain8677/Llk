#include "stdafx.h"
#include "CEasyGame.h"


void CEasyGame::StartGame()
{
	CGameLogic gameLogic;
	gameLogic.InitMap(m_graph);
}

bool CEasyGame::PropLink()//�õ��� ֱ������
{
	//�ж��Ƿ�Ϊͬһλ��
	if (m_ptSelFirst.col == m_ptSelSec.col&&m_ptSelFirst.row == m_ptSelSec.row) {
		return false;
	}
	
	
	CGameLogic gameLogic;

	gameLogic.Clear(m_graph, m_ptSelFirst, m_ptSelSec);
	//��ȡ·�����Լ�·���ж���ĸ���
	return true;
}

CEasyGame::CEasyGame()
{
}


CEasyGame::~CEasyGame()
{
}


