#pragma once
#include "Card.h"
class CardThirteen :
    public Card
{
    int Price, Fees;
    Player* Owner;
public:
    CardThirteen(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardThirteen();
};

