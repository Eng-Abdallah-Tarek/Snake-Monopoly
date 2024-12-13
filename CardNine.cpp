#include "CardNine.h"
CardNine::CardNine(const CellPosition& cardpostion,const CellPosition& PostitionMovedTo):Card(cardpostion)
{
	moveto = PostitionMovedTo;
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{ 
	int dicevalue = moveto.GetCellNum() - position.GetCellNum() ;
	pPlayer->Move(pGrid, dicevalue);
}
CardNine::~CardNine()
{ }
