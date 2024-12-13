#include "CardTwelve.h"

Player* CardTwelve ::Owner = 0;
int CardTwelve::Fees = -1;
int CardTwelve::Price = -1;


CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}

CardTwelve::~CardTwelve()
{
}

void CardTwelve::RemoveOwner()
{
	Owner = 0;
}

bool CardTwelve::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Card 12: Enter the station's price: ");
	int temp = pIn->GetInteger(pOut);
	if (temp < 0) {
		pGrid->PrintErrorMessage("Cancelled, the price must be a positive integer. Click to continue...");
		return 0;
	}
	Price = temp;
	pOut->PrintMessage("Card 12: Enter the station's Fees: ");
	temp = pIn->GetInteger(pOut);
	if (temp < 0) {
		pGrid->PrintErrorMessage("Cancelled, the fees must be a positive integer. Click to continue...");
		return 0;
	}
	Fees = temp;
	return 1;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (Owner) {
		pGrid->GetCurrentPlayer()->ChangeWallet(Fees, 0);
		Owner->ChangeWallet(Fees, 1);
	}
	else {
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Vacant station reached. Would you like to buy it for " +
			to_string(Price) + "coins? (type Yes or No): ");
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
