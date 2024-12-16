#include "CardNine.h"
CardNine::CardNine(const CellPosition& cardpostion):Card(cardpostion)
{

}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{ 
	Card::Apply(pGrid, pPlayer);
	int dicevalue = moveto.GetCellNum() - position.GetCellNum() ;
	pPlayer->Move(pGrid, dicevalue);
}
bool CardNine::ReadCardParameters(Grid* pGrid)  //returns false in the case that the user entered invalid cell
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition InputedCell =pIn->GetCellClicked();
	if (! InputedCell.IsValidCell() )
	{
		pGrid->PrintErrorMessage("Error: Invalid Cell , Click to continue ....");
		return false;
	}
	else 
	{
		moveto = InputedCell; 
		return true;
	}
}
void CardNine::Save(ofstream& file)
{
	Card::Save(file);
	file << moveto.GetCellNum() << '\n';
}
CardNine::~CardNine()
{ }
