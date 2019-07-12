#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOkay(char open,char close);
bool isCheck(string exp);

int main() {
    // main func code goes here

    return 0;
}

bool isCheck(string exp){
    stack<char>s;
    int i;

    for(i=0;i<exp.length();i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(s.empty() || !isOkay(s.top(),exp[i])){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;
}

bool isOkay(char open , char close){
    if(open == '(' && open == ')') return true;
     else if(open == '{' && open == '}') return true;
      else if(open == '[' && open == ']') return true;

    return false;
}
