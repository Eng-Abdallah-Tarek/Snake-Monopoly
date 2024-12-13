#pragma once
#include "Card.h"
class CardTen :
    public Card
{
    int Price, Fees;
    Player* Owner;

public:

    CardTen(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardTen();
};

