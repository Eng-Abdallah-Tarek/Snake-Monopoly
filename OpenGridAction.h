#pragma once
#include "Action.h"
class OpenGridAction :
    public Action
{
    string FileName;
public:
    OpenGridAction(ApplicationManager* pApp);
    virtual bool ReadActionParameters();
    virtual void Execute();
    virtual ~OpenGridAction();
};

