#include "CopyCardAction.h"
#include "Grid.h"
#include "Card.h"
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
	pOut->PrintMessage("Click on the cell that you want to copy from...");
	CellPosition cellpos = pIn->GetCellClicked();
	if (!cellpos.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't Click on a Cell ! Pasting is Cancelled ! Click any where to continue");
		pManager->SetUpdateCond(false);
		return false;

	}
	GameObject* pgame = pGrid->getgameobj(cellpos);
	if (!dynamic_cast<Card*>(pgame))
	{
		pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to copy ! Click to continue ...");
		pManager->SetUpdateCond(false);
		return false;
	}
	ptr = dynamic_cast<Card*>(pgame);
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