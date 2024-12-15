#include "SwitchToPlayModeAction.h"
#include "Grid.h"
#include "Player.h"
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
}

bool SwitchToPlayModeAction::ReadActionParameters()
{
	return 1;
}

void SwitchToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->GetOutput()->CreatePlayModeToolBar();
	CellPosition start(1);
	for (int i = 0; i < 4; i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->SetWallet(100);
		pPlayer->SetTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetCurrentPlayer(0);
}