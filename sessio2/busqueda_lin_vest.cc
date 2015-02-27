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

void escribir_vector(const vector<Estudiant>& vec){
    int size = vec.size();
    for(int i=0; i < size; ++i){
        vec[i].escriure();
    }
}
bool busqueda_lin_vest(Estudiant& est, vector<Estudiant>& vec){
    bool found = false;
    int size=vec.size(), i = 0;
    escribir_vector(vec);
    while(not found and i < size ){
        //cout << "estDNI: " << est.consultar_DNI() << "  vecDNI: " << vec[i].consultar_DNI() << "nota: " << vec[i].consultar_nota() <<  endl;
        found = est.consultar_DNI() == vec[i].consultar_DNI();
        if(found){
            est.afegir_nota(vec[i].consultar_nota());
        }
        ++i;
    }

    return found;
}

int main()
{
    int n = readint();
    vector<Estudiant> vec (n);
    leer_vector(vec);
    int dni_bus = readint();
    Estudiant est(dni_bus);
    bool found =busqueda_lin_vest(est,vec);
    if(found){
        if(est.te_nota()){
            cout << "El estudiante está en el vector y su nota es " <<  est.consultar_nota() << endl;
        } else {
            cout << "El estudiante está en el vector, pero no tiene nota" << endl;
        }
    } else {
        cout << "El estudiante no está en el vector" << endl;
    }

}

