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
	
	

protected:

	//������ͨ·���Ķ�������
	int m_anPath[16];
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

	

	//IsLink�ĸ�������
	bool LinkInRow(int anMap[][4], Vertex v1, Vertex v2);//������ͨ�ж�
	bool LinkInCol(int anMap[][4], Vertex v1, Vertex v2);//������ͨ�ж�
	bool OneCornorLink(int anMap[][4], Vertex v1, Vertex v2);//һ���յ���ͨ�ж�
	bool TwoCornorLink(int anMap[][4], Vertex v1, Vertex v2);//�����յ���ͨ�ж�
	bool LineY(int anMap[][4], int nRow1, int nRow2, int nCol);//ֱ����ͨY��
	bool LineX(int anMap[][4], int nRow, int nCol1, int nCol2);//ֱ����ͨX��

};

