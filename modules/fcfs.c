#include "fcfs.h"
#include <stdlib.h> // Para qsort
#include <stdio.h>  // Para fprintf en caso de error

// Función de comparación para ordenar procesos por tiempo de llegada
int compararPorTiempoLlegada(const void *a, const void *b)
{
    const Proceso *procesoA = (const Proceso *)a;
    const Proceso *procesoB = (const Proceso *)b;
    return procesoA->tiempoLlegada - procesoB->tiempoLlegada;
}

// Función para planificar procesos usando el algoritmo First-Come, First-Served (FCFS)
void planificarFCFS(Proceso *procesos, int numProcesos)
{
    // Validación de los argumentos y ordenar después por su tiempo de llegada (se puede utilizar qsort)
    if (procesos == NULL || numProcesos <= 0)
    {
        fprintf(stderr, "Error: Argumentos no válidos para planificarSJF.\n");
        return;
    }
    qsort(procesos, numProcesos, sizeof(Proceso), compararPorTiempoLlegada);
    /*
    Después de esta llamada a qsort, los procesos están ordenados según el algoritmo FCFS, listos para ser procesados en este orden.
    */
}
