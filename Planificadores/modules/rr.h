#ifndef PROCESORR_H
#define PROCESORR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int tiempoLlegada;
    int duracionRafaga;
    int duracionRafagaOriginal;
    int *iniciosEjecucion;
    int *finesEjecucion;
    int numEjecuciones;
} ProcesoRR;

void planificarRR(ProcesoRR *procesos, int numProcesos, int quantum);
void guardarProcesosEnCSVRR(const char *nombreArchivo, ProcesoRR *procesos, int numProcesos);

#endif // PROCESORR_H
