#include "InputDiceValueAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
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
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please enter a dice value between 1 - 6");
	inputvalue = pIn->GetInteger(pOut);
	if (inputvalue < 1 || inputvalue > 6)
	{
		//pOut->PrintMessage("invalid input ");
		pGrid->PrintErrorMessage("invalid input,not between(1-6) ");   // i find this fun in grid but i want to make sure about that
		inputvalue = 0;
	}

	// Clear messages
	pOut->ClearStatusBar();
}
void InputDiceValueAction::Execute()
{

	//wait for ziad to do roll dice action;


}