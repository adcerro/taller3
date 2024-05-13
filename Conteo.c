#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("Entra a conteo %d de padre %s\n",getpid(),argv[argc-1]);
    if (argc != 4)
    {
        fprintf(stderr, "Uso: conteo ini_cont fin_cont\n");
        return 1;
    }
    int suma = 0;
    int cant = 0;
    for (int i = atoi(argv[1]); i <= atoi(argv[2]); i++)
    {
        printf("Conteo en el hijo %d\n", i);
        suma = suma + i;
        cant++;
    }
    float prom = suma/cant;
    printf("La suma = %d y el promedio = %5.2f\n",suma,prom);
}