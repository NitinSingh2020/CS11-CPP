#ifndef __COMMANDS_HH__
#define __COMMANDS_HH__

#include <iostream>
#include "expressions.hh"
#include <cassert>

/* Comment for the Command class
 * ========================== */
class Command {
public:
    virtual void run(Environment &env) const = 0;

    /* Virtual Destructor */
    virtual ~Command() {}
};


/* Comment for the PrintCommand class
 * =============================== */
class PrintCommand : public Command {
    Expression *command;
public:
    /* Constructor */
    PrintCommand(Expression *_command) {
        assert(_command != 0);
        command = _command;
    }

    void run(Environment &env) const {
        std::cout << " = " << command->evaluate(env) << std::endl;
    }

    /* Destructor */
    ~PrintCommand() {
        delete command;
    }
};


/* Comment for the AssignCommand class
 * ================================ */
class AssignCommand : public Command {
    Symbol *symbol;
    Expression *command;

public:
    /* Constructor */
    AssignCommand(Symbol *_symbol, Expression *_command) {
        symbol = _symbol;
        command = _command;
    }
    
    void run(Environment &env) const {
        symbol->getSymbol() = command->evaluate(env);
        std::cout << symbol->getSymbol() << " = " << command->evaluate(env) << std::endl;
    }

    /* Destructor */
    ~AssignCommand() {
        delete symbol;
        delete command;
    }
};

#endif /* __COMMANDS_HH__ */
