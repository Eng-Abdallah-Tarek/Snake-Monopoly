#include "EditCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"


EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{

}
bool EditCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ptr = NULL;
	pOut->PrintMessage("Click on the cell with the card you want to edit......");
	cellpos = pIn->GetCellClicked();
	if (!cellpos.IsValidCell())
	{
		pGrid->PrintErrorMessage("You didn't Click on a Cell ! Editting is Cancelled ! Click any where to continue ");
		pManager->SetUpdateCond(false);
		return false;
	}
	GameObject* pgame = pGrid->getgameobj(cellpos);
	if (dynamic_cast<Card*>(pgame))
	{
		
		ptr = dynamic_cast<Card*>(pgame);
		int i = ptr->GetCardNumber();

		if (i == 1 || i == 2 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13)
		{
			switch (i) {
			case 10:
				CardTen::SetHaveNotReadPars(1); break;
			case 11:
				CardEleven::SetHaveNotReadPars(1); break;
			case 12:
				CardTwelve::SetHaveNotReadPars(1); break;
			case 13:
				CardThirteen::SetHaveNotReadPars(1); break;
			}
			pOut->ClearStatusBar();
			return true;
		}
	}
	pGrid->PrintErrorMessage("Error: this Cell  doesn't have an editable card ! Click to continue ...");
	pManager->SetUpdateCond(false);
	return false;
}
void EditCardAction::Execute()
{
	if (ReadActionParameters())
	{
		Grid* pGrid = pManager->GetGrid();
		ptr->ReadCardParameters(pGrid);
	}	
}