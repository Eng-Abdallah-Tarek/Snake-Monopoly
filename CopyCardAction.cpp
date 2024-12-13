#include "CopyCardAction.h"
#include "Grid.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{

}
bool CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ptr = NULL;
	pOut->PrintMessage("Click on the source cell......");
	CellPosition cellpos = pIn->GetCellClicked();
	 int v = cellpos.VCell();
	 int h = cellpos.HCell();
	 Cell* c= pGrid->getcell(v,h);
	 if (!(c->HasCard()))
	 {
		 pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to copy ! Click to continue ...");
		 pManager->SetUpdateCond(false);
		 return false;
	 }
	 ptr = c->HasCard();
	 if (!ptr)
	 {
		 return false;
	 }
	 pOut->ClearStatusBar();
	 return true;
}

void CopyCardAction::Execute()
{
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(ptr);
	}
	
}