#include "Snake.h"
#include "Player.h"
#include "Ladder.h"
int Snake::count = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() < endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}
	count++;
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

int Snake::getCount()
{
	return count;
}

bool Snake::IsOverlapping(GameObject* ObjectComparedWith, Grid* pGrid)const
{
	int start2 = position.VCell()
		, end2 = endCellPos.VCell();

	if (Snake* pSnake = dynamic_cast<Snake*>(ObjectComparedWith))
	{
			int start1 = (pSnake->GetPosition()).VCell()
			, end1 = (pSnake->GetEndPosition()).VCell();
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
	else if (Ladder* pLadder=dynamic_cast<Ladder*>(ObjectComparedWith))
	{
		int start1 = (pLadder->GetPosition()).VCell()
			, end1 = (pLadder->GetEndPosition()).VCell();

		if (start1 == end2)
		{
			pGrid->PrintErrorMessage("The Start of a Ladder can't be Snake's Tail  , Click to continue ...");
			return true;
		}
		else if (start2 == end1)
		{
			pGrid->PrintErrorMessage("The End of a Ladder can't be the Head of a Snake , Click to continue ...");
			return true;
		}
		else
			return false;  // The Snake Head isn't the Ladder's End
	}					   // Snake's Tail isn't the Ladder's start

	else                   // if the ObjectComparedWith is NULL (this isn't the case of testing OverLapping) 
		return false;

}


void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");
	//pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);			//I don't want ladders' motion to be counted as a turn so we decrement it
	pPlayer->Move(pGrid, (endCellPos.GetCellNum() - position.GetCellNum()));	// This includes checking if the ladder made you reach the last cell and ended game or not 
	// and this also checks if the ladder end has any cards

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& file)
{

	file << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << '\n';
}

Snake::~Snake()
{
	count--;
}