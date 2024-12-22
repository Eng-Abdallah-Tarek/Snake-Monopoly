#include "CardNine.h"
CardNine::CardNine(const CellPosition& cardpostion):Card(cardpostion)
{
	cardNumber = 9;
}

CardNine::CardNine(const CellPosition& cardpostion, CellPosition CP) :Card(cardpostion)
{
	cardNumber = 9;
	moveto = CP;
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)	
{ 
	Card::Apply(pGrid, pPlayer);
	int dicevalue = moveto.GetCellNum() - position.GetCellNum() ;
	pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);   //Turn count isn't considered with this motion by 1 !
	pPlayer->Move(pGrid, dicevalue);
}
bool CardNine::ReadCardParameters(Grid* pGrid)  //returns false in the case that the user entered invalid cell
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please, click on the cell to move to on reaching card 9...");
	CellPosition InputedCell =pIn->GetCellClicked();
	if (! InputedCell.IsValidCell() )
	{
		pGrid->PrintErrorMessage("Adding Card is cancelled : Invalid Cell , Click to continue ....");
		return false;
	}
	else 
	{
		moveto = InputedCell; 
		return true;
	}
	pOut->ClearStatusBar();
}
void CardNine::Save(ofstream& file)
{
	Card::Save(file);
	file << moveto.GetCellNum() << '\n';
}
CardNine::~CardNine()
{ }
