// StackBalanceEquationLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Demonstrates how to use a stack to check for proper open and closing of {, [, and (

#include <iostream>
#include <stack>
using namespace std;

bool inline balancedParenthesis(string exp) {
    stack<char> parens;
    
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            parens.push(ch);//push open parenthesis
        }

        if (ch == ')' || ch == '}' || ch==']') {
            
            if (parens.empty()) {
                return false;
            }
            
            char top = parens.top();
            parens.pop();

            if ((top == '(' && ch != ')') ||
                (top == '{' && ch != '}') ||
                (top == '[' && ch != ']')) {
                return false;
            }
        }
    }
    
    return parens.empty();
}


int main()
{
    string exp = "{([}]))))";
    if (balancedParenthesis(exp)) {
        cout << "Expression is balanced" << endl;
    }
    else {
        cout << "Expression is NOT balanced" << endl;
    }

}

