#include "ExitAction.h"
#include "Grid.h"

ExitAction::ExitAction(ApplicationManager* pApp): Action(pApp)
{
}

ExitAction::~ExitAction()
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	pManager->GetGrid()->PrintErrorMessage("Game Exit, Click anywhere to continue...");
}