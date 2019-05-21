#include "stdafx.h"
#include "CGameLogic.h"


CGameLogic::CGameLogic()
{
	m_nVexNum = 0;
	m_nCorner = 0;
}


CGameLogic::~CGameLogic()
{
}

//��ʼ����Ϸ��ͼ�Ķ�ά����
void CGameLogic::InitMap(CGraph &graph)
{


	//������ɵ�ͼ
	int anTemp[MAX_VERTEX_NUM];
	//���ٻ�ɫ
	for (int i = 0; i < MAX_PIC_NUM; i++) {
		//�ظ���
		for (int j = 0; j < REPEAT_NUM; j++) {
			anTemp[i*REPEAT_NUM + j] = i;
		}
	}
	//��������
	srand((int)time(NULL));

	//������⽻��������
	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		//����õ���������
		int nIndex1 = rand() % MAX_VERTEX_NUM;
		int nIndex2 = rand() % MAX_VERTEX_NUM;
		//����������ֵ
		int temp = anTemp[nIndex1];
		anTemp[nIndex1] = anTemp[nIndex2];
		anTemp[nIndex2] = temp;
	}

	for (int i = 0; i < MAX_VERTEX_NUM; i++) {
		
			graph.AddVertex(anTemp[i]);
		
	}
	//����ͼ��Ϣ
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			UpdateArc(graph, i, j);
		}
	}

}

//�ж�����ͼ�Ƿ��������
bool CGameLogic::IsLink(CGraph &g, Vertex v1, Vertex v2)
{
	//��ȡ����������
	int nV1Index = v1.row * MAX_COL + v1.col;
	int nV2Index = v2.row * MAX_COL + v2.col;
	//ѹ���һ����
	PushVertex(nV1Index);
	//�ж��������Ƿ�������ͨ
	if (g.GetArc(nV1Index, nV2Index)) {
		PushVertex(nV2Index);
		return true;
	}
	if (SearchPathDFS(g, nV1Index, nV2Index)) {
		return true;
	}
	//PopVertex();
	return false;
}

int CGameLogic::GetVexPath(int avPath[])
{
	for (int i = 0; i < m_nVexNum; i++) {
		avPath[i] = m_anPath[i];
	}
	return m_nVexNum;
}

void CGameLogic::Clear(CGraph &g, Vertex v1, Vertex v2)
{
	//��ȡ��������
	int index1 = v1.row * MAX_COL + v1.col;
	int index2 = v2.row * MAX_COL + v2.col;
	//���¶���
	g.UpdateVertex(index1, BLANK);
	g.UpdateVertex(index2, BLANK);
	//���±�����
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			UpdateArc(g, i, j);
		}
	}
	
}

bool CGameLogic::isBlank(CGraph & g)
{
	int vn = g.GetVexNum();
	for (int i = 0; i < vn; i++) {
		if (g.GetVertex(i) != BLANK)
			return false;
	}
	return true;
}

bool CGameLogic::SearchValidPath(CGraph & g)
{
	//�ҵ���һ����Ϊ�յĵ�V1
	int index1;
	int index2;
	for (int i = 0; i < g.GetVexNum(); i++) {
		if (g.GetVertex(i) != BLANK) {
			index1 = i;
			for (int j = 0; j < g.GetVexNum(); j++) {
				if (i != j) {
					if (g.GetVertex(index1) == g.GetVertex(j)) {
						PushVertex(index1);
						if (SearchPathDFS(g, index1, j)) {
							return true;
						}
						PopVertex();
					}

				}
			}
		}
		
	}

	return false;
}

int CGameLogic::GetPathNum()
{
	return m_nVexNum;
}

int CGameLogic::GetPathIn(int index)
{
	if (index < m_nVexNum) {
		return m_anPath[index];
	}
	return -1;
}

void CGameLogic::ResetGraph(CGraph & g)
{
	for (int i = 0; i < 100; i++) {
		int index1 = rand() % MAX_VERTEX_NUM;
		int index2 = rand() % MAX_VERTEX_NUM;
		int temp = g.GetVertex(index1);
		g.SetVertex(index1, g.GetVertex(index2));
		g.SetVertex(index2, temp);
	}
	//����ͼ��Ϣ���ߵĹ�ϵ��
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			UpdateArc(g, i, j);
		}
	}
}

void CGameLogic::UpdateArc(CGraph & g, int nRow, int nCol)
{
	int nV1Index = nRow * MAX_COL + nCol;
	if (nCol > 0) {
		int nV2Index = nV1Index - 1;
		if (g.GetVertex(nV2Index) == g.GetVertex(nV1Index)||g.GetVertex(nV1Index)==BLANK||g.GetVertex(nV2Index)==BLANK) {
			g.AddArc(nV1Index, nV2Index);
		}
	}
	if (nCol < MAX_COL-1) {
		int nV2Index = nV1Index + 1;
		if (g.GetVertex(nV2Index) == g.GetVertex(nV1Index) || g.GetVertex(nV1Index) == BLANK || g.GetVertex(nV2Index) == BLANK) {
			g.AddArc(nV1Index, nV2Index);
		}
	}
	if (nRow > 0) {
		int nV2Index = nV1Index - MAX_COL;
		if (g.GetVertex(nV2Index) == g.GetVertex(nV1Index) || g.GetVertex(nV1Index) == BLANK || g.GetVertex(nV2Index) == BLANK) {
			g.AddArc(nV1Index, nV2Index);
		}
	}
	if (nRow < MAX_ROW-1) {
		int nV2Index = nV1Index + MAX_COL;
		if (g.GetVertex(nV2Index) == g.GetVertex(nV1Index) || g.GetVertex(nV1Index) == BLANK || g.GetVertex(nV2Index) == BLANK) {
			g.AddArc(nV1Index, nV2Index);
		}
	}
}

bool CGameLogic::SearchPathDFS(CGraph & g, int v0, int v1)
{
	//�õ�������
	int nVexnum = g.GetVexNum();
	//����ͼ��nV0�У���0��nVexnum��ֵΪtrue�ĵ�
	for (int vi = 0; vi < nVexnum; vi++) {
		if (g.GetArc(v0, vi) && !isExsit(vi)) {
			PushVertex(vi);
			if (m_nCorner > 2) {
				PopVertex();
				continue;
			}

			//���м䶥�㲻��v1ʱ������������һ����������ͨ�ĵ�
			if (vi != v1) {
				//���м䶥�㲻Ϊ��ʱ����ʾ·������ͨ
				if (g.GetVertex(vi) != BLANK) {
					PopVertex();
					continue;
				}
				//���vi��һ���������ĵ㣬�ж�(vi v1)
				if (SearchPathDFS(g, vi, v1)) {
					return true;
					//��ʾ�Ѿ��ҵ���һ����ͨ·��������true
				}
			}
			else {//���vi=v1��ʾ�Ѿ��ҵ���һ����ͨ·��������true
				return true;
			}
			PopVertex();
		}
	}
	return false;
}

bool CGameLogic::isExsit(int nVi)
{
	for (int i = 0; i < m_nVexNum; i++) {
		if (m_anPath[i] == nVi) {
			return true;
		}
	}
	return false;
}

bool CGameLogic::IsCorner()
{
	if (m_nVexNum >= 3) {
		if ((m_anPath[m_nVexNum - 1] + m_anPath[m_nVexNum - 3]) / 2 != m_anPath[m_nVexNum - 2]) {
			
			return true;
		}
	}
	return false;
}

void CGameLogic::PushVertex(int nV )
{
	m_anPath[m_nVexNum++] = nV;
	if (IsCorner()) {
		m_nCorner++;
	}
}

void CGameLogic::PopVertex()
{
	if (IsCorner()) {
		m_nCorner--;
	}
	m_nVexNum--;
}

