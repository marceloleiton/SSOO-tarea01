#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

//Manejador de finalización del proceso
void handler(int signal_num)
{
    static uint32_t trials = 0;
    trials++;
    printf(" Para interrumpir programa (ctrl+c) %d  veces.\n", signal_num);
    if (trials == 2)
    {
        printf("\nPrograma finalizado con éxito.\n");
        exit(signal_num);
    }
}
int main(){
    int contador = 0;
    // register the signals and the signal handler
    signal(SIGTERM, handler);
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    while (++contador)
    {
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    sleep(1);
    printf("\nPrograma en ejecución ... PID= %d \n", getpid());
    printf("\nEn espera de señal SIGUSR1");
    if (contador == 100)
    {
        //printf(SIGTERM);
        }
    }
    return 0;
}