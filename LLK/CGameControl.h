#pragma once

#include "global.h"
#include "CGraph.h"
class CGameControl
{
public:
	CGameControl();
	~CGameControl();

	void StartGame();
	int GetElement(int nRow, int nCol);//����ָ������Ԫ��
	void SetFirstPoint(int nRow, int nCol);//���õ�һ�����к��к�
	void SetSecPoint(int nRow, int nCol);//���õڶ���������к�
	bool Link(int avPath[16],int &nVertex);//�ж��Ƿ����ͨ���������ͨ��ͨ��������������·��������
	
protected:
	CGraph m_graph;//��һ��ͼ�ṹ�����ͼ
	Vertex m_ptSelFirst;//��һ��ѡ�е�
	Vertex m_ptSelSec;//�ڶ���ѡ�еĵ�
};

