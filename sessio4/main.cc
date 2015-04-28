#include "utils.PRO2"
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"

int main()
{
    Cjt_estudiants ce;
    Estudiant est;
    cout << "Escribe un estudiante <DNI nota>" << endl;
    est.llegir();

  cout << "El estudiante con la nota redondeada, o NP: " <<endl;
  est.escriure();
}
