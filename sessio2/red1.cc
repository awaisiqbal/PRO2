#include "utils.PRO2"
#include "Estudiant.hh"
#include <vector>

// Redondear, version funcion

Estudiant redondear_e_f(const Estudiant & est)
/* Pre: est tiene nota */
/* Post: el resultado es un estudiante como est pero con la nota redondeada */
{
  Estudiant est2(est.consultar_DNI());
  double notaR = ((int) (10.0 * (est.consultar_nota() + 0.05))) / 10.0;
  est2.afegir_nota(notaR);
  return est2;
}

// Redondear, version accion

void redondear_e_a(Estudiant & est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

Estudiant leer_estudiante(){
    Estudiant est;
    cout << "Escribe un estudiante <DNI nota>" << endl;
    est.llegir();
    return est;
}
void leer_vector(vector<Estudiant>& vec){
    int size = vec.size();
    for(int i=0; i < size; ++i){
        vec[i] = leer_estudiante();
    }
}

void redondear_vector(vector<Estudiant>& vec){
    int size = vec.size();
    for(int i=0; i <= size; ++i){
        Estudiant est = vec[i];
        if (est.te_nota()) { // comprobamos la precondicion
          //est=redondear_e_f(est);	// version funcion, en este caso es ineficiente
          redondear_e_a(est);    // version accion
        }
    }
}

void escribir_vector(const vector<Estudiant>& vec){
    int size = vec.size();
    for(int i=0; i < size; ++i){
        vec[i].escriure();
    }
}
int main()
{
    int n = readint();
    vector<Estudiant> vec (n);
    leer_vector(vec);
    redondear_vector(vec);
    escribir_vector(vec);

}
