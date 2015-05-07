#ifndef EXPRESSIONS_HH
#define EXPRESSIONS_HH


/* Comment for the Expression class
 * ============================= */
class Expression {

protected:
    /* Pure Virtual Function */
    virtual double evaluate(const Environment &env) const = 0;

public:
    /* Pure Virtual Destructor */
    virtual ~Expression() {}
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

    const Expression * getLHS() {
        return pLHS;
    }
    const Expression * getRHS() {
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
    AddOper() : BinaryOperator(pLHS, pRHS) {}
    double evaluate(const Environment &env) const {
        return pLHS->evaluate() + pRHS->evaluate();
    }
};

/* Comment for the class */
class SubOper : public BinaryOperator {
public:
    SubOper() : BinaryOperator(pLHS, pRHS) {}
    double evaluate(const Environment &env) const {
        return pLHS->evaluate() - pRHS->evaluate();
    }
};

/* Comment for the class */
class MulOper : public BinaryOperator {
public:
    MulOper() : BinaryOperator(pLHS, pRHS) {}
    double evaluate(const Environment &env) const {
        return pLHS->evaluate() * pRHS->evaluate();
    }
};

/* Comment for the class */
class DivOper : public BinaryOperator {
public:
    DivOper() : BinaryOperator(pLHS, pRHS) {}
    double evaluate(const Environment &env) const {

    	if (pRHS->evaluate() == 0) {
    		throw std::runtime_error("Division by 0 is not permitted !");
    	}
        return pLHS->evaluate() / pRHS->evaluate();
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

    const Expression * getpOperand() {
        return pOperand;
    }

    ~UnaryOperator() {
        delete pOperand;
    }
};

/* Comment for the class */
class NegOper : public UnaryOperator {
public:
    NegOper() : UnaryOperator(pOperand) {}
    double evaluate(const Environment &env) const {
        return pLHS->evaluate() + pRHS->evaluate();
    }
};


#endif /* EXPRESSIONS_HH */












