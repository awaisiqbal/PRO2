/**
 * @mainpage Ejemplo de diseño modular:  Factor Psi.
 
En este ejemplo se construye un programa modular que, dado un texto marcado,
obtiene la frecuencia de la palabra más frecuente del mismo. Se introducen 
las clases <em> Palabra</em> y <em> ListaPalabras</em>.
*/

/** @file pro2_s52.cc
    @brief Programa principal para el ejercicio <em>Factor Psi</em>.
*/

#include "Palabra.hh" // para que el diagrama modular quede bien
#include "ListaPalabras.hh"


/** @brief Programa principal para el ejercicio <em>Factor Psi</em>.
*/
int main ()
{
    ListaPalabras lp;
    cout << "escribe la primera letra" << endl;
    Palabra p;
    p.leer('.');
    while(p.long_pal() != 0){
        p.escribir();
        cout << endl;
        //cout << "long: " << p.long_pal() << endl;
        lp.anadir_palabra(p);
        p.leer('.');
    }
    cout << "max freq: " << lp.max_frec() << endl;
    lp.escribir();
}
