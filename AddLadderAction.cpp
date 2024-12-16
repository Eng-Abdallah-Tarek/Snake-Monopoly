#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

bool AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (startPos.VCell() == -1 || startPos.HCell() == -1)
	{
		pGrid->PrintErrorMessage("Adding Ladder is Cancelled : You didn't click on a cell ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}
	else if (startPos.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("Adding Ladder is Cancelled : Ladder can't start at the First Cell ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}
	else if (startPos.VCell() == 0)
	{
		pGrid->PrintErrorMessage("Adding Ladder is Cancelled : Ladder can't start at the Last Row ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	///TODO: Make the needed validations on the read parameters
	if (endPos.VCell() == -1 || endPos.HCell() == -1)
	{
		pGrid->PrintErrorMessage("Adding Ladder is Cancelled : You didn't click on a cell ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}

	else if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Ladder is Cancelled! The Ladder must be Vertical ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}
	else if(startPos.VCell() < endPos.VCell())
	{	
		pGrid->PrintErrorMessage("Ladder is Cancelled! The Ladder must be drawn from bottom to top ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}	
	else if (startPos.VCell() == endPos.VCell()) //if it is the same cell nothing will be drawn!
	{
		pGrid->PrintErrorMessage("Ladder is Cancelled! The start Cell and End cell can't be the same Cell ! Click to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}

	// Clear messages
	pOut->ClearStatusBar();
	return true;
}



// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	if (ReadActionParameters())
	{
		// Create a Ladder object with the parameters read from the user
		Ladder* pLadder = new Ladder(startPos, endPos);
		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
		if (pGrid->IsOverlapping(pLadder))  // detects the overlpapping with other Ladders 
		{
			pManager->SetUpdateCond(false);
			delete pLadder;
			return;
		}

		bool added=pGrid->AddObjectToCell(pLadder); //if the Ladder isn't added due to a snake or a card in the start cell
		if (!added)
			pGrid->PrintErrorMessage("There is already an Object in this Cell , Click to continue ...");
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
}
