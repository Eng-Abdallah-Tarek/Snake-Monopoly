#include "AddSnakeAction.h"


#include "Input.h"
#include "Output.h"
#include"Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp):Action(pApp)
{
}
AddSnakeAction::~AddSnakeAction()
{
}
bool AddSnakeAction::ReadActionParameters() 
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pManager->SetUpdateCond(true); //this function reset the state of updating to true for more optimization

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (startPos.VCell() == -1 || startPos.HCell() == -1)
	{
		pOut->PrintMessage("Please, click in the Grid Area on a Cell to select the cell you want!");
		pManager->SetUpdateCond(false);
		return false;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (endPos.VCell() == -1 || endPos.HCell() == -1)
	{
		pOut->PrintMessage("Adding Snake is Cancelled! Please, click in the Grid Area on the Cells to select the Cell you want!");
		pManager->SetUpdateCond(false);
		return false;
	}

	else if (startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("Adding Snake is Cancelled! The Snake must be Vertical!");
		pManager->SetUpdateCond(false);
		return false;
	}

	else if (startPos.VCell() > endPos.VCell())
	{
		pOut->PrintMessage("Adding Snake is Cancelled! The Snake must be drawn from top to bottom!");
		pManager->SetUpdateCond(false);
		return false;
	}
	else if (startPos.VCell() == endPos.VCell()) //if it is the same cell nothing will be drawn!
	{
		pOut->PrintMessage("Adding Snake is Cancelled! The start Cell and End cell can't be the same Cell!");
		pManager->SetUpdateCond(false);
		return false;
	}
	// Clear messages
	pOut->ClearStatusBar();
	return true;
	
}
void AddSnakeAction::Execute() 
{
	ReadActionParameters();
	/*
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	if (ReadActionParameters())
	{
		// Create a Snake object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error:The First Cell already has an Object ! Click to continue ..."); //i added the word The First Cell
			pManager->SetUpdateCond(false);
		}
		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	}
	*/
}
