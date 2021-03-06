#include "utils.PRO2"
#include <vector>
#include <algorithm>

struct parint {
    int gol1, gol2;
};
struct equipo {
    int ident,puntos,golesF,golesC;
};

typedef vector <vector<parint> > Matriz;
typedef vector <equipo> Clas;


int leerMatriz_int(Matriz& m)
{
  int numN=readint();
  m =  Matriz (numN, vector<parint>(numN));

  for (int i=0; i<numN;++i)
    {
      for (int j=0; j<numN;++j)
      {
        m[i][j].gol1 = readint();
        m[i][j].gol2 = readint();
      }
    }
    return numN;
}

void escribirMatriz_clas2(const Clas& m)
{
  for (int i=0; i<m.size();++i)
    {
        cout << m[i].ident + 1 << " ";
        cout << m[i].puntos << " ";
        cout << m[i].golesF << " ";
        cout << m[i].golesC ;
        cout << endl;
    }
}

void comprobar_equipo(int& golesFavor, int& golesContra, int& puntos, bool esI, const parint& partido){
    if (partido.gol1 == partido.gol2) ++puntos;
    if(esI){
        if(partido.gol1 > partido.gol2){
            puntos += 3;
        }
        golesFavor += partido.gol2;
        golesContra += partido.gol1;
    } else {
        if(partido.gol2 > partido.gol1){
            puntos += 3;
        }
        golesFavor += partido.gol1;
        golesContra += partido.gol2;
    }
}
bool comp(const equipo& a,const equipo& b){
    if(a.puntos == b.puntos){
        int indGolA = a.golesF - a.golesC;
        int indGolB = b.golesF - b.golesC;
        if(indGolA == indGolB){
            return a.ident < b.ident;
        } else {
            return indGolA > indGolB;
        }
    } else {
        return a.puntos > b.puntos;
    }

}

int  main ()
{
    Matriz m1;
    int size = leerMatriz_int(m1);
    Clas clas = Clas(size);
    for(int i =0; i < size; ++i ){
        int golesFavor = 0,golesContra = 0,puntos = 0;
        for (int j=0; j < size;++j)
        {
            if(j != i){
                //comprobar puntuacion vertical m[j][i]
                comprobar_equipo(golesFavor,golesContra,puntos,true,m1[j][i]);
            }
        }

        for (int j=0; j < size ; ++j)
        {
            if(j != i){
                comprobar_equipo(golesFavor,golesContra,puntos,false,m1[i][j]);
                //comprobar puntuacion horizontal m[i][j]
            }
        }
        equipo e;
        e.ident = i;
        e.golesF = golesFavor;
        e.golesC = golesContra;
        e.puntos = puntos;
        clas[i] = e;
    }


    sort(clas.begin(),clas.end(),comp);

    //escribirMatriz_clas(clas);
     escribirMatriz_clas2(clas);

}






