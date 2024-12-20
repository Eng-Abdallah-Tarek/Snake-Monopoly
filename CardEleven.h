#pragma once
#include "Card.h"
class CardEleven :
    public Card
{

   static int Price, Fees;
   static Player* Owner;
   static bool HaveNotReadPars, HaveNotSavedPars;
public:

    CardEleven(const CellPosition& pos);

    CardEleven(const CellPosition& pos, int, int);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    static void SetHaveNotSavedPars(bool);

    static void SetHaveNotReadPars(bool);

    virtual void Save(ofstream&);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardEleven();
};

