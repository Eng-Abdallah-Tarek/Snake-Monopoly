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
	pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);   //Turn count isn't considered with this motion by 1 !
	pPlayer->Move(pGrid, (DiceValue* -1));
}

void CardSix::Save(ofstream& file)
{
	Card::Save(file);
	file << '\n';
}
CardSix::~CardSix()
{

}