#pragma once
#include "Action.h"
class SwitcToDesignModeAction :
    public Action
{
public:
    SwitcToDesignModeAction(ApplicationManager* pApp);
    virtual bool ReadActionParameters();
    virtual void Execute();
    virtual ~SwitcToDesignModeAction();
};

