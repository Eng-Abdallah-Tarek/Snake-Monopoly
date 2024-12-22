#include "Player.h"

#include "GameObject.h"
#include "CellPosition.h"
#include "UI_Info.h"
Player::Player(Cell * Cell, int playerNum) :justRolledDiceNum(-1), stepCount(0), wallet(100), playerNum(playerNum)
{
	pCell = Cell;
	turnCount = 0;
	prevented = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetTurnCount(int val)
{
	turnCount = val;
}

void Player::SetWallet(int pwallet)
{
	wallet = (pwallet < 0) ? 0 : pwallet;
	// Make any needed validations
}
bool Player::IsPrevented() const
{
	return prevented;
}
void Player::Setprevented(bool state)
{
	prevented = state;
}

int Player::GetWallet() const
{
	return wallet;
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}
int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, UI.PlayerColors[playerNum]);
}

void Player::ClearDrawing(Output* pOut) const
{
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, 
		((pCell->HasCard()) ? UI.CellColor_HasCard : UI.CellColor_NoCard));
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (++turnCount >= 3) {
		wallet += 10 * diceNumber;
		turnCount -= 3;
		return;
	}
	
	CellPosition pos = pCell->GetCellPosition();
	justRolledDiceNum = diceNumber;

	if (diceNumber + pos.GetCellNum() >= 99)  //the game ended
	{
		pos.SetHCell(10);
		pos.SetVCell(0);
		pGrid->UpdatePlayerCell(this, pos);
		pGrid->SetEndGame(1);
		pGrid->PrintErrorMessage("Congratulations ! Player No "+ to_string(this->playerNum)+" has Won (^_^)  ---- Click to continue.....");
		return;
	}

	pGrid->UpdatePlayerCell( this, pos.AddCellNum(justRolledDiceNum));

	if(pCell->GetGameObject())
		pCell->GetGameObject()->Apply(pGrid, this);

	
}
void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::ChangeWallet(int val, bool determine) // determine is a bool that determinates whether the 
{													// changing of the wallet is for the owner or the player who passed on it
	if (determine)
		wallet += val;
	else
		wallet = (val > wallet) ? 0 : wallet - val;

}