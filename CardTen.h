#pragma once
#include "Card.h"
class CardTen :
    public Card
{
    static int Price, Fees;
    static Player* Owner;
    static bool HaveNotReadPars, HaveNotSavedPars;
public:

    CardTen(const CellPosition& pos);
    CardTen(const CellPosition& pos, int , int);
    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    virtual void Save(ofstream&);

    static void SetHaveNotSavedPars(bool);

    static void SetHaveNotReadPars(bool);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardTen();
};

