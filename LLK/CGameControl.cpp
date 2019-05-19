#include "stdafx.h"
#include "CGameLogic.h"
#include "CGameControl.h"


CGameControl::CGameControl()
{
}


CGameControl::~CGameControl()
{
}

void CGameControl::StartGame()
{
	CGameLogic gameLogic;
	gameLogic.InitMap(m_anMap);
}

int CGameControl::GetElement(int nRow, int nCol)
{
	return m_anMap[nRow][nCol];
}

void CGameControl::SetFirstPoint(int nRow, int nCol)
{
	m_ptSelFirst.row = nRow;
	m_ptSelFirst.col = nCol;
}

void CGameControl::SetSecPoint(int nRow, int nCol)
{
	m_ptSelSec.col = nCol;
	m_ptSelSec.row = nRow;
}

bool CGameControl::Link(Vertex avPath[4], int &nVertex)
{   //�ж��Ƿ�Ϊͬһ��ͼƬ
	if (m_ptSelFirst.col == m_ptSelSec.col&&m_ptSelFirst.row == m_ptSelSec.row) {
		return false;
	}
	//�ж�ͼƬ�Ƿ���ͬ
	if (m_anMap[m_ptSelFirst.row][m_ptSelFirst.col] != m_anMap[m_ptSelSec.row][m_ptSelSec.col]) {
		return false;
	}
	CGameLogic gameLogic;
	
	if (!gameLogic.IsLink(m_anMap, m_ptSelFirst, m_ptSelSec)){
		return false;
	}
	gameLogic.Clear(m_anMap, m_ptSelFirst, m_ptSelSec);
	//��ȡ·�����Լ�·���ж���ĸ���
	nVertex = gameLogic.GetVexPath(avPath);
	return true;
}


