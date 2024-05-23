#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("Entra a conteo %d de padre %d\n",getpid(),getppid());
    if (argc != 3)
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
    float prom = (float) suma/cant;
    printf("La suma = %d y el promedio = %.2f\n",suma,prom);
}