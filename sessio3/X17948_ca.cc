#include "utils.PRO2"
#include "Palabra.hh"


/* Pre: cierto */
/* Post: une las 2 palabras */
Palabra pref (const Palabra &p1, const Palabra& p2){
    Palabra p3  ;
    for(int i = 1 ; i <= p1.long_pal();++i ){
        p3.anadir_letra(p1.consultar_letra(i));
    }
    for(int i = 1 ; i <= p2.long_pal();++i ){
       p3.anadir_letra(p2.consultar_letra(i));
    }
    return p3;
}


int main()
{

    Palabra p1;
    p1.leer('.');
    Palabra p2;
    p2.leer('.');
    Palabra p3 = pref(p1,p2);
    p3.escribir();
    cout << endl;

}
