#include "CutCardAction.h"
#include "Grid.h"
#include "GameObject.h"
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
		int nun = ptr->GetCardNumber();
		Card* pCard=NULL;
		switch (nun)
		{
		case 1:
			pCard = new CardOne(*dynamic_cast<CardOne*>(ptr));
			break;

		case 2:
			pCard = new CardTwo(*dynamic_cast<CardTwo*>(ptr));
			break;

		case 3:
			pCard = new CardThree(*dynamic_cast<CardThree*>(ptr));
			break;

		case 4:

			pCard = new CardFour(*dynamic_cast<CardFour*>(ptr));
			break;

		case 5:
			pCard = new CardFive(*dynamic_cast<CardFive*>(ptr));
			break;

		case 6:
			pCard = new CardSix(*dynamic_cast<CardSix*>(ptr));
			break;
		case 7:
			pCard = new CardSeven(*dynamic_cast<CardSeven*>(ptr));
			break;
		case 8:
			pCard = new CardEight(*dynamic_cast<CardEight*>(ptr));
			break;
		case 9:
			pCard = new CardNine(*dynamic_cast<CardNine*>(ptr));
			break;
		case 10:
			pCard = new CardTen(*dynamic_cast<CardTen*>(ptr));
			break;

		case 11:
			pCard = new CardEleven(*dynamic_cast<CardEleven*>(ptr));
			break;

		case 12:
			pCard = new CardTwelve(*dynamic_cast<CardTwelve*>(ptr));
			break;

		case 13:
			pCard = new CardThirteen(*dynamic_cast<CardThirteen*>(ptr));
			break;

		}
		pGrid->SetClipboard(pCard);
		pGrid->RemoveObjectFromCell(cellpos);
	}
	return;
}
