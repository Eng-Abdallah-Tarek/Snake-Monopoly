#pragma once
#include "Card.h"
class CardTwelve :
    public Card
{

  static  int Price, Fees;
  static Player* Owner;
  static bool HaveNotReadPars;
public:
    CardTwelve(const CellPosition& pos);

    virtual bool ReadCardParameters(Grid* pGrid);

    static void RemoveOwner();

    virtual void Save(ofstream&);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    ~CardTwelve();
};

