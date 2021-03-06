/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
PSN 2003 #13 "Huna zerka dekoratiba"
*/
#include <iostream>
using namespace std;

#define MAXN 21

typedef long long int64;

int T ,N, i, j, k, dir, last;
int64 C;
int64 dp[2][MAXN][MAXN];
int sol[MAXN];
bool used[MAXN];

int main() {

  /* Init */
  dp[0][1][1] = dp[1][1][1] = 1;
  for ( i = 2; i < MAXN; i++ )
    for ( j = 1; j <= i; j++ ) {

      /* down */
      for ( k = 1; k < j; k++ )
        dp[0][i][j] += dp[1][i - 1][k];

      /* up */
      for ( k = j; k < i; k++ )
        dp[1][i][j] += dp[0][i - 1][k];
    }

  for ( cin >> T; T; T-- ) {

    cin >> N >> C;

    /* Find First */
    for ( i = 1; i < MAXN; i++ ) {

      dir = 0;
      if ( C > dp[0][N][i] ) C -= dp[0][N][i];
      else break;

      dir = 1;
      if ( C > dp[1][N][i] ) C -= dp[1][N][i];
      else break;
    }

    /* Find the rest */
    sol[N] = last = i;
    for ( i = N - 1; i; i-- ) {

      dir ^= 1;

      if ( dir ) {
        for ( j = 1; j < last; j++ )
          if ( C > dp[1][i][j] ) C -= dp[1][i][j];
          else break;
      } else
        for ( j = last; j <= i; j++ )
          if ( C > dp[0][i][j] ) C -= dp[0][i][j];
          else break;

      sol[i] = last = j;
    }

    /* Print */
    for ( i = 1; i <= N; i++ )
      used[i] = false;

    for ( i = N; i; i-- )
      for ( j = 1; j <= N; j++ )
        if ( !used[j] )
          if ( --sol[i] == 0 ) {
            used[j] = true;
            if ( i > 1 )
                 cout << j << ' ';
            else cout << j << endl;
            break;
          }
  }

  return 0;
}

/*
13� Una cerca decorativa.                                     USA 2003
----------------------------------------------------------------------

Richard justamente  terminaba  de  construir  su nueva casa. Ahora  la
�nica cosa que le faltaba a la  casa es una linda cerca de madera.  El
no ten�a ninguna idea de c�mo  hacer una cerca de madera,  por  lo que
�l decidi�  pedir  una.   De alg�n modo  �l  consigui� de manos de  la
ACME (Una Compa��a que Hace Todo) del Cat�logo de Cercas del 2002,  la
�ltima fuente de lindas cercas  de madera. Despu�s de leer  su pr�logo
�l supo ya, como hacer una linda cerca de madera.

Una  cerca  de  madera  consiste  de  N  tablones  de  madera, puestos
verticalmente seguidos uno al lado de otro. Una cerca parece bonita si
y s�lo si re�ne las siguientes condiciones:

* Los tablones tienen longitudes diferentes, particularmente 1, 2,...,
  N unidades de longitud.

* Cada  tabl�n  con  dos  vecinos o  es m�s grande que cada uno de sus
  vecinos o m�s peque�o que cada uno de ellos. (Note que esto hace que
  la cima suba alternadamente de la cerca y se baje).

Nosotros podemos describir cada cerca  bonita con N tablones como  una
permutaci�n a[1], ...,  a[N] de los  n�meros desde 1,  ..., N tal  que
(para  todo i;  1 <  i <  N) (a[i]  - a[i-1])*(a[i]  - a[i+1])  > 0  y
viceversa, cada permutaci�n describe una cerca bonita.

Es obvio, que hay muchas cercas de madera bonitas diferentes hechas de
N  tablones.  Para traer alg�n orden en su cat�logo, el gerente de las
ventas  de  ACME  decidi�  pedirlos  de  la  manera siguiente: Cerca A
(representado por la permutaci�n a[1], ..., a[N]) est� en el  cat�logo
antes de la cerca  B (representado por b[1],  ..., b[N]) si y  s�lo si
all� existe tal i que (para todo j  < i) a[j] = b[j] y (a[i] <  b[i]).
(Tambi�n  para decidir,  cu�l de  las dos  cercas est�  primero en  el
cat�logo, tome sus permutaciones correspondientes, encuentre el primer
lugar en el que ellas difieren y comparar los valores de este  lugar.)
Todos las cercas bonitas con N tablones se enumeran (empezando por  1)
en el orden aparecen en el cat�logo. Este n�mero se llama su n�mero de
cat�logo.

    ++   ++      ++      ++   ++      ++     ++    ++    ++     ++
  ++��   ��++    �++   ++��   ��    ++��   ++��   +��    ��++   ��++
  �+��   �+��  ++���  +����  +��++  ���++  �+��   ���++  ���++  �+��
 +����   ����  �����  �����  �����  �����  ����   �����  �����  ����
 �����  +����  �+���  ��+��  ��+��  �+���  ���++  ��+��  �+���  ���++
----------------------------------------------------------------------
   Todas  las cercas fabricada de N=4 tablones, ordenadas por su n�mero
   de cat�logo

Despu�s de examinar cuidadosamente todas las cercas bonitas de madera,
Richard decidi�  pedir algunas  de ellos.  Para cada  una de  ellas �l
anot� el  n�mero de  sus tablones  y su  n�mero de  cat�logo. Despu�s,
cuando �l se encontr� a sus amigos, �l quiso mostrarles las cercas que
�l pidi�, pero perdi� el cat�logo  en alguna parte. La �nica cosa  que
�l tiene son sus notas. Por favor ay�dele a averiguar, c�mo quiere que
aparezcan sus cercas.

Entrada

La  primera l�nea del archivo de entrada FENCE.IN contiene el n�mero K
(1 <=  K <=  100), el  conjunto de  datos de  la entrada. Las K l�neas
siguientes, cada una de ellas describe un juego de datos de entrada.

Cada una de las K l�neas siguientes contiene dos enteros N y C (1 <= N
<=  20),  separados  por  un espacio. N es el n�mero de tablones en la
cerca, C es el n�mero de cat�logo de la cerca.

Usted  puede  asumir,  que el n�mero total de cercas de madera  con 20
tablones  cabe  en  una variable entera de 64-bit (long long en C/C++,
int64 en  FreePascal). Usted  tambi�n puede  asumir que  la entrada es
correcta, en  particular que  C tiene  por lo  menos 1  y no excede el
n�mero de cercas bonitas con N tablones.

Salida

Para  cada  conjunto de  datos  de la  entrada  el archivo  de  salida
FENCE.OUT  tendr�  una  l�nea, describiendo  la  C-�sima  cerca con  N
tablones en el cat�logo. M�s precisamente, si la cerca es descrita por
la permutaci�n a[1], ..., a[N], entonces la l�nea correspondiente  del
archivo del salida debe contener el n�mero a[i] (en el orden
correcto), separados por simples espacios.

Ejemplo de Entrada y Salida:

+----------+    +-----------+
� FENCE.IN �    � FENCE.OUT �
+----------�    +-----------�
� 2        �    � 1 2       �
� 2 1      �    � 2 3 1     �
� 3 3      �    +-----------+
+----------+
*/
