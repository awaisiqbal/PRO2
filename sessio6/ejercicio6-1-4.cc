#include<iostream>
#include <stack>

using namespace std;

bool parse(string s){
    int size = s.size(), i = 0;
    bool found = false;
    stack<char> p;
    while(not found and i < size){
        cout << s[i] << endl;
        if(s[i]!= ')' and s[i]!=']'){
            p.push(s[i]);
        } else {
            if((p.top() == '(' and s[i] != ')') or (p.top() == '[' and s[i] != ']') ){
                found = true;
            } else {
                p.pop();

            }
        }
        ++i;
    }
    return not found;
}


int main() {
 //string s = "[(()[]())()]";
 string s = "([)(])";
 cout << "PRE PARSE" << endl;
 bool be = parse(s);
 cout << "POST PARSE" << endl;
 if(be){
     cout << "correcto! " << endl;
 } else {
     cout << "incorrecto!! " << endl;
 }
}
