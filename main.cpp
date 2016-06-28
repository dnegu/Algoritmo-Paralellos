#include "preg.hpp"

int main()
{

    ST tam = 2;
    MI A,B,C;
    llenar(A,tam);
    print(A,tam);
    llenar(B,tam);
    print(B,tam);

    C=TNL3(A,B,tam);
    print(C,tam);

}

