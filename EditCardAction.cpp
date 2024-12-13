#include "EditCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"

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
	pOut->PrintMessage("click on the source cell......");
	cellpos = pIn->GetCellClicked();
	int v = cellpos.VCell();
	int h = cellpos.HCell();
	Cell* c = pGrid->getcell(v, h);
	if (c->HasCard())
	{
		
		ptr = c->HasCard();
		int i = ptr->GetCardNumber();

		if (i == 1 || i == 2 || i == 9||i==10||i==11||i==12||i==13)
		{
			
			num = i;
			pOut->ClearStatusBar();
			return true;
		}
	}
	pGrid->PrintErrorMessage("Error: this Cell  hasn't a card to edit ! Click to continue ...");
	ptr = NULL;
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