#ifndef INVOKER_H
#define INVOKER_H

#include "command.h"
class Invoker
{
    Command *command = nullptr;
public:
    void exec(Command *command_);
};

#endif // INVOKER_H