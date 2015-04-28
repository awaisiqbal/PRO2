#include<iostream>
#include<vector>

using namespace std;

 int solitaris(const vector<int> &v){
     int soli, size = v.size();
     if(size != 0 and v[0] != v[1]){
         soli = 1;
     } else {
         soli = 0;
     }
     for(int i = 1; i < size -1 ; ++i){
         if(v[i] != v[i+1] and v[i-1] != v[i]) ++soli;
     }
     if(v[size -2] != v[size -1]){
         ++soli;
     }
     return  soli;
 }

/*
int main() {
    vector<int> v(9) ;
    v[0] = -7;
    v[1] = 5;
    v[2] = 5;
    v[3] = 5;
    v[4] = -2;
    v[5] = 2;
    v[6] = 5;
    v[7] = 1;
    v[8] = 1;

    cout << solitaris(v)<< endl;

}
*/
