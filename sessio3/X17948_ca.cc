#include "utils.PRO2"
#include "Palabra.hh"


/* Pre: cierto */
/* Post: el resultado indica si p1 es prefijo de p2 */
void pref (const Palabra &p1, const Palabra& p2, Palabra& p3){
    /*bool b;
    if (p1.long_pal() > p2.long_pal()){
        b= false;
     } else {
        int i = 1;
        b= false;
        while ( not b and i <= p1.long_pal()  ){
            cout << "i: " << i <<  " p1.long: "<< p1.long_pal()  << endl;
            cout << "char 1: " << p1.consultar_letra(i) << " char 2: " << p2.consultar_letra(i) << endl;
            if ( p1.consultar_letra(i) != p2.consultar_letra(i) ){

                 b= true;
            } else {
                 ++i;
            }
        }
    }*/
    //p1.escribir();
    cout << p1.long_pal()<< endl;
    for(int i = 1 ; i <= p1.long_pal();++i ){
        cout << p1.long_pal()<< endl;
        cout << p1.consultar_letra(i) << " ";
        p3.anadir_letra(p1.consultar_letra(i));
    }
    for(int i = 1 ; i <= p2.long_pal();++i ){
        cout << p2.consultar_letra(i) << " ";
        p3.anadir_letra(p2.consultar_letra(i));
    }
    p3.escribir();
//return b;
}


int main()
{

    Palabra p1;
    p1.leer('.');
    //p1.anadir_letra('a');
    //p1.escribir();
    Palabra p2;
    p2.leer('.');
    //p2.escribir();
    Palabra p3;
    pref(p1,p2,p3);
    p3.escribir();

}
