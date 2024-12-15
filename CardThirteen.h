#pragma once
#include "Card.h"
class CardThirteen :
    public Card
{
 static   int Price, Fees;
 static   Player* Owner;
 static   bool HaveNotReadPars;

public:
    CardThirteen(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardThirteen();
};

