#include "CardThree.h"
#include "Ladder.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (7z here)
}
CardThree::~CardThree(void)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
  
	Cell* cell = pPlayer->GetCell();
	const  CellPosition c1 = cell->GetCellPosition();
	Ladder* l = pGrid->GetNextLadder(c1);
	       //((GameObject*)l)->GetPosition();
	if (l)
	{
		const  CellPosition c2 = l->GetPosition();
		int n2 = c2.GetCellNum();
		int n1 = c1.GetCellNum();
		pPlayer->Move(pGrid, n2 - n1);
		
	}
}
