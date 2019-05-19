#pragma once

#include "global.h"
class CGameControl
{
public:
	CGameControl();
	~CGameControl();

	void StartGame();
	int GetElement(int nRow, int nCol);//����ָ������Ԫ��
	void SetFirstPoint(int nRow, int nCol);//���õ�һ�����к��к�
	void SetSecPoint(int nRow, int nCol);//���õڶ���������к�
	bool Link(Vertex avPath[2]);

private:
	int m_anMap[4][4];//�������е�ͼ
	Vertex m_ptSelFirst;//��һ��ѡ�е�
	Vertex m_ptSelSec;//�ڶ���ѡ�еĵ�
};

