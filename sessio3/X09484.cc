#include "utils.PRO2"
#include "Palabra.hh"
#include <algorithm>


bool ordenar (const Palabra& p1, const Palabra& p2) {
    int k1 = p1.long_pal();
    int k2 = p2.long_pal();
    if (k1 != k2) return false;
    vector<int> v1(74);
    for (int i = 1; i <= k1; ++i) {
        v1[int(p1.consultar_letra(i)-'0')] += 1;
        v1[int(p2.consultar_letra(i)-'0')] -= 1;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != 0) return false;
    }
    return true;
}

int main()
{

    Palabra p1;
    p1.leer('.');
    Palabra p2;
    p2.leer('.');
    bool b = ordenar(p1,p2);
    if(b){
        cout << "SI";
    } else {
        cout << "NO";
    }
    cout << endl;

}
