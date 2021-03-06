/*
Alfonso Alfonso Peterssen
16 - 9 - 2007
USACO 2006 JAN Silver "El Prom Bovino"
*/
#include <cstdio>
#include <stack>
using namespace std;

#define problem "d"
#define MAXE 50001
#define MAXV 10000

int V, E, i, j, k, cnt, sol;
int low[MAXV], dfsnum[MAXV];
int P[MAXV];
struct edge { int B, next; } ls[MAXE];
stack< int > S;

  void dfs( int x ) {

    S.push( x );
    dfsnum[x] = low[x] = ++cnt;

    for ( int i = P[x]; i; i = ls[i].next ) {

      int j = ls[i].B;

      if ( !dfsnum[j] ) {
        dfs( j );
        low[x] <?= low[j];
      } else low[x] <?= dfsnum[j];

    }

    if ( low[x] == dfsnum[x] ) {
      if ( S.top() != x ) sol++;
      while ( S.top() != x ) S.pop();
      S.pop();
    }
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &V, &E );
  for ( i = 1; i <= E; i++ ) {

    scanf( "%d %d", &j, &k );

    j--, k--;
    ls[i] = ( edge ) { k, P[j] };
    P[j] = i;
  }

  for ( i = 0; i < V; i++ )
    if ( !dfsnum[i] ) dfs( i );

  printf( "%d\n", sol );

  return 0;
}

/*
Problema 6: El Prom Bovino [Brian Dean, 2004]

Las N (2 <= N <= 10,000) vacas est�n excitadas: �es la noche de su
prom! Ellas est�n vestidas con sus vestidos de etiqueta con sus
ramilletes y zapatos nuevos. Ellas saben que esta noche trataran de
ejecutar el Baile Circular.

Unicamente las vacas pueden ejecutar el Baile Circular el cual tambi�n
requiere un conjunto de cuerdas. Para comenzar, las vacas rodean el
tanque de agua circular y se numeran consecutivamente en orden horario
de 1 a N. Luego ellas adquieren un total de M (2 <= M <= 50,000)
cuerdas, todas las cuales son distribuidas a las vacas quienes las
tienen con sus pezu�as. Cada vaca espera que le den cuerdas para
tenerlas tanto en su pezu�a izquierda como en la derecha; algunas de
ellas ocasionalmente quedan disconformes.

Para que el Baile Circular sea un �xito para cualquier vaca dada (por
ejemplo, Bessie), las cuerdas que ella tiene deben ser configuradas de
la manera correcta. El baile requiere que uno examine el conjunto de
vacas que tiene los otros extremos de sus cuerdas, junto con las vacas
que tengan los otros extremos de cualquier cuerda tenida por cualquier
vaca del conjunto, etc. Cuando Bessie baila en sentido horario
alrededor del tanque, ella jalar� instant�neamente todas las vacas en
su grupo alrededor de manera horaria, tambi�n. De la misma manera, si
ella baila en el otro sentido, ella instant�neamente jalar� todo el
grupo de manera antihoraria.

Por supuesto, si las cuerdas no est�n distribuidas adecuadamente
entonces un conjunto de vacas podr�an no formar un grupo adecuado y
esto no producir�a un �xito en el Baile Circular. Una manera en que
esto podr�a pasar es cuando solo una cuerda conecta dos vacas. Una
vaca podr�a jalar la otra en una direcci�n, pero no podr�a jalarla en
la otra (desde que es un hecho bien conocido que empujar cuerdas no
tiene sentido). Note que las vacas deben bailar en pasos cerrados: una
vaca colgada (tal vez con solo una cuerda) que es jalada eventualmente
descalifica un grupo de ejecutar el Baile Circular desde que no es
jalada inmediatamente en pasos cerrados con el resto.

Dadas las cuerdas y su distribuci�n a las vacas, �Cu�ntos grupos de
vacas pueden ejecutar apropiadamente el Baile Circular? La cuerda
podr�a envolver muchas veces alrededor del tanque de agua, por
supuesto.


NOMBRE DEL PROBLEMA: prom

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio N y M.

* L�neas 2..M+1: Cada l�nea contiene dos enteros separados por espacio
A
        y B que describen una cuerda de la vaca A a la vaca B en
        direcci�n horaria.

ENTRADA EJEMPLO (archivo prom.in):

5 4
2 4
3 5
1 2
4 1

DETALLES DE LA ENTRADA:

La representaci�n en ASCII para un Baile Circular es desafiante. Sin
embargo, aqu� hay una representaci�n de las vacas alrededor del tanque
de agua:

       _1___
      /xxxx \
   5 /xxxxxx 2
  / /xTANQUEx|
  \ \xxxxxxxx/
   \ \xxxxxx/  3
    \ 4____/  /
     \_______/


FORMATO DE LA SALIDA:

* L�nea 1: 	Una sola l�nea con un solo entero que es el n�mero de
grupos
       que bailan exitosamente el Baile Circular.

SALIDA EJEMPLO (archivo prom.out):

1

DETALLES DE LA SALIDA:

Las vacas 1, 2, y 4 est�n conectadas apropiadamente y forman un grupo
completo de Baile Circular. Las vacas 3 y 5 no tienen la segunda
cuerda que ellas necesitan para jalar en ambas direcciones, por lo
tanto ellas no pueden ejecutar apropiadamente el Baile Circular.
*/
