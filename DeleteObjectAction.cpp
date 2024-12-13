#include "DeleteObjectAction.h"

#include"input.h"
#include"output.h"
#include"Grid.h"			//CHECK HOW TO AVOID THIS LATER
DeleteObjectAction::DeleteObjectAction(ApplicationManager* pApp):Action(pApp)
{ }
DeleteObjectAction::~DeleteObjectAction()
{	}
bool DeleteObjectAction::ReadActionParameters()
{
	pManager->SetUpdateCond(true); //this function reset the state of updating to true for more optimization
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	startPos = pIn->GetCellClicked();
	if (startPos.VCell() == -1 || startPos.HCell() == -1)
	{
		pOut->PrintMessage("Please, click in the Grid Area on a Cell to select the cell you want!");
		pManager->SetUpdateCond(false);
		return false;
	}

	return true;
}
void DeleteObjectAction::Execute()
{	
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool removed = pGrid->RemoveObjectFromCell(startPos);
		
		if (!removed)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("The Cell you chose doesn't have any object! Click to continue ..."); 
			pManager->SetUpdateCond(false);
		}

	}
}
