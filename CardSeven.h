#pragma once
#include "Card.h"
class CardSeven :  public Card
{
public:
	CardSeven(const CellPosition& pos);  // A Constructor takes card position



	virtual void Apply(Grid* pGrid, Player* pPlayer); //Applies the effect of card 7 by giving the 
	                                                  //player a second dice roll


	virtual ~CardSeven(); // A Virtual Destructor
};

