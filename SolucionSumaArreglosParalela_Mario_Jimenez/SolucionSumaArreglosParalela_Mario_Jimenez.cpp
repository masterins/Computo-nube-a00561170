// SolucionSumaArreglosParalela_Mario_Jimenez.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10 

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Suma de dos arreglos paralelamente !\n\n";
//local variables i for the cyclo and a,b,c to arrays of N dimensions
    int i;
    float a[N], b[N], c[N];

    // fill the two arrays using a cyclo   
    for (i = 0; i < N; i++)
    {
        //example I)
        a[i] = (float) i * 7;
        b[i] = (float)((i + 3) * 3.7);
    }

    int pedazos = chunk;

    //sum a+b arrays in parallel and record the result in the array c
    #pragma omp parallel for shared(a,b, pedazos) private(i) schedule (static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    //print the result and the arrays
    std::cout << " imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << " " << std::endl;
    std::cout << " imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << " " << std::endl;
    std::cout << " imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
    
}
// procedure for print arraays regarding with the value of mostrar 
void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
