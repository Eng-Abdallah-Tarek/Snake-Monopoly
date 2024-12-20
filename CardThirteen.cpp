#include "CardThirteen.h"
Player* CardThirteen::Owner = 0;
int CardThirteen::Fees = -1;
int CardThirteen::Price = -1;
bool CardThirteen::HaveNotReadPars = 1;
bool CardThirteen::HaveNotSavedPars = 1;

CardThirteen::CardThirteen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 13;
}

CardThirteen::CardThirteen(const CellPosition& pos, int price, int fee) : Card(pos)
{
	cardNumber = 13;
	Price = price;
	Fees = fee;
	HaveNotReadPars = 0;
}

CardThirteen::~CardThirteen()
{
}

void CardThirteen::RemoveOwner()
{
	Owner = 0;
}

void CardThirteen::SetHaveNotSavedPars(bool par)
{
	HaveNotSavedPars = par;
}

void CardThirteen::SetHaveNotReadPars(bool par)
{
	HaveNotReadPars = par;
}

bool CardThirteen::ReadCardParameters(Grid* pGrid)
{
	if (HaveNotReadPars)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		HaveNotReadPars = 0;
		pOut->PrintMessage("Card 13: Enter the station's price: ");
		int temp = pIn->GetInteger(pOut);
		if (temp < 0) {
			pGrid->PrintErrorMessage("Cancelled, the price must be a positive integer. Click to continue...");
			return 0;
		}
		Price = temp;
		pOut->PrintMessage("Card 13: Enter the station's Fees: ");
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

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
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

void CardThirteen::Save(ofstream& file)
{
	Card::Save(file);
	if(HaveNotSavedPars)
	{
		file << Price << ' ' << Fees;
		HaveNotSavedPars = 0;
	}
	file << '\n';
}
