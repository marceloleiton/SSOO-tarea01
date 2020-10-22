#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void handler(int signal_num)
{
    static uint32_t trials = 0;

    trials++;
    printf(" Para interrumpir programa (ctrl+c) %s  veces.\n", signal_num);

    if (trials == 2)
    {
        printf("\nPrograma finalizado con éxito.\n");
        exit(signal_num);
    }
}
