#include "CardSix.h"
#include"Ladder.h"
#include"Snake.h"
CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int DiceValue = pPlayer->GetjustRolledDiceNum();
	pPlayer->Move(pGrid, (DiceValue* -1));
}
CardSix::~CardSix()
{

}