#pragma once

#include "global.h"
#include "CGraph.h"

class CGameLogic
{
public:
	CGameLogic();
	~CGameLogic();

	void InitMap(CGraph &graph);
	bool IsLink(CGraph &graph, Vertex v1, Vertex v2);//�ж�v1v2�Ƿ���ͨ

	int GetVexPath(int avPath[]);//�õ�·��axPath����ͨ���������ظ����ú���������ֵΪ������
	void Clear(CGraph &g, Vertex v1, Vertex v2);
	bool isBlank(CGraph &g);//�ж�g�ж����Ƿ�Ϊ��
	bool SearchValidPath(CGraph &g);
	int GetPathNum();
	int GetPathIn(int index);//����path������Ϊindex��ֵ��������������-1
	void ResetGraph(CGraph &g);
protected:

	//������ͨ·���Ķ�������
	int m_anPath[MAX_VERTEX_NUM];
	//��ͨ·���������
	int m_nVexNum;
	//��ͨ·������m_anPath�еĹյ���
	int m_nCorner;

	//��������������ж϶���V0��V1��ͼ���Ƿ���ͨ
	bool SearchPathDFS(CGraph &g, int v0,int v1);
	//�ж�����ΪnVi�Ķ����Ƿ񱣴浽��ͨ����m_anPath�� 
	bool isExsit(int nVi);
	//�ж�����·������m_anPath�У��������������Ƿ񹹳�һ���յ�
	bool IsCorner();


	void PushVertex(int nV);//���һ��·�����㵽m_anPath�����ж�ѹ����Ƿ��γ�һ���յ㣬����ǹյ㣬��յ�������һ

	void PopVertex();//pop��һ������
	//�ж�nRow�У�nCol�еĶ��������������ҵĶ����Ƿ��бߣ�����бߣ�����ͼ�ṹ
	void UpdateArc(CGraph &g, int nRow, int nCol);

	

	
};

