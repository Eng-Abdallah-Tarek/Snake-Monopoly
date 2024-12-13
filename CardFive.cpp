#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos):Card(pos)
{
	cardNumber = 5;
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	int DiceValue =pPlayer->GetjustRolledDiceNum();
	pPlayer->Move(pGrid, DiceValue);

}
CardFive::~CardFive()
{

}