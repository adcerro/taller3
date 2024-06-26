#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Uso: Padre vlr-inip, vlr-finp, fnc, arg1, [arg2 … argN]\n");
        return 1;
    }
    int pid = fork();
    if (pid == -1)
    {
        perror("Error en fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Va a ejecutar al hijo PID(%s) = %d de padre %d\n", argv[3], getpid(), getppid());
        int argscount = argc - 3;
        char *args[argscount+1];
        for (int j = 0; j < argscount; j++)
        {
            args[j] = argv[j + 3];
        }
        args[argscount] = NULL;
        if (execv(args[0], args) == -1)
        {
            printf("Falló la ejecución del proceso hijo");
            return 1;
        }
    }
    else
    {
        printf("Va a ejecutar al padre %d\n", getpid());
        for (int i = atoi(argv[1]); i <= atoi(argv[2]); i++)
        {
            printf("Conteo en el padre %d\n", i);
        }
    }
    while (1)
    {
        sleep(1);
    }
}