#include "CardFour.h"
#include "Snake.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}
CardFour::~CardFour(void)
{
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Cell* cell = pPlayer->GetCell();
	const  CellPosition c1 = cell->GetCellPosition();
	//Snake* s = pGrid->GetNextSnake(c1);                      // must first added from them
	//((GameObject*)s)->GetPosition();
	//if (s)
	//{
	// //const  CellPosition c2 = s->GetPosition();
	//	int n2 = c2.GetCellNum();
	//	int n1 = c1.GetCellNum();
	//	pPlayer->Move(pGrid, n2 - n1);
	// 
	//}
}
