#include "utils.PRO2"
#include "Estudiant.hh"
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

int main()
{
    int m = readint();
    int n = readint();
    int s = readint();
    vector<bool> subconjuntoS(n,false);
    for(int i =0; i < s;++i){
        int pos = readint();
        subconjuntoS[pos - 1] = true;
    }
    for(int i = 0; i < m; ++i){     // tratar cada alumno
        int dni = readint();
        //cout << "dniEntry: "<< dni<< endl;
        double suma = 0;
        for(int i = 0; i < n; ++i){
            if(subconjuntoS[i]){
                double asd = readdouble();
                suma = suma + asd;
            } else {
                readdouble();
            }
        }
       // cout << "suma:  " << suma << endl;
        double nota_media = suma / s;
        //cout << "DNI: " << dni << "\tNOTA:" << nota_media<< endl<< endl;
        Estudiant est(dni);
        est.afegir_nota(nota_media);
        est.escriure();

    }

}

