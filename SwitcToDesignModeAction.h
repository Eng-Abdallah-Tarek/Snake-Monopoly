#pragma once
#include "Action.h"
class SwitcToDesignModeAction :
    public Action
{
public:
    SwitcToDesignModeAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~SwitcToDesignModeAction();
};

