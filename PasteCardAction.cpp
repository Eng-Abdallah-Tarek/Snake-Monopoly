#include "PasteCardAction.h"
#include "Grid.h"
#include "Cell.h"
#include "Card.h"
#include<iostream>
using namespace std;
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{

}
bool PasteCardAction::ReadActionParameters()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the cell that you want to paste to it.....");
	CellPosition c1 = pIn->GetCellClicked();
	if (!c1.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't Click on a Cell ! Pasting is Cancelled ! Click any where to continue ");
		pManager->SetUpdateCond(false);
		return false;
	}
	int v = c1.VCell();
	int h = c1.HCell();
	c = pGrid->getcell(v, h);
	if ((c->HasCard()) || (c->HasLadder()) || (c->HasSnake()))
	{

		pGrid->PrintErrorMessage("Error: Cell already has an object !Click to continue ...");
		pManager->SetUpdateCond(false);
		return false;
	}
	cellpos = c1;
	pOut->ClearStatusBar();
	return true;
}
void PasteCardAction::Execute()
{
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();
		Card* cardpaste = pGrid->GetClipboard();
		c->SetGameObject(cardpaste);
		cout << 2;
	}
	return;
}
