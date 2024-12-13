#include "SwitcToDesignModeAction.h"
#include "Grid.h"
SwitcToDesignModeAction::SwitcToDesignModeAction(ApplicationManager*pApp): Action(pApp)
{
}

SwitcToDesignModeAction::~SwitcToDesignModeAction()
{
}

void SwitcToDesignModeAction::ReadActionParameters()
{
}

void SwitcToDesignModeAction::Execute()
{
	pManager->GetGrid()->GetOutput()->CreateDesignModeToolBar();
}
