#include "CardSeven.h"
#include "RollDiceAction.h"
#include "Player.h"
CardSeven::CardSeven(const CellPosition& pos): Card(pos)
{
	cardNumber = 7;
}

CardSeven::~CardSeven() 
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Card 7: You get a second turn! Click to continue...");
	pGrid->SetCurrentPlayer(pGrid->GetCurrentPlayerNum() - 1);
}
