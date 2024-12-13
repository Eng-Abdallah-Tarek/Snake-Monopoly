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

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("please enter a dice value between 1-6");
	int temp = pGrid->GetInput()->GetInteger(pOut);
	if (temp < 1 || temp > 6) {
		pGrid->PrintErrorMessage("The input value must be an integer between 1-6, Click to continue...");
	}
	else
	{
		InputValue = temp;
		pOut->ClearStatusBar();
	}

}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame()) {
		pGrid->PrintErrorMessage("The player already won! Click anywhere to continue...");
	}
	else {
		pGrid->GetCurrentPlayer()->Move(pGrid, InputValue);
	}
}