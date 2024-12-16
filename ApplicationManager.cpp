#include"ApplicationManager.h"
#include"Grid.h"
#include"AddLadderAction.h"
#include"AddCardAction.h"
#include"AddSnakeAction.h"
#include"DeleteObjectAction.h"
#include "RollDiceAction.h"
#include "CopyCardAction.h"
#include "PasteCardAction.h"
#include "CutCardAction.h"
#include "EditCardAction.h"
#include "SwitchToPlayModeAction.h"
#include "SwitcToDesignModeAction.h"
#include "ExitAction.h"
#include "NewGameAction.h"
#include "InputDiceValueAction.h"
#include "SaveGridAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
	UpdateCond = true;
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

void ApplicationManager::SetUpdateCond(bool var)
{
	UpdateCond = var;
}
//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	if(UpdateCond)
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();

}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	SetUpdateCond(true);
	 //CHECK THIS IN CODE REVISING 

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case DELETE_GAME_OBJECT:
		pAct = new DeleteObjectAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case COPY_CARD:
		// create an object of AddCardAction here
		pAct = new CopyCardAction(this);
		break;
	case PASTE_CARD:
		// create an object of AddCardAction here
		pAct = new PasteCardAction(this);
		break;
	case CUT_CARD:
		// create an object of AddCardAction here
		pAct = new CutCardAction(this);
		break;
	case EDIT_CARD:
		// create an object of AddCardAction here
		pAct = new EditCardAction(this);
		break;
	case EXIT:
	case eXIT:
		pAct = new ExitAction(this);
		break;

	
	case TO_PLAY_MODE:
		pAct = new SwitchToPlayModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new SwitcToDesignModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;

	case INPUT_DICE_VALUE:
		pAct = new InputDiceValueAction(this);
		break;
	case SAVE_GRID:
		pAct = new SaveGridAction(this);
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
