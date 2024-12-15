#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
NewGameAction::NewGameAction(ApplicationManager* pApp): Action(pApp)
{
}

NewGameAction::~NewGameAction()
{
}

bool NewGameAction::ReadActionParameters()
{
	return 1;
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	CellPosition start(1);
	Player* pPlayer;
	for (int i = 0; i < 4; i++)
	{
		pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->SetWallet(100);
		pPlayer->SetTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrentPlayer(0);
	CardTen::RemoveOwner();
	CardEleven::RemoveOwner();
	CardTwelve::RemoveOwner();
	CardThirteen::RemoveOwner();
}