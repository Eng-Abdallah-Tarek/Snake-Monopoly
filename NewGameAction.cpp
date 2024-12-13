#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
NewGameAction::NewGameAction(ApplicationManager* pApp): Action(pApp)
{
}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	CellPosition start(1);
	for(int i=0; i<4; i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->SetWallet(100);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->ChangeCurrentPlayer(0);
	

}