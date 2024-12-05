#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	DELETE_GAME_OBJECT, // delete the game object 
	ADD_CARD,		// Add Card Action	
	CUT_CARD,       // cut a card with all its data of the clipboard
	COPY_CARD,      // copy a card with all its data of the clipboard
	PASTE_CARD,     // paste the card in the  clipboard
	EDIT_CARD,      // edit the card in the choosen cell 
	SAVE_GRID,     // saving information of the designed grid
	OPEN_GRID,     // open the saved grid from a file and re_drawing it 
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,			// Exit Application





	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	NEW_GAME,   // restart all players'information
	INPUT_DICE_VALUE, // Instead of generating a random value for the dice
	TO_DESIGN_MODE,	// Go to Design Mode
	eXIT,          // exit application
	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif