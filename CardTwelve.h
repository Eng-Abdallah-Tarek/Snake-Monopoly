#pragma once
#include "Card.h"
class CardTwelve :
    public Card
{

  static  int Price, Fees;
  static Player* Owner;
  static bool HaveNotReadPars, HaveNotSavedPars;
public:
    CardTwelve(const CellPosition& pos);

    CardTwelve(const CellPosition& pos, int, int);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    static void SetHaveNotSavedPars(bool);

    static void SetHaveNotReadPars(bool);

    virtual void Save(ofstream&);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardTwelve();
};

