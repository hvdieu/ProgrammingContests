/*
Alfonso Alfonso Peterssen
15 - 7 - 2007
USACO 2005 MAR Gold "Elevador Espacial"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 400
#define MAXH 40001

int N, i, j;
int last[MAXH], cant[MAXH];

struct block {

  int len, cnt, limit;

  bool operator < ( const block &x ) const {
    return limit < x.limit;
  }

} ls[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].len >> ls[i].limit >> ls[i].cnt;

  sort( ls, ls + N );

  cant[0] = last[0] = -1;
  for ( i = 0; i < N; i++ )
    for ( j = ls[i].len; j <= ls[i].limit; j++ ) {

      int back = j - ls[i].len;

      if ( cant[back] == 0 || cant[j] != 0 )
        continue;

      if ( last[back] == i ) {
        if ( cant[back] < ls[i].cnt ) {
          last[j] = i;
          cant[j] = cant[back] + 1;
        }
      } else {
        last[j] = i;
        cant[j] = 1;
      }
    }

  for ( i = ls[N - 1].limit; !cant[i]; i-- );

  fout << i << endl;

  return 0;
}

/*
Problema 2: Elevador Espacial [Entrenadores, 2004]

�Las vacas est�n yendo al espacio! Ellas planean entrar en �rbita
construyendo una especie de elevador espacial: una torre gigante de
bloques. Ellas tienen K (1 <= K <= 400) tipos diferentes de bloques
con los que cuales construir la torre. Cada tipo de bloque i tienen
una altura h_i (1 <= h_i <= 100) y est� disponible en cantidad c_i (1
<= c_i <= 10). Debido a posibles da�os producidos por rayos c�smicos,
ninguna parte de un bloque de tipo i puede exceder una altura m�xima
a_i (1 <= a_i <= 40000).

Ayude a las vacas a construir el elevador espacial m�s alto posible
apilando bloques uno encima del otro de acuerdo a las reglas.

NOMBRE DEL PROBLEMA: elevator

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, K

* L�neas 2..K+1: Cada l�nea contiene tres enteros separados por
    espacio: h_i, a_i, y c_i. La l�nea i+1 describe el bloque de tipo
    i.

ENTRADA EJEMPLO (archivo elevator.in):

3
7 40 3
5 23 8
2 52 6

FORMATO DE SALIDA:

* L�nea 1: Un solo entero H, la m�xima altura con la que se puede
    construir una torre.

SALIDA EJEMPLO (archivo elevator.out):

48

DETALLES DE LA SALIDA:

Desde abajo: 3 bloques de tipo 2, debajo de 3 de tipo 1, debajo de 6
de tipo 3. Apilar 4 bloques de tipo 2 y 3 de tipo 1 no es legal, desde
que la parte superior del �ltimo bloque de tipo 1 exceder�a la altura
40.
*/
