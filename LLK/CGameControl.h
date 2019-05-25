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
	bool Link(int avPath[MAX_VERTEX_NUM],int &nVertex);//�ж��Ƿ����ͨ���������ͨ��ͨ��������������·��������
	int isWin(int time);//�ж�ͼ�ж����Ƿ�Ϊ�գ����Ϊ�գ�����ͼ�ṹ������true
	bool Help(int avPath[MAX_VERTEX_NUM], int &nVexNum);
	void ResetGraph();
	void SetFlag(Flag flag);
	Flag GetFlag();
protected:
	CGraph m_graph;//��һ��ͼ�ṹ�����ͼ
	Vertex m_ptSelFirst;//��һ��ѡ�е�
	Vertex m_ptSelSec;//�ڶ���ѡ�еĵ�
	Flag m_flag;
};

