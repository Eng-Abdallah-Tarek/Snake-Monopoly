#include "OpenGridAction.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include <fstream>
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp):Action(pApp)
{
}

OpenGridAction::~OpenGridAction()
{
}

bool OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the name of the txt file to open: ");
	FileName = pGrid->GetInput()->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
	return 1;
}

void OpenGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	int nLadders, nSnakes, nCards, n1, n2, n3, n4;
	bool c10 = 1, c11 = 1, c12 = 1, c13 = 1;
	ReadActionParameters();
	ifstream file;
	file.open(FileName);
	if(file.is_open())
	{
		pGrid->RemoveAllObjects();
		GameObject* ptr;
		file >> nLadders;
		for (int i = 0; i < nLadders; i++) {
			file >> n1 >> n2;
			ptr = new Ladder( CellPosition(n1), CellPosition(n2));
			pGrid->AddObjectToCell(ptr);
		}
		file >> nSnakes;
		for (int i = 0; i < nSnakes; i++) {
			file >> n1 >> n2;
			ptr = new Snake(CellPosition(n1), CellPosition(n2));
			pGrid->AddObjectToCell(ptr);
		}
		file >> nCards;
		for (int i = 0; i < nCards; i++) {
			file >> n1 >> n2;
			switch (n1) {
			case 1:
				file >> n3;
				ptr = new CardOne(CellPosition(n2), n3);
				break;
			case 2:
				file >> n3;
				ptr = new CardTwo(CellPosition(n2), n3);
				break;
			case 3:
				ptr = new CardThree(CellPosition(n2));
				break;
			case 4:
				ptr = new CardFour(CellPosition(n2));
				break;
			case 5:
				ptr = new CardFive(CellPosition(n2));
				break;
			case 6:
				ptr = new CardSix(CellPosition(n2));
				break;
			case 7:
				ptr = new CardSeven(CellPosition(n2));
				break;
			case 8:
				ptr = new CardEight(CellPosition(n2));
				break;
			case 9:
				file >> n3;
				ptr = new CardNine(CellPosition(n2), CellPosition(n3));
				break;
			case 10:
				if (c10) {

					file >> n3 >> n4;
					ptr = new CardTen(CellPosition(n2), n3, n4);
					c10 = 0;
				}
			
				else {
					ptr = new CardTen(CellPosition(n2));
				}
				break;
			case 11:
				if (c11) {

					file >> n3 >> n4;
					ptr = new CardEleven(CellPosition(n2), n3, n4);
					c11 = 0;
				}
			
				else {
					ptr = new CardEleven(CellPosition(n2));
				}
				break;
			case 12:
				if (c12) {

					file >> n3 >> n4;
					ptr = new CardTwelve(CellPosition(n2), n3, n4);
					c12 = 0;
				}
			
				else {
					ptr = new CardTwelve(CellPosition(n2));
				}
				break;
				
			case 13:
				if(c13) {
				file >> n3 >> n4;
				ptr = new CardThirteen(CellPosition(n2), n3, n4);
				c13 = 0;
				}
				else {
					ptr = new CardThirteen(CellPosition(n2));
				}
				break;
			}
			pGrid->AddObjectToCell(ptr);
		}
	}
	else {
		pGrid->PrintErrorMessage("Error: The file doesn't exist. Click to continue...");
	}
}