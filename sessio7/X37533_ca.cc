#include<iostream>
#include "Arbre.hh"

using namespace std;
int alcaria(Arbre<int>& a, Arbre<int> &agd) {
    if (a.es_buit()) return 0;
    else {
        Arbre<int> a1, a2, agd1,agd2;
        a.fills(a1, a2);
        int y = alcaria(a1,agd1);
        int z = alcaria(a2,agd2);
        agd.plantar(y- z,agd1,agd2);
        if (y >= z) return y + 1;
        else return z + 1;
    }
}

void arbre_graus_desequilibri(Arbre<int> &a, Arbre<int> &agd){
    alcaria(a,agd);
}
/*
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
void escriure_arbre_int(Arbre<int> &a) {
  if (not a.es_buit()) {
    Arbre<int> a1;
    Arbre<int> a2;
    int x = a.arrel();
    a.fills(a1,a2);
    escriure_arbre_int(a1);
    cout << " " << x;
    escriure_arbre_int(a2);
    a.plantar(x,a1,a2);
  }
}


int main() {
    Arbre<int> a;
    llegir_arbre_int(a,0);
    Arbre<int> agd;
    arbre_graus_desequilibri(a,agd);
    escriure_arbre_int(agd);

}
*/
