#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("Entra a fibonacci %d de padre %d\n", getpid(), getppid());
    if (argc != 2)
    {
        fprintf(stderr, "Uso: fibo lim-fibo\n");
        return 1;
    }
    int number = atoi(argv[1]);
    if (number == 1)
    {
        printf("Fibo 1 = 0\n");
        return 0;
    }
    if (number == 2)
    {
        printf("Fibo 1 = 0\n");
        printf("Fibo 2 = 1\n");
        return 0;
    }
    int sequence[number];
    sequence[0] = 0;
    sequence[1] = 1;
    printf("Fibo 1 = 0\n");
    printf("Fibo 2 = 1\n");
    for (int i = 2; i < number; i++)
    {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
        printf("Fibo %d = %d\n", i + 1, sequence[i]);
    }
}