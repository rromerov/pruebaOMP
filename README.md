# Tarea 1. Programación de una solución paralela

## Definición
El **procesamiento** paralelo es un método informático que consiste en ejecutar dos o más procesadores (CPU) para gestionar partes separadas de una tarea global. Repartir las distintas partes de una tarea entre varios procesadores ayuda a reducir el tiempo de ejecución de un programa. Cualquier sistema que tenga más de una CPU puede realizar procesamiento paralelo, así como los procesadores multinúcleo que se encuentran comúnmente en los ordenadores de hoy en día.

## Ubicación del código dentro del repositorio
Para acceder al código de la **Tarea 1** lo puede realizar a través del siguiente [enlace.](https://github.com/rromerov/pruebaOMP/blob/main/pruebaOMP/pruebaOMP.cpp)


## Código completo
Así mismo se puede encontrar aquí el código completo: 

```
// pruebaOMP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static,pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << "valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}
    void imprimeArreglo(float* d)
    {
        for (int x = 0; x < mostrar; x++)
            std::cout << d[x] << " - ";
        std::cout << std::endl;
    }

```
