#include "InputDiceValueAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp): Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

InputDiceValueAction::~InputDiceValueAction()
{
}

bool InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	if (pGrid->GetEndGame()) {		// Checking whether the game ended before reading the Parameters
		pGrid->PrintErrorMessage(" Game is already Over ! select new game to play again , Click anywhere to continue...");
		pManager->SetUpdateCond(false);
		return false;
	}
	else if (pGrid->GetCurrentPlayer()->IsPrevented())
	{
		pGrid->PrintErrorMessage("You are denied from playing this turn , Click to continue .... ");
		pGrid->GetCurrentPlayer()->Setprevented(false);
		InputValue=0;
		return true;
	}

	else if (pGrid->GetCurrentPlayer()->GetWallet() == 0 && pGrid->GetCurrentPlayer()->GetTurnCount()==1 )
	{
		pGrid->PrintErrorMessage("Can't move : Your Wallet is empty wait for it to recharge , click to continue ... ");
		pGrid->GetCurrentPlayer()->SetTurnCount(2);
		pGrid->AdvanceCurrentPlayer();
		return false;
	}

	pOut->PrintMessage("Enter a dice value between 1-6");
	InputValue = pGrid->GetInput()->GetInteger(pOut);
	if (InputValue < 1 || InputValue > 6)
	{
		pGrid->PrintErrorMessage("Cancelling Dice : You can only enter an integer form 1 to 6 , Click to continue...");
		pManager->SetUpdateCond(false);
		return 0;
	}
	else
	{
		pOut->ClearStatusBar();
		return 1;
	}

}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	if (ReadActionParameters())
	{
		
			pGrid->GetCurrentPlayer()->Move(pGrid, InputValue);
			pGrid->AdvanceCurrentPlayer();
	}
	
}