#include "ExitAction.h"
#include "Grid.h"

ExitAction::ExitAction(ApplicationManager* pApp): Action(pApp)
{
}

ExitAction::~ExitAction()
{
}

bool ExitAction::ReadActionParameters()
{
	return 1;
}

void ExitAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->PrintErrorMessage("Game Exit, Click anywhere to continue...");
	pGrid->SetEndGame(1);

}