#include "SwitcToDesignModeAction.h"
#include "Grid.h"
SwitcToDesignModeAction::SwitcToDesignModeAction(ApplicationManager*pApp): Action(pApp)
{
}

SwitcToDesignModeAction::~SwitcToDesignModeAction()
{
}

bool SwitcToDesignModeAction::ReadActionParameters()
{
	return 1;
}

void SwitcToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->GetOutput()->CreateDesignModeToolBar();
	CellPosition start(1);
	for (int i = 0; i < 4; i++)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pGrid->AdvanceCurrentPlayer();
	}

}
