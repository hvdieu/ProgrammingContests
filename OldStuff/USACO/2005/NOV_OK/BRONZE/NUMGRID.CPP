/*
Alfonso Alfonso Peterssen
11 - 8 - 2007
USACO 2005 NOV Bronze "Tablero"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 1000000

int i, j, sol;
bool mark[MAXN];
int mat[5][5];

  void dfs( int x, int y, int len, int num ) {

    if ( len == 6 ) {
      if ( !mark[num] ) {
         mark[num] = true;
         sol++;
      }
      return ;
    }

    num = num * 10 + mat[x][y];
    if ( x > 0 ) dfs( x - 1, y, len + 1, num );
    if ( x < 4 ) dfs( x + 1, y, len + 1, num );
    if ( y > 0 ) dfs( x, y - 1, len + 1, num );
    if ( y < 4 ) dfs( x, y + 1, len + 1, num );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( i = 0; i < 5; i++ )
    for ( j = 0; j < 5; j++ )
      fin >> mat[i][j];

  for ( i = 0; i < 5; i++ )
    for ( j = 0; j < 5; j++ )
      dfs( i, j, 0, 0 );

  fout << sol << endl;

  return 0;
}

/*
Problema 12: Tablero [Hal Burch, 2005]

Las vacas se inventaron un juego que consiste en un tablero de 5x5 casillas
pintado en el piso paralelo a los ejes x y y en el cual ellas brincan. En cada
una de las casillas est� escrito un d�gito.

Ellas saltan h�bilmente en cualquier d�gito del tablero y de ah� a otro en alg�n
d�gito adyacente, hacia delante, hacia atr�s, hacia la derecha, o hacia la
izquierda (nunca en diagonal). Vuelven a saltar nuevamente (mismas reglas) a otro
d�gito (potencialmente un d�gito ya visitado).

Con un total de cinco saltos entre casillas, sus saltos crean un entero de seis
d�gitos (el cual podr�a tener ceros a la izquierda como 000201).

Determine el n�mero de distintos enteros que pueden ser creados de esta manera.

NOMBRE DEL PROBLEMA: numgrid

FORMATO DE ENTRADA:

* L�neas 1..5: El tablero, cinco d�gitos separados por espacios por l�nea.


ENTRADA EJEMPLO (archivo numgrid.in):

1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1

FORMATO DE SALIDA:

L�nea 1: El n�mero de enteros distintos que pueden ser construidos

SALIDA EJEMPLO (archivo numgrid.out):

15

DETALLES DE LA SALIDA:

111111, 111112, 111121, 111211, 111212, 112111, 112121, 121111, 121112,
121211, 121212, 211111, 211121, 212111, y 212121 pueden ser construidos.
No son posibles otros valores.
*/
