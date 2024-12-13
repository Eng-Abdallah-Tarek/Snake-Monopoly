#pragma once

#include "Card.h"
// [ CardFour ] Summary:Moves the player forward to the start of the next snake.

// Its Parameters: there is no parameters


class CardFour : public Card
{


	// there is no parameters


public:
	CardFour(const CellPosition& pos); // A Constructor takes card position



	virtual void Apply(Grid* pGrid, Player* pPlayer); // Moves the player forward to the start of the next snake.


	virtual ~CardFour(); // A Virtual Destructor


};

