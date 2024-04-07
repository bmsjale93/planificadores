#include "rr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void planificarRR(ProcesoRR *procesos, int numProcesos, int quantum)
{
    // Verificamos la validez del quantum.
    if (quantum <= 0)
    {
        fprintf(stderr, "El quantum debe ser mayor que 0.\n");
        return;
    }

    int tiempoActual = 0;
    // Reservamos memoria para los tiempos restantes.
    int *tiemposRestantes = (int *)malloc(sizeof(int) * numProcesos);
    int procesosTerminados = 0;

    // Inicializa los tiempos restantes y cuenta procesos ya terminados.
    for (int i = 0; i < numProcesos; i++)
    {
        tiemposRestantes[i] = procesos[i].duracionRafaga;
        if (tiemposRestantes[i] == 0)
            procesosTerminados++;
    }

    // Ejecuta cada proceso según el quantum y su tiempo restante.
    while (procesosTerminados < numProcesos)
    {
        bool seEjecutoProceso = false;
        for (int i = 0; i < numProcesos; i++)
        {
            // Verificamos las condiciones para ejecutar.
            if (tiemposRestantes[i] > 0 && procesos[i].tiempoLlegada <= tiempoActual)
            {
                seEjecutoProceso = true;
                int tiempoEjecucion = (tiemposRestantes[i] > quantum) ? quantum : tiemposRestantes[i];
                tiempoActual += tiempoEjecucion;
                tiemposRestantes[i] -= tiempoEjecucion;
                if (tiemposRestantes[i] == 0)
                    procesosTerminados++;
            }
        }
        if (!seEjecutoProceso)
            // Si no se ejecuta ningún proceso avanzamos el tiempo.
            tiempoActual++;
    }
    // Libera memoria.
    free(tiemposRestantes);
}

// Implementamos una nueva forma para guardar los CSV, la dada no funciona
void guardarProcesosEnCSVRR(const char *nombreArchivo, ProcesoRR *procesos, int numProcesos)
{
    FILE *archivo = fopen(nombreArchivo, "w");
    if (!archivo)
    {
        perror("Error al abrir el archivo CSV");
        return;
    }

    fprintf(archivo, "ID Proceso,Tiempo de Llegada,Duración de la Ráfaga\n");

    for (int i = 0; i < numProcesos; i++)
    {
        fprintf(archivo, "%d,%d,%d\n", procesos[i].id, procesos[i].tiempoLlegada, procesos[i].duracionRafaga);
    }

    fclose(archivo);
}
