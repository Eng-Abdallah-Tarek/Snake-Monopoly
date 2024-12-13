#pragma once
#include "Action.h"
class InputDiceValueAction :
    public Action
{
    int InputValue;
public:
    InputDiceValueAction(ApplicationManager* pApp);

    virtual bool ReadActionParameters();

    virtual void Execute();

    virtual ~InputDiceValueAction();
};

