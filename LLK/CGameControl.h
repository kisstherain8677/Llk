#pragma once

#include "global.h"
#include "CGraph.h"
class CGameControl
{
public:
	CGameControl();
	~CGameControl();
	virtual int GetGrade();
	virtual void SetGrade(int i);
	virtual void StartGame() = 0;
	int GetElement(int nRow, int nCol);//����ָ������Ԫ��
	void SetFirstPoint(int nRow, int nCol);//���õ�һ�����к��к�
	void SetSecPoint(int nRow, int nCol);//���õڶ���������к�
	bool Link(int avPath[MAX_VERTEX_NUM],int &nVertex);//�ж��Ƿ����ͨ���������ͨ��ͨ��������������·��������
	virtual int isWin(int time);//�ж�ͼ�ж����Ƿ�Ϊ�գ����Ϊ�գ�����ͼ�ṹ������true
	virtual bool Help(int avPath[MAX_VERTEX_NUM], int &nVexNum);
	virtual void ResetGraph();
	void SetFlag(Flag flag);
	Flag GetFlag();
	virtual bool PropLink();
protected:
	int m_nGrade;

	CGraph m_graph;//��һ��ͼ�ṹ�����ͼ
	Vertex m_ptSelFirst;//��һ��ѡ�е�
	Vertex m_ptSelSec;//�ڶ���ѡ�еĵ�
	Flag m_flag;
};

