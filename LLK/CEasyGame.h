#pragma once
#include "CGameControl.h"
#include "CGameLogic.h"
class CEasyGame :
	public CGameControl
{
public:
	virtual void StartGame();
	//virtual int isWin(int time);//�ж�ͼ�ж����Ƿ�Ϊ�գ����Ϊ�գ�����ͼ�ṹ������true
	//virtual bool Help(int avPath[MAX_VERTEX_NUM], int &nVexNum);
	//virtual void ResetGraph();
	virtual bool PropLink();
	CEasyGame();
	~CEasyGame();

	
};

