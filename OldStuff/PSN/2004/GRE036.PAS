{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #36 "Estantes"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,M,S,i,j,k     : longint;
  C,h             : array[-2..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  readln(fin,S);
  for i:=1 to S do
  begin
    read(fin,j,k);
    if k > h[j] then h[j] := k;
  end;{for}

  {slve}
  for i:=1 to N do
    C[i] := min( C[i - 1] + h[i],
                 min( C[i - 2] + max(h[i],h[i - 1]),
                      C[i - 3] + max(h[i],max(h[i - 1],h[i - 2]))));

  {dprint}
  writeln(fout,C[N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
36� Estantes.                                              Grecia 2004
����������������������������������������������������������������������

Una estanteria en un departamento de policia consiste de estantes que
est�n organizados en C columnas y R filas. Para alcanzar un objeto de
alg�n estante una escalera tiene que ser usada. Una escalera puede ser
recostada contra una columna de estantes solamente. Subiendo en la
escalera a cierta altura (fila) es posible tomar algun objeto de esa
columna hasta la altura ascendida incluyendo los objetos de las
columnas (izquierda y derecha) adyacentes.

Un policia necesita tomar ciertos objetos del estante. Para disminuir
el riesgo de lesi�n en el trabajo es necesario encontrar una via para
tomar todos los objetos necesitados del estante tal que la altura
total de todas las subidas sea la minima posible. La altura total es
la suma de las alturas de todas las subidas. Los objetos en los
estantes son dados.

Escriba un programa que determine la minima altura posible de todas
las subidas necesarias para recoger todos los objetos de los estantes.

Entrada

La primera linea del fichero de entrada SHELVES.IN contien dos enteros
C y R, 1 <= C <= 100, 1 <= R <= 100, numero de columnas y numero de
filas, separados por un caracter espacio. La segunda linea contiene un
entero N, 1 <= N <= 100, numero de estantes que se necesitan alcanzar.
Cada uno de las pr�ximas N lineas contienen dos enteros A y B, 1 <= A
<= C, 1 <= B <= R, separados por un caracter espacio, numero de
columna y fila del estante que necesita se alcanzado.

Salida

La primera y �nica linea del fichero de salida SHELVES.OUT debe
contener la posible altura total minima de subidas necesarias para
alcanzar todos los estantes dados.

Ejemplo de Entrada y Salida

 Ejemplo #1         Ejemplo #2        Ejemplo #3
������������Ŀ     ������������Ŀ    ������������Ŀ
� SHELVES.IN �     � SHELVES.IN �    � SHELVES.IN �
������������Ĵ     ������������Ĵ    ������������Ĵ
� 5 5        �     � 6 20       �    � 10 10      �
� 3          �     � 4          �    � 5          �
� 2 3        �     � 5 6        �    � 9 1        �
� 3 4        �     � 1 1        �    � 7 6        �
� 4 4        �     � 6 1        �    � 5 8        �
��������������     � 3 7        �    � 4 1        �
�������������Ŀ    ��������������    � 3 2        �
� SHELVES.OUT �    �������������Ŀ   ��������������
�������������Ĵ    � SHELVES.OUT �   �������������Ŀ
� 4           �    �������������Ĵ   � SHELVES.OUT �
���������������    � 9           �   �������������Ĵ
                   ���������������   � 11          �
                                     ���������������
}
