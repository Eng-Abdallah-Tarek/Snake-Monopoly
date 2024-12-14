#include "CutCardAction.h"
#include "Grid.h"
#include "GameObject.h"
#include<iostream>
using namespace std;
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{

}
bool CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ptr = NULL;
	pOut->PrintMessage("Click on the card cell that you want to cut......");
	cellpos = pIn->GetCellClicked();
	 if (!cellpos.IsValidCell())
	 {
		 pGrid->PrintErrorMessage("You didn't Click on a Cell ! Cutting is Cancelled ! Click any where to continue ");
		 pManager->SetUpdateCond(false);
		 return false;

	 }
	int v = cellpos.VCell();
	int h = cellpos.HCell();
	Cell* c = pGrid->getcell(v, h);
	if (!(c->HasCard()))
	{
		pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to cut ! Click to continue ...");
		pManager->SetUpdateCond(false);
		return false;
	}
	 ptr = c->HasCard();
	 pOut->ClearStatusBar();
	 return true;
}
void CutCardAction::Execute()
{
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(NULL);
		pGrid->RemoveObjectFromCell(cellpos);
		cout << 1;
	}
	return;
}
