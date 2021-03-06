/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Vacas Hambrientas"
*/
#include <cstdio>

#define problem "d"
#define MAXN 5000

int N, i, j, sol;
int seq[MAXN], dp[MAXN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );

  for ( i = 0; i < N; i++ ) {

    scanf( "%d", &seq[i] );

    for ( j = 0; j < i; j++ )
      if ( seq[i] > seq[j] && dp[j] + 1 > dp[i] )
        dp[i] = dp[j] + 1;

    sol >?= dp[i];
  }

  printf( "%d\n", sol + 1 );

  return 0;
}

/*
Problema 5: Vacas Hambrientas [Kolstad, 2006]

Cada una de las N (1 <= N <= 5,000) vacas tiene un entero positivo
�nico que es una marca que entra bonito en 32 bits con signo. El
quisiera que las vacas se alinearan en orden num�rico para alimentarse,
pero ellas nunca cooperan. Para alentar el buen comportamiento, �l le
permite a una vaca comer solo si es la primera vaca a ser elegida a
comer o si su n�mero es mayor que la vaca que comi� antes.

Dada una lista de marcas de ordenamientos de vacas para que las vacas
est�n en una l�nea, �cu�l es el mayor n�mero de vacas que pueden comer
usando las reglas de GJ?

Considere esta l�nea de 11 vacas:

2 5 18 3 4 7 10 9 11 8 15

Uno podr�a alimentar a las 2, 3, 4, 7, 10 11, y 15  vacas para un total
de siete alimentadas, el mayor n�mero posible.
Uno no podr�a alimentar a las vacas 2, 5, 3, 10 15 desde que la marca de
la vaca 3 no es mayor que la de su predecesora, 5.

NOMBRE DEL PROBLEMA: lineup

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, N

* L�neas 2..??: Cada l�nea excepto potencialmente la �ltima contiene 20
       enteros separados por espacio que son sucesivamente las marcas de
       las vacas separados por espacio que son sucesivamente las marcas
       de las vacas en la l�nea. La �ltima l�nea podr�a tener menos de 20
       enteros si N no es un m�ltiplo exacto de 20.


ENTRADA EJEMPLO (archivo lineup.in)

11
2 5 18 3 4 7 10 9 11 8 15


FORMATO DE SALIDA

* L�nea 1: La longitud de la cadena m�s grande de vacas donde cada marca
       es mayor m�ltiplo exacto de 20.


SALIDA EJEMPLO (archivo lineup.out)

7
*/
