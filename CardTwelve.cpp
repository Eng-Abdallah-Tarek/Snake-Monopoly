#include "CardTwelve.h"

Player* CardTwelve ::Owner = 0;
int CardTwelve::Fees = -1;
int CardTwelve::Price = -1;
bool CardTwelve::HaveNotReadPars = 1;
bool CardTwelve::HaveNotSavedPars = 1;

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;
}

CardTwelve::CardTwelve(const CellPosition& pos, int price, int fee) : Card(pos)
{
	cardNumber = 12;
	Price = price;
	Fees = fee;
	HaveNotReadPars = 0;
}

CardTwelve::~CardTwelve()
{
}

void CardTwelve::RemoveOwner()
{
	Owner = 0;
}

void CardTwelve::SetHaveNotSavedPars(bool par)
{
	HaveNotSavedPars = par;
}

void CardTwelve::SetHaveNotReadPars(bool par)
{
	HaveNotReadPars = par;
}

bool CardTwelve::ReadCardParameters(Grid* pGrid)
{
	if (HaveNotReadPars)
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
		HaveNotReadPars = 0;
		return 1;
	}
	return 1;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	
	if (Owner) {
		pGrid->PrintErrorMessage("You have reached a bought station fees will be deducted from your wallet . Click to continue ...");
		int gained = Fees;

		if (pPlayer->GetWallet() < Fees)
			gained = pPlayer->GetWallet();

		pPlayer->ChangeWallet(Fees, 0);
		Owner->ChangeWallet(gained, 1);
	}
	else {
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Vacant station reached. Would you like to buy it for " +
			to_string(Price) + " coins? (type Yes or No): ");
		string s = pIn->GetSrting(pOut);
	again:
		if (s == "Yes") {
			Player* pPlayer = pGrid->GetCurrentPlayer();
			if (pPlayer->GetWallet() < Price)
				pGrid->PrintErrorMessage("You don't have enough coins. Click to continue...");
			else {
				Owner = pPlayer;
				pPlayer->ChangeWallet(Price, 0);
			}
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

void CardTwelve::Save(ofstream& file)
{
	Card::Save(file);
	if(HaveNotSavedPars)
	{
		file << Price << ' ' << Fees;
		HaveNotSavedPars = 0;
	}
	file << '\n';
}
