#pragma once
#include "Card.h"
class CardEleven :
    public Card
{

   static int Price, Fees;
   static Player* Owner;
   static bool HaveNotReadPars;
public:

    CardEleven(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    virtual void Save(ofstream&);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardEleven();
};

