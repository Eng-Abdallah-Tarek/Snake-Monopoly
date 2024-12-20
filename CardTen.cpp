#include "CardTen.h"

Player* CardTen::Owner = 0;
int CardTen::Fees = -1;
int CardTen::Price = -1;
bool CardTen::HaveNotReadPars = 1;
bool CardTen::HaveNotSavedPars = 1;

CardTen::CardTen(const CellPosition& pos): Card(pos)
{
	cardNumber = 10;
}

CardTen::CardTen(const CellPosition& pos, int price, int fee): Card(pos)
{
	cardNumber = 10;
	Price = price;
	Fees = fee;
	HaveNotReadPars = 0;
}

CardTen::~CardTen()
{
}

void CardTen::SetHaveNotSavedPars(bool par)
{
	HaveNotSavedPars = par;
}


void CardTen::SetHaveNotReadPars(bool par)
{
	HaveNotReadPars = par;
}

 void CardTen::RemoveOwner()
{
	Owner = 0;
}

bool CardTen::ReadCardParameters(Grid* pGrid)
{ if(HaveNotReadPars)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		HaveNotReadPars = 0;
		pOut->PrintMessage("Card 10: Enter the station's price: ");
		int temp = pIn->GetInteger(pOut);
		if (temp < 0) {
			pGrid->PrintErrorMessage("Cancelled, the price must be a positive integer. Click to continue...");
			return 0;
		}
		Price = temp;
		pOut->PrintMessage("Card 10: Enter the station's Fees: ");
		temp = pIn->GetInteger(pOut);
		if (temp < 0) {
			pGrid->PrintErrorMessage("Cancelled, the fees must be a positive integer. Click to continue...");
			return 0;
		}
		pOut->ClearStatusBar();
		Fees = temp;
		return 1;
	}
return 1;
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply( pGrid, pPlayer);
	if (Owner) {
		pGrid->GetCurrentPlayer()->ChangeWallet(Fees, 0);
		Owner->ChangeWallet(Fees, 1);
	}
	else {
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Vacant station reached. Would you like to buy it for " +
			to_string(Price)+"coins? (type Yes or No): ");
		string s = pIn->GetSrting(pOut);
		again:
		if (s == "Yes") {
			Owner = pGrid->GetCurrentPlayer();
		}
		else if (s == "No") {
			return;
		}
		else {
			pOut->PrintMessage("Invalid, please type \"Yes\" or \"No\": ");
			s = pIn->GetSrting(pOut);
			goto again;
		}

	}
}

void CardTen::Save(ofstream& file)
{
	Card::Save(file);
	if(HaveNotSavedPars)
	{
		file << Price << ' ' << Fees;
		HaveNotSavedPars = 0;
	}
	file << '\n';
}