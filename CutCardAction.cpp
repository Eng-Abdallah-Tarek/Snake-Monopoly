#include "CutCardAction.h"
#include "Grid.h"
#include "GameObject.h"
#include "Card.h"
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
	pOut->PrintMessage("Click on the card cell from which you want to cut......");
	cellpos = pIn->GetCellClicked();
	 if (!cellpos.IsValidCell())
	 {
		 pGrid->PrintErrorMessage("You didn't Click on a Cell ! Cutting is Cancelled ! Click any where to continue ");
		 pManager->SetUpdateCond(false);
		 return false;

	 }
	 GameObject* pgame = pGrid->getgameobj(cellpos);
	 if (!dynamic_cast<Card*>(pgame))
	 {
		 pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to cut! Click to continue ...");
		 pManager->SetUpdateCond(false);
		 return false;
	 }
	 ptr = dynamic_cast<Card*>(pgame);
	 pOut->ClearStatusBar();
	 return true;
}
void CutCardAction::Execute()
{
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->SetClipboard(ptr);
		pGrid->RemoveObjectFromCell(cellpos);		
	}
	return;
}
