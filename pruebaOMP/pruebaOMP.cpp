// Esta parte del código muestra las librerías que vamos a usar
#include <iostream>
#include <omp.h>


// Aquí N es la cantidad de elementos que tendrán los arreglos
// Chunk indica la cantidad de elementos que deben ser procesador por cada uno de los fragmentos
// Mostrar es utilizado para denotar la cantidad de elementos que se deben mostrar de los arreglos.
#define N 500
#define chunk 50
#define mostrar 5

// La función prototipo recibe un puntero al arreglo que contiene los datos a imprimir
void imprimeArreglo(float* d);

int main()
{
    //Aquí declaramos 3 arreglos a, b y c, el tamaño de cada uno de ellos, será de tamaño N.
    std::cout << "Sumando Arreglos en Paralelo\n";
    float a[N], b[N], c[N];
    int i;

    //Usamos este ciclo for para llenar los arreglos a y b con valores
    for (i = 0; i < N; i++) {
        a[i] = i * 5;
        b[i] = (i + 3) * 1.5;
    }

    //La variable pedazos se usa para especificar la cantidad de chunks en los que se divide,el trabajo en la sección paralela
    int pedazos = chunk;

    //Pragma omp parallel significa que la secuencia de código debe ser ejecutada en paralelo, por varios hilos
    //Shared indica las variables compartidas
    //Private las variables privadas
    //Schedule especifica que el código se divide en bloques estáticos, con tamaño igual a la variable pedazos
    #pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static,pedazos)

    //Esta parte del código se encarga de sumar los arreglos a y b, para guardarlos dentro del arreglo c, mediante un ciclo for
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    //En esta parte del código se imprimen los primeros elementos de los arreglos a,b y c, para ello se apoya 3 veces de la función imprimeArreglo
    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}
    // La función imprimeArreglo se encarga de imprimir los valores de un arreglo, en este caso con valores flotantes, la cantidad de elementos a imprimir estará dado por mostrar
    void imprimeArreglo(float* d)
    {
        for (int x = 0; x < mostrar; x++)
            std::cout << d[x] << " - ";
        std::cout << std::endl;
    }
