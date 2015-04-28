#include <iostream>
#include <vector>
using namespace std;

bool calcular(string s, int ini, int end){
    int nivel = 0, i = ini;
    bool cumple1 = false;
    bool found = false;
    while(not(nivel == 0) and (not(found) or i != end){
        if(s[i]=='('){ // caso dodne hay un a expr dentro
            ++nivel;
            int j = i+1;
            int nivelj = nivel;
            while(s[j] != ')' and nivel == nivelj){
                if(s[j]=='('){
                    ++nivelj;

                } else if (s[j] == ')'){
                    --nivelj;
                }
                ++j;
            }
            cumple1 = calcular(s,i,j);

        } else { // caso solamente buscar TAG
            cumple1 = buscar(ini, i);
        }
          found = s[i] == '.' or s[i] == ',';
    }
    if(s[i]==',' and cumple1){
        return true;
    }
    bool cumple2 = calcular(s,i+1,end);
    if((s[i]==',' and cumple2) or (cumple1 and cumple2)){
        return true;
    } else {
        return false;
    }
}

int main()
{
  string s = "((#lleure,#feina).#art)";
  bool cumple = calcular(s,1,s.size()-1);

}
