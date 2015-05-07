#ifndef EXPRESSIONS_HH
#define EXPRESSIONS_HH

#include <cassert>

/* Comment for the Expression class
 * ============================= */
class Expression {

// protected:
//     /* Pure Virtual Function */
//     virtual double evaluate(const Environment &env) const = 0;

public:
    /* Pure Virtual Destructor */
    virtual ~Expression() {}

    /* Pure Virtual Function */
    virtual double evaluate(const Environment &env) const = 0;
};

/* Comment for the class */
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

/* Comment for the class */
class AddOper : public BinaryOperator {
public:
    AddOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) + (getRHS())->evaluate(env);
    }
};

/* Comment for the class */
class SubOper : public BinaryOperator {
public:
    SubOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) - (getRHS())->evaluate(env);
    }
};

/* Comment for the class */
class MulOper : public BinaryOperator {
public:
    MulOper(Expression *_pLHS, Expression *_pRHS) :
        BinaryOperator(_pLHS, _pRHS) {}

    double evaluate(const Environment &env) const {
        return (getLHS())->evaluate(env) * (getRHS())->evaluate(env);
    }
};

/* Comment for the class */
class DivOper : public BinaryOperator {
public:
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

/* Comment for the class */
class NegOper : public UnaryOperator {
public:
    NegOper(Expression *_pOperand) : UnaryOperator(_pOperand) {}

    double evaluate(const Environment &env) const {
        return -1 * (getpOperand())->evaluate(env);
    }
};


#endif /* EXPRESSIONS_HH */












