#include "Ladder.h"
int Ladder::count = 0;
#include"Snake.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if(startCellPos.HCell()==endCellPos.HCell() && startCellPos.VCell() > endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}

	count++;
	///TODO: Do the needed validation
}

int Ladder::getCount()
{
	return count;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
}
bool Ladder::IsOverlapping(GameObject* ObjectComparedWith , Grid* pGrid) const	
{
	/*
	1 ==> is the first thing drawn which might be snake , ladder , card or none
	2 ==> is the second thing drawn which is Ladder 
 
	*/
	int start2 = position.VCell()
		, end2 = endCellPos.VCell();

	if (Ladder* pLadder = dynamic_cast<Ladder*>(ObjectComparedWith))
	{
		int start1 = (pLadder->GetPosition()).VCell()
			, end1 = (pLadder->GetEndPosition()).VCell();

		if (start2 < end1)
			return false;
		else if (end2 > start1)
			return false;
		else if (end1 == start2)
		{
			pGrid->PrintErrorMessage("The End of a Ladder can't be the Start of another Ladder , Click to continue ...");
			return true;
		}
		else if (end2 == start1)
		{
			pGrid->PrintErrorMessage("The Start of a Ladder can't be the End of another Ladder , Click to continue ...");
			return true;
		}
		else
		{
			pGrid->PrintErrorMessage("Two Ladders Can't Overlap , Click to continue ...");
			return true;
		}
	}
	else if (Snake* pSnake = dynamic_cast<Snake*>(ObjectComparedWith))
	{
		int start1 = (pSnake->GetPosition()).VCell()
			, end1 = (pSnake->GetEndPosition()).VCell();

		if (start1 == end2)
		{
			pGrid->PrintErrorMessage("The Head of a Snake can't be The End of a Ladder , Click to continue ...");
			return true;
		}
		else if (start2 == end1)
		{
			pGrid->PrintErrorMessage("Snake's Tail can't be the Start of a Ladder , Click to continue ...");
			return true;
		}
		else
			return false;  // The Snake Head isn't the Ladder's End 
	}					   // Snake's Tail isn't the Ladder's start 
	else
		return false; // if the ObjectComparedWith is NULL (this isn't the case of testing OverLapping) 
		
}


CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save (ofstream& file)
{

	file << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << '\n';
}

Ladder::~Ladder()
{
	count--;
}
