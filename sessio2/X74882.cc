#include "utils.PRO2"
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <vector>



Estudiant leer_estudiante(){
    Estudiant est;
    //cout << "Escribe un estudiante <DNI nota>" << endl;
    est.llegir();
    return est;
}
void leer_vector(vector<Estudiant>& vec){
    int size = vec.size();
    for(int i=0; i < size; ++i){
        vec[i] = leer_estudiante();
    }
}

void escribir_vector(const vector<Estudiant>& vec,int limit){
    //int size = vec.size();
    for(int i=0; i < limit; ++i){
        vec[i].escriure();
    }
}
/**
 * @brief compara las notas del estudiante y coge la nota mas alta y la pone en el est1.
 * @param est1
 * @param est2
 */
void comparar_nota(Estudiant& est1,Estudiant& est2){
    if(est1.te_nota() and est2.te_nota()){
        double nota1 = est1.consultar_nota(),nota2 = est2.consultar_nota();
        if(nota2 > nota1){
            est1.modificar_nota(nota2);
        }
    } else if ( not est1.te_nota() and est2.te_nota()){
        est1.afegir_nota(est2.consultar_nota());
    }
}

int main()
{
    Cjt_estudiants cjt1;
    //cout << "Escriu la mida del conjunt i els elements" << endl;
    cjt1.llegir();
    Cjt_estudiants cjt2;
    //cout << "Escriu la mida del conjunt i els elements" << endl;
    cjt2.llegir();

    int size = cjt1.mida();
    for(int i = 0; i < size; ++i){
        Estudiant est = cjt1.consultar_iessim(i+1);
        //cout << "\t consultando: "  << i+1 << "consigue: " << est.consultar_DNI() << endl;
        if(cjt2.existeix_estudiant(est.consultar_DNI())){
            Estudiant est2 = cjt2.consultar_estudiant(est.consultar_DNI());
            //cout << "\t\t Existe: " << est2.consultar_DNI() << endl;
            comparar_nota(est,est2);
            cjt1.modificar_iessim(i+1,est);
        }

    }
    //cout << "Primer conjunt actualitzat" << endl;
    cjt1.escriure();



}

