/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Bronze "Palindrome"
*/
#include <fstream>
#include <cstring>
using namespace std;

#define problem "d"

int i;
string st, sol;

  void check( int i, int j ) {

    while ( i >= 0 && j < st.size() &&
            st[i] == st[j] ) i--, j++;

    if ( j - i > sol.size() )
      sol = st.substr( i + 1, j - i - 1 );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> st;

  for ( i = 0; i < st.size(); i++ ) {
    check( i, i );
    check( i, i + 1 );
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 12: Palindrome [Tradicional, 2004]

Un palindrome es una serie de d�gitos (o de letras, si usted quiere)
que se leen lo mismo hacia delante y hacia atr�s. El n�mero 12344321
es un pal�ndrome, as� como 12321 y 3. El n�mero 2468 no es un
pal�ndrome.

Lea un n�mero de hasta 75 d�gitos del archivo de entrad y encuentre el
pal�ndrome m�s grande que ocurre en este n�mero. El pal�ndrome estar�
en cualquier parte y podr�  de dos d�gitos hasta todos los d�gitos del
n�mero y se garantiza que ser� �nico.

NOMBRE DEL PROBLEMA: pal

FORMATO DE ENTRADA:

* L�nea 1: Un solo n�mero de hasta 75 d�gitos de longitud

ENTRADA EJEMPLO (archivo pal.in):

82910341234565432158735

FORMATO DE SALIDA

* L�nea 1: El pal�ndrome mas grande que se encuentre en cualquier
    lugar en el n�mero.

SALIDA EJEMPLO (archivo pal.out):

12345654321

DETALLES DE LA SALIDA:

8291034-->12345654321<--58735
*/
