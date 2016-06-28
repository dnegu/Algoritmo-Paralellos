#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef size_t ST;
typedef int** MI;

MI TNL(MI &A,MI &B,ST tam)
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

