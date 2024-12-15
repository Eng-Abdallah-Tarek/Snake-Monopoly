#pragma once
#include "Action.h"
class SaveGridAction :
    public Action
{

public:
    SaveGridAction(ApplicationManager* pApp);

    virtual bool ReadActionParameters();

    virtual void Execute();

    virtual ~SaveGridAction();
};

