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
    C=new int*[tam];
    for(int i=0;i<tam;i++)
        C[i]=new int[tam];

    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            for(k=0;k<tam;k++)
            C[i][j]+=A[i][k]*B[k][j];
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
    A=new int*[tam];
    for(int i=0;i<tam;i++)
        A[i]=new int[tam];

    ST i,j;
    for(i=0;i<tam;i++)
        for(j=0;j<tam;j++)
            A[i][j]=rand() % 10 + 1;
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
        C[i]=new int[tam];

    for (i = 0; i < tam; i+=tamblock)
        for (j = 0 ; j < tam; j+=tamblock)
	      for (k = 0; k < tam ; k+= tamblock)
	         for (ib = i; ib<j+tamblock; ib++)
	            for (kb = k ; kb<k+tamblock; kb++)
	               for (jb = j ; jb<j+tamblock ; jb++)
	                 C[ib][jb] += A[ib][kb] *B[kb][jb];
    return C;
}

/**
Pregunta 3
**/


/**
Pregunta 4
**/

