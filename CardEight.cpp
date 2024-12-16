#include "CardEight.h"
	CardEight::CardEight(const CellPosition& pos):Card(pos)
	{ 
		cardNumber = 8;
	}

 void CardEight::Apply(Grid* pGrid, Player* pPlayer)
	{
	 Card::Apply(pGrid, pPlayer);
	 pPlayer->Move(pGrid, 0);
	}

 void CardEight::Save(ofstream& file)
 {
	 Card::Save(file);
	 file << '\n';
 }

 CardEight::~CardEight()
	{

	}

