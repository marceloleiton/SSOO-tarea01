#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void recibidora(int sig){
    time_t tiempoactual;
    time(&tiempoactual);
    printf("\nSeñal SIGUSR1 recibida: %s\n",ctime(&tiempoactual));
}
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
    signal(SIGTERM, handler);
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    signal(SIGUSR1, &recibidora);
    int contador = 0;
    while (++contador)
    {
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    
    printf("\nPrograma hora ejecutandose. PID= %d \n", getpid());
    printf("Listo para recibir señal SIGUSR1.\n");
    sleep(100);
    //if (signal(SIGUSR1,recibidora) == SIG_ERR)
    //{
        //perror("no puedo obtener la señal");
    //}
    //else
    //{
        
    //}
    }
    return 0;
}