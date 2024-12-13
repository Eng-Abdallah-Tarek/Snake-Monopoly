#pragma once
#include "Card.h"
// [ CardThree ] Summary:Moves the player forward to the start of the next ladder.

// Its Parameters: there is no parameters


class CardThree : public Card
{
    
	// there is no parameters


public:
	CardThree(const CellPosition& pos); // A Constructor takes card position



	virtual void Apply(Grid* pGrid, Player* pPlayer); // Moves the player forward to the start of the next ladder.

	
	virtual ~CardThree(); // A Virtual Destructor



};

