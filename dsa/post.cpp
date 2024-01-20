#include <iostream>
#include <stack>
using namespace std;

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int operation (int oprator, int op1, int op2){
    switch (oprator){
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        default : return 0;
    }
}

int evaluate (string const &expr){
    stack <int> oper;
    for (char c : expr){
        if(isdigit(c)){
            oper.push(c - '0');
        } else {
            int op2 = oper.top();
            oper.pop();
            int op1 = oper.top();
            oper.pop();
            int result = operation(c, op1, op2);
            oper.push(result);
        }
    }

    return oper.top();
}

int main(){
    string str;
    cin >> str;

    cout << "result: " << evaluate(str) << endl;

    return 0;
}