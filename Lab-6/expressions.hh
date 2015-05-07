#ifndef __EXPRESSIONS_HH__
#define __EXPRESSIONS_HH__

#include <cassert>
#include <string>
#include "environment.hh"


/* Comment for the Expression class
 * ============================= */
class Expression {
public:
    /* Virtual Destructor */
    virtual ~Expression() {}

    /* Pure Virtual Function */
    virtual double evaluate(const Environment &env) const = 0;
};

/* Comment for the Value class
 * ============================= */
class Value : public Expression {
    double value;
public:
    /* Constructor */
    Value(double val) {
        value = val;
    }

    double evaluate(const Environment &env) const {
        return value;
    }
};

/* Comment for the Symbol class
 * ========================= */
class Symbol : public Expression {
    string symbol;
public:
    /* Constructor */
    Symbol(string sym) {
        symbol = sym;
    }

    string getSymbol() {
        return symbol;
    }

    double evaluate(const Environment &env) const {
        return env.getSymbolValue(symbol);
    }
};


/* Comment for the BinaryOperator class
 * ================================= */
class BinaryOperator : public Expression {
    Expression *pLHS;
    Expression *pRHS;

public:
    /* Constructor */
    BinaryOperator(Expression *_pLHS, Expression *_pRHS) {
        assert(_pLHS != 0);
        assert(_pRHS != 0);
        pLHS = _pLHS;
        pRHS = _pRHS;
    }

    const Expression * getLHS() const {
        return pLHS;
    }
    const Expression * getRHS() const {
        return pRHS;
    }

    ~BinaryOperator() {
        delete pLHS;
        delete pRHS;
    }
};

/* Comment for the AddOper class
 * ========================== */
class AddOper : public BinaryOperator {
public:
    /* Constructor */
    AddOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) + (getRHS())->evaluate(env);
    }
};

/* Comment for the SubOper class
 * ========================== */
class SubOper : public BinaryOperator {
public:
    /* Constructor */
    SubOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) - (getRHS())->evaluate(env);
    }
};

/* Comment for the MulOper class
 * ========================== */
class MulOper : public BinaryOperator {
public:
    /* Constructor */
    MulOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) * (getRHS())->evaluate(env);
    }
};

/* Comment for the DivOper class
 * ========================== */
class DivOper : public BinaryOperator {
public:
    /* Constructor */
    DivOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        if ((getRHS())->evaluate(env) == 0) {
            throw std::runtime_error("Division by 0 is not permitted !");
        }
        return (getLHS())->evaluate(env) / (getRHS())->evaluate(env);
    }
};

/* Comment for the UnaryOperator class
 * ================================ */
class UnaryOperator : public Expression {
    Expression *pOperand;

public:
    /* Constructor */
    UnaryOperator(Expression *_pOperand) {
        assert(_pOperand != 0);
        pOperand = _pOperand;
    }

    const Expression * getpOperand() const {
        return pOperand;
    }

    ~UnaryOperator() {
        delete pOperand;
    }
};

/* Comment for the NegOper class
 * ========================== */
class NegOper : public UnaryOperator {
public:
    NegOper(Expression *_pOperand) : UnaryOperator(_pOperand) {}

    double evaluate(const Environment &env) const {
        return -1 * (getpOperand())->evaluate(env);
    }
};


#endif /* __EXPRESSIONS_HH__ */
