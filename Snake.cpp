#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() < endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

bool Snake::IsOverlapping(GameObject* ObjectComparedWith, Grid* pGrid)const
{
	Snake* pLadder = dynamic_cast<Snake*>(ObjectComparedWith);
	if (pLadder)
	{
		int start2 = position.VCell()
			, end2 = endCellPos.VCell()
			, start1 = (pLadder->GetPosition()).VCell()
			, end1 = (pLadder->GetEndPosition()).VCell();
		if (start2 > end1)
			return false;
		else if (end2 < start1)
			return false;
		else if (end1 == start2)
		{
			pGrid->PrintErrorMessage("The End of a Snake can't be the Start of another Snake , Click to continue ...");
			return true;
		}
		else if (end2 == start1)
		{
			pGrid->PrintErrorMessage("The Start of a Snake can't be the End of another Snake , Click to continue ...");
			return true;
		}
		else
		{
			pGrid->PrintErrorMessage("Two Snakes Can't Overlap , Click to continue ...");
			return true;
		}
	}

	else                   // if the ObjectComparedWith is NULL (this isn't the case of testing OverLapping) 
		return false;

}


void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}