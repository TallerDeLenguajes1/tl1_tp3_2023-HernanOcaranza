#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANIO 5
#define MES 12

void CargarMatriz(int m[ANIO][MES]);

void MostrarMatriz(int m[ANIO][MES]);

void CalcularPromedioGananciasPorAnio(int m[ANIO][MES], float promedios[ANIO]);

void MostrarPromedios(float *promedios);

void MostrarValorMaxYMin(int m[ANIO][MES]);

int main()
{
    srand(time(NULL));
    int matriz[ANIO][MES];
    float promediosPorAnio[ANIO];

    CargarMatriz(matriz);
    MostrarMatriz(matriz);
    CalcularPromedioGananciasPorAnio(matriz, promediosPorAnio);
    MostrarPromedios(promediosPorAnio);
    MostrarValorMaxYMin(matriz);
    return 0;
}

// Desarrollo de funciones
void CargarMatriz(int m[ANIO][MES])
{
    int i, j;
    for (i = 0; i < ANIO; i++)
    {
        for (j = 0; j < MES; j++)
        {
            m[i][j] = 10000 + rand() % 40000;
        }
    }
}

void MostrarMatriz(int m[ANIO][MES])
{
    int i, j;
    printf("\t\t ");
    for (i = 0; i < MES; i++)
    {
        printf("Mes%3d  ", i + 1);
    }
    printf("\n");
    for (i = 0; i < ANIO; i++)
    {
        printf("Anio Num %d\t", i + 1);
        for (j = 0; j < MES; j++)
        {
            printf("%6d  ", m[i][j]);
        }
        printf("\n");
    }
}

void CalcularPromedioGananciasPorAnio(int m[ANIO][MES], float promedios[ANIO])
{
    int i, j, suma;
    for (i = 0; i < ANIO; i++)
    {
        suma = 0;
        for (j = 0; j < MES; j++)
        {
            suma += m[i][j];
        }
        promedios[i] = (float)suma / MES;
    }
}

void MostrarPromedios(float *promedios)
{
    int i;
    for (i = 0; i < ANIO; i++)
    {
        printf("\nEl promedio del anio %d fue: $%.2f", i + 1, promedios[i]);
    }
}

void MostrarValorMaxYMin(int m[ANIO][MES])
{
    int i, j, max = -1, min = 999999, mesMax, anioMax, mesMin, anioMin;
    for (i = 0; i < ANIO; i++)
    {
        for (j = 0; j < MES; j++)
        {
            if (m[i][j] > max)
            {
                max = m[i][j];
                anioMax = i;
                mesMax = j;
            }
            if (m[i][j] < min)
            {
                min = m[i][j];
                anioMin = i;
                mesMin = j;
            }
        }
    }
    printf("\n\nEl valor maximo fue de $%d en el mes %d del anio %d", max, mesMax + 1, anioMax + 1);
    printf("\nEl valor minimo fue de $%d en el mes %d del anio %d", min, mesMin + 1, anioMin + 1);
}