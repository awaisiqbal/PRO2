#include "utils.PRO2"
#include "Palabra.hh"
#include <algorithm>



int consultar (const Palabra& p) {
    int sub = 1;
    int max = sub;
    if (p.long_pal() > 1) {
        for (int i = 2; i <= p.long_pal(); ++i) {
            if (p.consultar_letra(i-1) == p.consultar_letra(i)) ++sub;
            else {
                if (max < sub) max = sub;
                sub = 1;
            }
        }
    }
    if (max < sub) max = sub;
    return max;
}

int main()
{

    Palabra p1;
    p1.leer('.');
    if (p1.long_pal() > 0){
        cout << consultar(p1);
    } else {
        cout << "0";
    }
    cout << endl;

}
