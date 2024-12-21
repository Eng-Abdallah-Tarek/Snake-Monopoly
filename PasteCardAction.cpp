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
	pOut->PrintMessage("Click on the cell that you want to paste to.....");
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
			pGrid->PrintErrorMessage("You must copy or cut a card first befor Pasting ! Click to continue ...");
			return;
		}
		int nun = pCard->GetCardNumber();
		
		switch (nun)
		{
		case 1:
			pCard = new CardOne(*dynamic_cast<CardOne*>(pCard));
			break;

		case 2:
			pCard = new CardTwo(*dynamic_cast<CardTwo*>(pCard));
			break;

		case 3:
			pCard = new CardThree(*dynamic_cast<CardThree*>(pCard));
			break;

		case 4:

			pCard = new CardFour(*dynamic_cast<CardFour*>(pCard));
			break;

		case 5:
			pCard = new CardFive(*dynamic_cast<CardFive*>(pCard));
			break;

		case 6:
			pCard = new CardSix(*dynamic_cast<CardSix*>(pCard));
			break;
		case 7:
			pCard = new CardSeven(*dynamic_cast<CardSeven*>(pCard));
			break;
		case 8:
			pCard = new CardEight(*dynamic_cast<CardEight*>(pCard));
			break;
			case 9:
					pCard = new CardNine(*dynamic_cast<CardNine*>(pCard));
				break;
		case 10:
			pCard = new CardTen(*dynamic_cast<CardTen*>(pCard));
			break;

		case 11:
			pCard = new CardEleven(*dynamic_cast<CardEleven*>(pCard));
			break;

		case 12:
			pCard = new CardTwelve(*dynamic_cast<CardTwelve*>(pCard));
			break;

		case 13:
			pCard = new CardThirteen(*dynamic_cast<CardThirteen*>(pCard));
			break;
		
		}
		pCard->change(cellpos);
		pGrid->SetWithPos(cellpos, pCard);
		Card::Increment();
		
	}
	return;
}
