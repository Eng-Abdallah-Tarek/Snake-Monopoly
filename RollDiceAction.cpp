#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

bool RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
	return true;
}

void RollDiceAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame()) {
		pGrid->PrintErrorMessage("The game is over! Click anywhere to continue...");
	}
	else
		///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) to implement this function ==

		// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

		// -- If not ended, do the following --:

		// 2- Generate a random number from 1 to 6 --> This step is done for you
	{
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 3- Get the "current" player from pGrid

		// 4- Move the currentPlayer using function Move of class player

		// 5- Advance the current player number of pGrid


		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
		pGrid->PrintErrorMessage("DiceNumber: " + to_string(diceNumber) +
			", Click anywhere to continue...");

		pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);
		pGrid->AdvanceCurrentPlayer();
	}
}

RollDiceAction::~RollDiceAction()
{
}
