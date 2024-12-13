#pragma once
#include "Card.h"
class CardTen :
    public Card
{
    static int Price, Fees;
    static Player* Owner;

public:

    CardTen(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardTen();
};

