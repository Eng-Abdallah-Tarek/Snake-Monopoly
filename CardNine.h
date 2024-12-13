#pragma once
#include "Card.h"

class CardNine : public Card
{
	CellPosition moveto;
public:
	CardNine(const CellPosition& cardpostion,const CellPosition& PostitionMoveTo);
	virtual void Apply(Grid* pGrid,Player* pPlayer);
	virtual ~CardNine();
};

