#include <iostream>

struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value() << " ";
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        bool bracket = bop->get_op() == '+' || bop->get_op() == '-';

        std::cout << (bracket ? "(" : "");
        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << (bracket ? ")" : "");
    }
};