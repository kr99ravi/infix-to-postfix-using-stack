#include<bits/stdc++.h>
using namespace std;

int helperFunc(char c) {
    if(c == '^')
        return 8;
    else if(c == '/' || c=='*')
        return 7;
    else if(c == '+' || c == '-')
        return 6;
    else
        return -6;
}


void infixToPostfixFunction(string str) {
    stack<char> temp; 
    string ans;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ans += ch;
        else if(ch == '(') temp.push('(');    
        else if(ch == ')') {
            while(temp.top() != '(')
            {
                ans += temp.top();
                temp.pop();
            }
            temp.pop();
        }
        else {
            while(!temp.empty() && helperFunc(str[i]) <= helperFunc(temp.top())) {
                ans += temp.top();
                temp.pop();
            }
            temp.push(ch);
        }
    }
    while(!temp.empty()) {
        ans += temp.top();
        temp.pop();
    }
    cout << ans << endl;
}


int main() {
    string expression = "(r-b/v)*(k/p-o)";
    infixToPostfixFunction(expression);
    return 0;
}
