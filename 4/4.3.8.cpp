struct Expression
{
    virtual double evaluate() const = 0;

	virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

	double evaluate() const {
		return value;
	}

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

	double evaluate() const {
		double lr = left->evaluate();
		double rr = right->evaluate();
		if(op == '+') return lr + rr;
		if(op == '*') return lr * rr;
		if(op == '-') return lr - rr;
		if(op == '/') return lr / rr;
		throw;
	}

	~BinaryOperation() {
		delete left;
		delete right;
	}

private:
    Expression const * left;
    Expression const * right;
    char op;
};