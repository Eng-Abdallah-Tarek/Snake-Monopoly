#include "CopyCardAction.h"
#include "Grid.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{

}
void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ptr = NULL;
	pOut->PrintMessage("click on the source cell......");
	CellPosition cellpos = pIn->GetCellClicked();
	 int v = cellpos.VCell();
	 int h = cellpos.HCell();
	 Cell* c= pGrid->getcell(v,h);
	 if (!(c->HasCard()))
	 {
		 pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to copy ! Click to continue ...");
		 return;
	 }
	 ptr = c->HasCard();
	
	 pOut->ClearStatusBar();
}
void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (ptr)
	{
		pGrid->SetClipboard(ptr);
	}
	return;
}