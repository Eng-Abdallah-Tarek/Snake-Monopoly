#include "SwitcToDesignModeAction.h"
#include "Grid.h"
SwitcToDesignModeAction::SwitcToDesignModeAction(ApplicationManager*pApp): Action(pApp)
{
}

SwitcToDesignModeAction::~SwitcToDesignModeAction()
{
}

bool SwitcToDesignModeAction::ReadActionParameters()
{
	return 1;
}

void SwitcToDesignModeAction::Execute()
{
	pManager->GetGrid()->GetOutput()->CreateDesignModeToolBar();
}
