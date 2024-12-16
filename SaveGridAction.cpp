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
	pOut->PrintMessage("Enter the name of the file to save to: ");
	FileName = pGrid->GetInput()->GetSrting(pOut)+".txt";
	return 1;
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	ofstream file(FileName);
	pManager->GetGrid()->SaveAll(file);
}