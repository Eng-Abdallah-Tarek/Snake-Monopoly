#pragma once
#include "Action.h"
class SaveGridAction :
    public Action
{
    string FileName;

public:
    SaveGridAction(ApplicationManager* pApp);

    virtual bool ReadActionParameters();

    virtual void Execute();

    virtual ~SaveGridAction();
};

