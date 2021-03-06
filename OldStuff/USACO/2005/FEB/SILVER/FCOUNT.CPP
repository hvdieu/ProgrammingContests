/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Silver "Contabilidad de Comida"
*/
#include <cstdio>

#define problem "d"
#define MAXD 2001

int C, F1, F2, D, i, j, k;
int cnt[MAXD];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d %d %d", &C, &F1, &F2, &D );

  for ( i = 0; i < C; i++ ) {
    scanf( "%d %d", &j, &k );
    for ( ; j <= k; j++ )
      cnt[j]++;
  }

  j = 0;
  for ( i = D; i; i-- )
    if ( j >= F1 - F2 ) break;
    else j += cnt[i];

  printf( "%d\n", i + 1 );

  return 0;
}

/*
Problema 8: Contabilidad de Comida [Hal Burch, 2004]

El Granjero Juan est� tratando de averiguar cuando lleg� su �ltimo
cargamento de comida. Comenzando con un dep�sito vac�o de comida, �l
orden� y recibi� F1 (1 <= F1 <= 1,000,000) kilogramos de comida.
Desafortunadamente, �l no est� seguro de cuando lleg� la comida
exactamente. De los F1 kilogramos, F2 (1 <= F2 <= F1) kilogramos de
comida permanecen en el d�a D (1 <= D <= 2,000). El debe determinar el
d�a m�s reciente en que su cargamento podr�a haber llegado.

Cada una de sus C (1 <= C <= 100) vacas come exactamente 1 kilogramo de
comida cada d�a. Por diferentes razones, las vacas llegan un d�a y se van
en otro, por lo tanto los d�as podr�an tener diferentes consumos de
comida. Los datos de entrada dicen en que d�as cada vaca estaba presente.
Cada vaca comi� comida del dep�sito del Granjero Juan el d�a en que ella
lleg� y tambi�n el d�a en que ella se fue.

Dado que hoy es el d�a D, determine el m�nimo n�mero de d�as que deben de
haber pasado desde su �ltimo cargamento. Las vacas ya han comido hoy, y
el cargamento lleg� antes de que las vacas comenzaran a comer.

NOMBRE DEL PROBLEMA: fcount

FORMATO DE ENTRADA:

* L�nea 1: Cuatro enteros seprados por espacios: C, F1, F2 y D.

* L�neas 2..C+1: La l�nea i+1 contiene dos enteros separados por espacio
    describiendo la presencia de una vaca. El primer entero dice el primer
    d�a en que la vaca estuvo en la granja; el segundo dice el d�a final
    de su presencia. Cada d�a est� en el rango 0..2,000.

ENTRADA EJEMPLO (archivo fcount.in):

3 14 4 10
1 9
5 8
8 12

DETALLES DE LA ENTRADA:

El cargamento m�s reciente fue de 14 kilogramos de comida, y el Granjero
Juan tiene 4 kilogramos sobrantes. El tuvo tres vacas que comieron comida
por alguna cantidad de tiempo durante los �ltimos 10 d�as.

FORMATO DE SALIDA:

El �ltimo d�a en que el cargamento podr�a haber llegado, un entero que
ser� siempre positivo.

SALIDA EJEMPLO (archivo fcount.out):

6

DETALLES DE LA SALIDA:

Si el Granjero Juan comenz� con 14 kg de comida en el d�a 6,
entonces en los d�as 6 y 7, se hubieran comido dos kilogramos cada d�a.
En el d�a 8, se hubieran comido tres kilogramos. En el d�a 9, se hubieran
comido dos kilogramos. En el d�a 10, se hubiera comido un kilogramo. Por
lo tanto, el total comido hubiera sido 2 + 2 + 3 + 2 + 1 = 10, dej�ndolo
con 4 kilogramos.
*/
