/*
#ifndef EXPR_HPP
#define EXPR_HPP

#include "defs.hpp"

namespace parser {

class Expr {
public:
    virtual ~Expr() = default;
};

class LiteralExpr : public Expr {
public:
    string value;

    LiteralExpr(string value) : value(value) {}
};

class BinaryExpr : public Expr {
public:
    ptr<Expr> left;
    ptr<Expr> right;
    string op;

    BinaryExpr(std::shared_ptr<Expr> left, std::shared_ptr<Expr> right, const std::string& op)
        : left(left), right(right), op(op) {}

};

class UnaryExpr : public Expr {
private:
    std::shared_ptr<Expr> operand;
    std::string op;
    bool prefix;

public:
    UnaryExpr(std::shared_ptr<Expr> operand, const std::string& op, bool prefix = true)
        : operand(operand), op(op), prefix(prefix) {}

    std::string toString() const override {
        if (prefix) {
            return op + operand->toString();
        } else {
            return operand->toString() + op;
        }
    }
};

class TensorExpr : public Expr {
public:
// custom string, not latex. format 
    string name;
    vector<int> indices;

    TensorExpr(string name, vector<int> indices) : name(name), indices(indices) {}
};

class GroupingExpr : public Expr {
private:
    std::shared_ptr<Expr> expression;

public:
    GroupingExpr(std::shared_ptr<Expr> expression) : expression(expression) {}

    std::string toString() const override {
        return "(" + expression->toString() + ")";
    }
};

}  // namespace parser

#endif  // EXPR_HPP
*/