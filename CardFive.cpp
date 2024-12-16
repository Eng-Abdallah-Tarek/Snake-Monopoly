#include "CardFive.h"
#include"Ladder.h"
#include"Snake.h"
CardFive::CardFive(const CellPosition& pos):Card(pos)
{
	cardNumber = 5;
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int DiceValue =pPlayer->GetjustRolledDiceNum();
	pPlayer->Move(pGrid, DiceValue);
}

CardFive::~CardFive()
{

}