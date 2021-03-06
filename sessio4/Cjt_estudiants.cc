#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}
  
Cjt_estudiants::~Cjt_estudiants() {}
 
void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = 0;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i < nest and not b) {
    if (dni < vest[i].consultar_DNI()) b = true;
    else ++i; 
  }	  
  // b indica que est ha d'anar abans del final i, per tant, cal desplaŤar
  // i es la posicio on ha d'anar est
  if(b) { /* est.consultar_DNI() < vest[i].consultar_DNI() */
    for (int j = nest; j > i; --j) vest[j] = vest[j-1];
  }
  vest[i] = est;
  ++nest;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est,bool& b) {
  //if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");

  int i = 0;
  bool br = false,found = false;
  int dni = est.consultar_DNI();
  while (i < nest and not br and not found) {
    if (dni < vest[i].consultar_DNI()){
        br = true;
    } else if (dni == vest[i].consultar_DNI()){
        found = true;
    }else{
        ++i;
    }
  }
  // b indica que est ha d'anar abans del final i, per tant, cal desplaŤar
  // i es la posicio on ha d'anar est
  if(br and not found) { /* est.consultar_DNI() < vest[i].consultar_DNI() */
    for (int j = nest; j > i; --j) vest[j] = vest[j-1];
  }
  if(not found){
    vest[i] = est;
    b = false;
    ++nest;
  } else {
      b = true;
  }

}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}  

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  vest[i] = est;
}    
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i-1] = est;
}
  
int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}
/*
bool comp(const Estudiant &e1, const Estudiant &e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}
*/
void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,Estudiant::comp);
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}
