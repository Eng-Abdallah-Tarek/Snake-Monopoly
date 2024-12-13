#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}
bool GameObject::IsOverlapping(GameObject* newobj ,Grid* pGrid)const //Virtual Not pure virutual because there is no need to override the pure virtual in the Card Class with isoverriding
 {
	 return false;
 }


GameObject::~GameObject()
{
}