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
	pOut->PrintMessage("Click on the card cell that you want to copy......");
	CellPosition cellpos = pIn->GetCellClicked();
	if (!cellpos.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't Click on a Cell ! Editting is Cancelled ! Click any where to continue");
		pManager->SetUpdateCond(false);
		return false;

	}
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
	return;
}