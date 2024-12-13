#pragma once
#include "Card.h"
class CardEleven :
    public Card
{

    int Price, Fees;
    Player* Owner;
public:

    CardEleven(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardEleven();
};

