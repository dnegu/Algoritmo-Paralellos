#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef size_t ST;
typedef int** MI;

/**
Pregunta Numero 1
**/

MI TNL3(MI &A,MI &B,ST tam)
{
    ST i,j,k;
    MI C;
    C=new int*[tam]; /*Uso de Memoria*/
    for(int i=0;i<tam;i++)
        C[i]=new int[tam]; /*Uso de Memoria*/

    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            for(k=0;k<tam;k++)
            C[i][j]+=A[i][k]*B[k][j]; /*Uso de Memoria*/
    return C;
}

void print(MI &A,ST tam)
{
    ST i,j;
    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    cout<<"_______________________________"<<endl;
}

void llenar(MI& A,ST tam)
{
    A=new int*[tam];  /*Uso de Memoria*/
    for(int i=0;i<tam;i++)
        A[i]=new int[tam]; /*Uso de Memoria*/

    ST i,j;
    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            A[i][j]=rand() % 10 + 1; /*Uso de Memoria*/
}

/**
Pregunta Numero 2
**/

MI TNL6(MI &A,MI &B,ST tam,ST tamblock)
{
    ST i,j,k,ib,jb,kb;
    MI C;
    C=new int*[tam];
    for(int i=0;i<tam;i++)
        C[i]=new int[tam]; /*Uso de Memoria*/

    for (i = 0; i < tam; i+=tamblock)
        for (j = 0 ; j < tam; j+=tamblock)
	      for (k = 0; k < tam ; k+= tamblock)
	         for (ib = i; ib<j+tamblock; ib++)
	            for (kb = k ; kb<k+tamblock; kb++)
	               for (jb = j ; jb<j+tamblock ; jb++)
	                 C[ib][jb] += A[ib][kb] *B[kb][jb]; /*Uso de Memoria*/
    return C;
}

/**
Pregunta 3
En el TNL3 :
	El tiempo computacional es BIGO(n^3) pero utiliza demasiada memoria en su ejecucion.
	La complejidad es cubica ya que recorre 3 ciclos loop invariant, estos ciclos dependen del 
	tamanho de la matriz directamente.
	
En el TNL6: 
	El tiempo computacional es BIGO(n^3) pero utiliza poca memoria en su ejecucion.
	La complejidad es cubica, ya que aunque se utilice 6 ciclos, estos no lo evaluan en toda la 
	matriz, sus ciclos en este caso no dependen del tamanho de la matriz sino de el tamanho del bloque 
	en la matriz a ejecutar.
**/



/**
Pregunta 4
Figure One: Valgrind output for Listing One

==2009== 512 bytes in 1 blocks are definitely lost in loss record 1 of 2
==2009==    at 0x400483E4: malloc (main.cpp:100)
==2009==    by 0x80484D4: main (in /algoritmos parallelos/)
==2009==    by 0x40271507: __libc_start_main (main.cpp:129)
==2009==    by 0x80483B1: free@@GLIBC_2.0 (in /algoritmos parallelos/)
==2009== 
==2009== 5120 bytes in 512 blocks are definitely lost in loss record 2 of 2
==2009==    at 0x400483E4: malloc (main.cpp:100)
==2009==    by 0x80484A0: get_mem (in /algoritmos parallelos/)
==2009==    by 0x8048519: main (in /algoritmos parallelos/)
==2009==    by 0x40271507: __libc_start_main (main.cpp:129)
==2009== 
==2009== LEAK SUMMARY:
==2009==    definitely lost: 5632 bytes in 513 blocks.
**/

