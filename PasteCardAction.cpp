#include "PasteCardAction.h"
#include "Grid.h"
#include "Cell.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
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
	GameObject* pgame = pGrid->getgameobj(c1);
	if (pgame)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
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
		Card* pCard = pGrid->GetClipboard();
		if (pCard == NULL)
		{
			return;
		}
		int nun = pCard->GetCardNumber();
		pCard->change(cellpos);
		switch (nun)
		{
		case 1:
			pCard = new CardOne(cellpos);
			break;

		case 2:
			pCard = new CardTwo(cellpos);
			break;

		case 3:
			pCard = new CardThree(cellpos);
			break;

		case 4:

			pCard = new CardFour(cellpos);
			break;

		case 5:
			pCard = new CardFive(cellpos);
			break;

		case 6:
			pCard = new CardSix(cellpos);
			break;
		case 7:
			pCard = new CardSeven(cellpos);
			break;
		case 8:
			pCard = new CardEight(cellpos);
			break;
			/*case 9:
					pCard = new CardNine(cardPosition);
				break;*/
		case 10:
			pCard = new CardTen(cellpos);
			break;

		case 11:
			pCard = new CardEleven(cellpos);
			break;

		case 12:
			pCard = new CardTwelve(cellpos);
			break;

		case 13:
			pCard = new CardThirteen(cellpos);
			break;
		default:
			return;
		}
	  
		pGrid->Helperfun(cellpos, pCard);
		//pGrid->SetClipboard(NULL);
	}
	return;
}
