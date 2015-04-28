#include<iostream>
#include <stack>
#include "Arbre.hh"

using namespace std;

int midaStack(Arbre<int> a,stack<int> &c)
{
  if (a.es_buit()) return 0;
  else{
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    int y=midaStack(a1,c);
    int z=midaStack(a2,c);
    if(y >= z and not a1.es_buit()){
        c.push(a1.arrel());
    } else if (not a2.es_buit()) {
        c.push(a2.arrel());
    }
    return y+z+1;
  }
}

void invert(stack<int>& p){
    stack<int> c;
    while(not p.empty()){
        c.push(p.top());
        p.pop();
    }
    p = c;
}
void cami_preferent(Arbre<int> &a, stack<int> &c){
    c.push(a.arrel());
    midaStack(a,c);
    invert(c);
}



void escriure_stack_int(stack<int> p)
{
  // el paso por valor copia p correctamente ya que la clase tiene
  // creadora copiadora
  while(not p.empty()){
    cout << p.top() << endl;
    p.pop(); // el que no haya salto de linea entre elementos
  }          // solo interesa si la pila no es muy grande
}

void llegir_arbre_int(Arbre<int>& a, int marca){
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca) {
    llegir_arbre_int(a1, marca);
    llegir_arbre_int(a2, marca);
    a.plantar(x,a1,a2);
  }
}



int main() {
    Arbre<int> a;
    llegir_arbre_int(a,0);
    stack<int> c;
    cami_preferent(a,c);
    escriure_stack_int(c);

}
