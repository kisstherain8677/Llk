#pragma once

#include "global.h"

class CGameLogic
{
public:
	CGameLogic();
	~CGameLogic();

	void InitMap(int anMap[][4]);
	bool IsLink(int anMap[][4], Vertex v1, Vertex v2);//�ж�v1v2�Ƿ���ͨ

	int GetVexPath(Vertex avPath[4]);//�õ�·��axPath����ͨ���������ظ����ú���������ֵΪ������
	void Clear(int anMap[][4], Vertex v1, Vertex v2);

	

protected:
	Vertex m_avPath[4];//�����ڽ�������ʱ�������ĵ�
	int m_nVexNum;//�����m_avPath�еĶ�����

	void PushVertex(Vertex v);//���һ��·������
	void PopVertex();//pop��һ������

	//IsLink�ĸ�������
	bool LinkInRow(int anMap[][4], Vertex v1, Vertex v2);//������ͨ�ж�
	bool LinkInCol(int anMap[][4], Vertex v1, Vertex v2);//������ͨ�ж�
	bool OneCornorLink(int anMap[][4], Vertex v1, Vertex v2);//һ���յ���ͨ�ж�
	bool TwoCornorLink(int anMap[][4], Vertex v1, Vertex v2);//�����յ���ͨ�ж�
	bool LineY(int anMap[][4], int nRow1, int nRow2, int nCol);//ֱ����ͨY��
	bool LineX(int anMap[][4], int nRow, int nCol1, int nCol2);//ֱ����ͨX��

};

