#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string& expresion){
    stack<char> pila;
    
    for (char c: expresion){
        if (c == '(' || c == '[' || c == '{'){
            pila.push(c);
        }

    else if (c == ')' || c == ']' || c == '}'){
        if (pila.empty()){
            return false;
        }

        char top = pila.top();
        pila.pop();

        if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
            return false;
        }
    }
    return pila.empty();
} 
}


int main(){
    string expression = "{[()]}";

    cout << isBalanced(expression);

    return 0;
}