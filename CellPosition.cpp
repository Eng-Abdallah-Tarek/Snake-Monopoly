#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
	
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
	
	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (v >= 0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	else {
		return false;
	}
}

bool CellPosition::SetHCell(int h)
{
	if (h >= 0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if ((vCell >= 0 && vCell <= 8) && (hCell >= 0 && hCell <= 10))
	{
		return true;

	}
	else {

		return false;
	}
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	if ((cellPosition.vCell >= 0 && cellPosition.vCell <= 8) && (cellPosition.hCell >= 0 && cellPosition.hCell <= 10))
	{
		int cellNum = (cellPosition.hCell) + 89 - 11 * (cellPosition.vCell);

		return cellNum;
	}
	else
		return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	if (cellNum >= 1 && cellNum <= 99)
	{
		int v, h;
		v = (99 - cellNum) / 11;
		h = cellNum + 11 * v - 89;
		position.SetVCell(v);
		position.SetHCell(h);
			
	}


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	return position;
}

CellPosition& CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int cellNum = GetCellNum();
	cellNum += addedNum;
	(*this) = GetCellPositionFromNum(cellNum);
	return *this;
	// Note: this function updates the data members (vCell and hCell) of the calling object

}




