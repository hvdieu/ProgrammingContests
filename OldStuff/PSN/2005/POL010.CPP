//koder: A^2P
//PSN 2005 #10 "Laboratorio de computaci�n"
#include <stdio.h>
#define filein "d.in"
#define fileout "d.out"

long N,i,sol;

int main()
{
  //fload
  freopen(filein,"r",stdin);
  freopen(fileout,"w",stdout);
  
  //dread
  scanf("%ld",&N);
  
  //solve
  for (i = 2; i <= N; i++)
  {
    sol = ((sol * (i % 2005)) + (i & 1 ? -1 : 1)) % 2005;
    if (sol = -1) sol = 2004;
  }
  
  //dprint
  printf("%ld",sol);
  
  //fclose
  fflush(stdout);
}

/*
10� Laboratorio de computaci�n                            Polonia 2005
----------------------------------------------------------------------

En  un  gran  laboratorio   de  computaci�n  las  computadoras   est�n
dispuestas todas en una fila una al lado de la otra. En dicha fila hay
N computadoras las que est�n numeradas  con los n�meros del 1 al  N de
izquierda a derecha. Cada uno de los N estudiantes que trabajan en  el
laboratorio tiene una m�quina preferida. En el laboratorio trabaja  un
t�cnico (de pensamientos muy malos por cierto) que planifica el tiempo
de m�quina asign�ndole a cada estudiante una computadora.

De  cu�ntas  maneras  el  t�cnico  de  laboratorio  puede  hacer   una
planificaci�n  del  tiempo  de m�quina  en  la  que ning�n  estudiante
trabaje en su m�quina preferida.

Tarea

Hacer un programa que permita:

- leer desde el fichero de  entrada LAB.IN el n�mero N de  m�quinas en
  el laboratorio y la m�quina preferida por cada estudiante.

- Determinar el n�mero C de formas que el t�cnico de laboratorio puede
  hacer   una  planificaci�n   del  tiempo  de  m�quina   en  la   que
  ning�n estudiante pueda trabajar en su m�quina preferida. - escribir
  hacia el fichero de salida LAB.OUT  el n�mero  C mod 2005 (resto  de
  la  divisi�n de C entre 2005).

Entrada

El fichero de entrada LAB.IN contiene:

- L�nea 1: N (1 <= N <= 10000000), representa laa cantidad de m�quinas
  en el laboratorio.
- L�nea 2..N+1: en cada una de estas l�neas se escribir� el n�mero  de
  la m�quina preferida por el estudiante   i, o sea, en la l�nea   i+1
  del fichero aparecer� la m�quina preferida por el estudiante i.

Salida

El fichero de salida LAB.OUT contiene en una sola l�nea con el  n�mero
C mod 2005.

Ejemplos de Entrada Salida

  LAB.IN             LAB.OUT

  3                  2
  2
  3
  1
*/
