#pragma once
#include"Action.h"
class DeleteObjectAction:public Action
{
private:
CellPosition startPos;
public:
	DeleteObjectAction(ApplicationManager* pApp);
	~DeleteObjectAction();
	bool ReadActionParameters();
	void Execute();

};

