#pragma once
#include "Card.h"
class CardNine : public Card
{

private:
	CellPosition moveto;
public:
	CardNine(const CellPosition& cardpostion);
	CardNine(const CellPosition& cardpostion, CellPosition);
	virtual bool ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid,Player* pPlayer);
	virtual void Save(ofstream&);
	virtual ~CardNine();
};

