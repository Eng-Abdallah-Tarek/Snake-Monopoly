#include "PasteCardAction.h"
#include "Grid.h"
#include "Cell.h"
#include "Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{

}
void PasteCardAction::ReadActionParameters()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the destination cell.....");
	CellPosition c1 = pIn->GetCellClicked();
	int v = c1.VCell();
	int h = c1.HCell();
	c = pGrid->getcell(v, h);
	if ((c->HasCard()) || (c->HasLadder()) || (c->HasSnake()))
	{

		pGrid->PrintErrorMessage("Error: Cell already has an object !Click to continue ...");
		return;
	}

	cellpos = c1;
	pOut->ClearStatusBar();
}
void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card*cardpaste = pGrid->GetClipboard();

	if (cellpos.IsValidCell())
	{
	
		c->SetGameObject(cardpaste);

	}
	return;
}
