#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	int DiceValue = pPlayer->GetjustRolledDiceNum();
	pPlayer->Move(pGrid, (DiceValue* -1));

}
CardSix::~CardSix()
{

}