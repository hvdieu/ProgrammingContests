/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Construyendo el Foso"
*/
#include <cstdio>
#include <cmath>

#define problem "d"
#define MAXN 5000
#define sqr( x ) ( ( x ) * ( x ) )

int N, i, j;
int start, last, next;
int X[MAXN], Y[MAXN];
double sol;

  int cross( int o, int c, int m ) {
    /*
      < 0 counterclockwise
      = 0 collinear
      > 0 clockwise
    */
    return ( X[c] - X[o] ) * ( Y[m] - Y[o] ) -
           ( X[m] - X[o] ) * ( Y[c] - Y[o] );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d %d", &X[i], &Y[i] );

  /* Convex Hull -> Jarvis-March ( Gift Wrapping ) */
  for ( i = 1; i < N; i++ )
    if ( X[i] < X[start] ) start = i;

  last = start;
  do {

    next = ( last == 0 );

    for ( i = 0; i < N; i++ )
      if ( cross( last, next, i ) > 0 )
        next = i;

    sol += sqrt( sqr( X[next] - X[last] ) +
                 sqr( Y[next] - Y[last] ) );

    last = next;

  } while ( next != start );

  printf( "%.2lf\n", sol );

  return 0;
}

/*
Problema 6: Construyendo el Foso [Eric Price, 2006]


Para repeler la invasi�n de zarig�eyas sedientas, el Granjero Juan (GJ)
quiere construir un foso alrededor de su granja. El posee N
(8 <= N <= 5,000) pozos de agua, y excavar� el foso como l�neas rectas
entre pares de ellos. Su foso debe proteger (rodear) todos los pozos;
cada pozo deber� estar dentro del foso, y el foso debe ser cerrado.

Excavar el foso es un trabajo costoso, y GJ quiere que su foso tenga la
m�nimalongitud posible. Encuentre la longitud del foso m�s peque�o que �l
pueda construir.

Los pozos est�n ubicados en coordenadas enteras en el rango (1..45,000,
1..45,000). GJ se ha dado cuenta que no hay tres pozos en la misma l�nea
recta.

Considere esta cuadrilla con a lo m�s dos docenas de '*'s representando
pozos:

...*-----------------*......
../..........*........\.....
./.....................\....
*......................*\...
|..........*........*....\..
|*........................\.
|..........................*
*..........................|
.\*........................|
..\.....................*..|
...\........*............*.|
....\..................*...*
.....\..*..........*....../.
......\................../..
.......*----------------*...

Las l�neas envolventes forman el camino m�s corto posible que encierra este
conjunto de pozos.

Los desplazamientos lineales, comenzando en la l�nea superior son : (18,0),
(6,-6), (0,-5), (-3,-3), (-17,0), (-7,7), (0,4), y (3,3).  Esto da una
distancia de 70.8700576850888(...).. Nuestra salida imprimir� solo dos
decimales, por lo tanto la distancia ser� reportada como 70.87.



NOMBRE DEL PROBLEMA: moat

FORMATO DE ENTRADA:

* L�nea  1: Un solo entero, N

* L�neas 2..N+1: Dos enteros separados por espacio, X_i y Y_i que especifican
      la ubicaci�n de un pozo

ENTRADA EJEMPLO (archivo moat.in):

20
2 10
3 7
22 15
12 11
20 3
28 9
1 12
9 3
14 14
25 6
8 1
25 1
28 4
24 12
4 15
13 5
26 5
21 11
24 4
1 8

FORMATO DE SALIDA:

* L�nea 1: Un solo entero D, la longitud m�s peque�a posible de un foso.
       Imprima este n�mero con dos n�meros decimales.

SALIDA EJEMPLO (archivo moat.out):

70.87
*/
