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
	pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);   //Turn count isn't considered with this motion by 1 !
	pPlayer->Move(pGrid, DiceValue);
}

void CardFive::Save(ofstream& file)
{
	Card::Save(file);
	file << '\n';
}

CardFive::~CardFive()
{

}