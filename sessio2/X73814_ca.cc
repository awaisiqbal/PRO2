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
vector<Estudiant> simplificar_vec(const vector<Estudiant>& vec,int& iterator){
    int size = vec.size();
    int ultimo_dni= vec[0].consultar_DNI();
    double ultima_nota=vec[0].consultar_nota();
    //cout << "DNI: " << ultimo_dni << "\t" << "Nota: "<< ultima_nota<< endl;
    vector<Estudiant> newVec(size);
    for(int i = 1; i < size; ++i){
        //cout << "entrado bucle... (33)" << endl;
        if(vec[i].consultar_DNI()!= ultimo_dni){
            Estudiant est(ultimo_dni);
            if(ultima_nota > -1){
                est.afegir_nota(ultima_nota);
            }
            newVec[iterator] = est;
            ++iterator;
            ultimo_dni = vec[i].consultar_DNI();
            if(vec[i].te_nota()){
                ultima_nota = vec[i].consultar_nota();
            } else {
                ultima_nota = -1;
            }

           // cout << "\tDNI: " << ultimo_dni << "\t" << "Nota: "<< ultima_nota<< endl;
        } else {
            if(vec[i].te_nota() and vec[i].consultar_nota() > ultima_nota and vec[i].consultar_nota() != -1){
                ultima_nota = vec[i].consultar_nota();
            }
        }
    }
   // cout << "newVec.size(): "<< newVec.size() << endl;
    Estudiant est(ultimo_dni);
    if(ultima_nota > -1){
        est.afegir_nota(ultima_nota);
    }
    newVec[iterator] = est;
    ++iterator;
    return newVec;
}

int main()
{
    int n = readint(), iterator = 0;
    vector<Estudiant> vec (n);
    leer_vector(vec);

    vector<Estudiant> v(n);
    v = simplificar_vec(vec,iterator);
    escribir_vector(v,iterator);

}

