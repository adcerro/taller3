#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("Entra a primos %d de padre %s\n", getpid(), argv[argc - 1]);
    if (argc != 3)
    {
        fprintf(stderr, "Uso: primos lim-primos\n");
        return 1;
    }
    int number = atoi(argv[1]);
    int ammount = 0;
    int n = 2;
    int divider = 2;
    while (ammount < number)
    {
        if (n % divider == 0)
        {
            if (n == divider)
            {
                ammount++;
                printf("Primo %d es %d\n", ammount, n);
            }
            n++;
            divider = 2;
        }
        else
        {
            divider++;
        }
    }
}