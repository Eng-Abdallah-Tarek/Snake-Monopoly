#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp):Action(pApp)
{
}


SaveGridAction::~SaveGridAction()
{
}

bool SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the name of the txt file to save to: ");
	FileName = pGrid->GetInput()->GetSrting(pOut)+".txt";
	pOut->ClearStatusBar();
	return 1;
}

void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	ofstream file(FileName);
	pGrid->SaveAll(file);
	file.close();
	pGrid->PrintErrorMessage("Saved! Click to continue...");
}