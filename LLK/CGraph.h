#pragma once
#include "global.h"
class CGraph
{
public:
	CGraph();
	~CGraph();

	int AddVertex(int info);//����һ������
	void AddArc(int nV1Index, int nV2Index);//����һ����
	int GetVertex(int nIndex);//��ȡ��������ΪnIndex��Ԫ��
	int GetVexNum();//��ȡ���������еĶ�����
	int GetArcNum();//��ȡ����
	void UpdateVertex(int nIndex, int info);//��ͼ��������ΪnIndex��Ԫ�ظ���Ϊinfo
	bool GetArc(int v1, int v2);//�����������ر�
	void ClearGraph();//��ͼ�ж���ͱ߻�ԭΪ��ʼ״̬
	void SetVertex(int index, int val);
protected:

typedef int Vertices[MAX_VERTEX_NUM];
typedef bool AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

Vertices m_Vertices;//��������
AdjMatrix m_AdjMatrix;//�ڽӾ���
int m_VexNum;//������
int m_nArcNum;//����


void InitGraph();


};

