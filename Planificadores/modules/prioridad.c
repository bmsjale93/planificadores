#include "prioridad.h"
#include <stdio.h>
#include <stdlib.h> // Para qsort

// Función de comparación inicial por prioridad y tiempo de llegada
int compararPorPrioridad(const void *a, const void *b)
{
    const Proceso *procesoA = (const Proceso *)a;
    const Proceso *procesoB = (const Proceso *)b;

    // Comparamos por prioridad, la mayor prioridad va primero
    if (procesoA->prioridad != procesoB->prioridad)
    {
        return procesoB->prioridad - procesoA->prioridad;
    }

    // Si ambas tienen la misma prioridad, desempatamos por tiempo de llegada
    return procesoA->tiempoLlegada - procesoB->tiempoLlegada;
}

// Ajusta las prioridades de los procesos basándose en el envejecimiento
void ajustarPrioridadesPorEnvejecimiento(Proceso *procesos, int numProcesos)
{
    // Función opcional para modificar las prioridades basadas en el tiempo de espera, mitigando el hambre.
    // Aumentamos prioridad por unidad de tiempo
    for (int i = 0; i < numProcesos; ++i)
    {
        procesos[i].prioridad += 1;
    }
}

void planificarPrioridades(Proceso *procesos, int numProcesos)
{
    if (procesos == NULL || numProcesos <= 0)
    {
        fprintf(stderr, "Error: Argumentos no válidos en planificarPrioridades.\n");
        return;
    }

    // Inicialmente, ordenamos los procesos por prioridad original y tiempo de llegada
    qsort(procesos, numProcesos, sizeof(Proceso), compararPorPrioridad);

    // Ajustamos las prioridades en base al envejecimiento (si debe ser apicado)
    ajustarPrioridadesPorEnvejecimiento(procesos, numProcesos);
}
