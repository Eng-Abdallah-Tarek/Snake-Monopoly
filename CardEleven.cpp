#include "CardEleven.h"

Player* CardEleven::Owner = 0;
int CardEleven::Fees = -1;
int CardEleven::Price = -1;
bool CardEleven::HaveNotReadPars = 1;
bool CardEleven::HaveNotSavedPars = 1;


CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;
}

CardEleven::CardEleven(const CellPosition& pos, int price, int fee) : Card(pos)
{
	cardNumber = 11;
	Price = price;
	Fees = fee;
	HaveNotReadPars = 0;
}

CardEleven::~CardEleven()
{
}

void CardEleven::RemoveOwner()
{
	Owner = 0;
}

void CardEleven::SetHaveNotSavedPars(bool par)
{
	HaveNotSavedPars = par;
}

void CardEleven::SetHaveNotReadPars(bool par)
{
	HaveNotReadPars = par;
}

bool CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (HaveNotReadPars)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		HaveNotReadPars = 0;
		pOut->PrintMessage("Card 11: Enter the station's price: ");
		int temp = pIn->GetInteger(pOut);
		if (temp < 0) {
			pGrid->PrintErrorMessage("Cancelled, the price must be a positive integer. Click to continue...");
			return 0;
		}
		Price = temp;
		pOut->PrintMessage("Card 11: Enter the station's Fees: ");
		temp = pIn->GetInteger(pOut);
		if (temp < 0) {
			pGrid->PrintErrorMessage("Cancelled, the fees must be a positive integer. Click to continue...");
			return 0;
		}
		Fees = temp;
		return 1;
	}
	return 1;
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
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
			Player* pPlayer = pGrid->GetCurrentPlayer();;
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

void CardEleven::Save(ofstream& file)
{
	Card::Save(file);
	if(HaveNotSavedPars)
	{
		file << Price << ' ' << Fees;
		HaveNotSavedPars = 0;
	}
	file << '\n';
}
