#include "utils.PRO2"

int  main ()
{
  int n = readint();
  int x  = readint();
  while(x != 0){
      n = x+n;
      cout << "La suma de " << x << " i " << n - x << " es " << n <<endl;
      int x=readint();
  }
}

