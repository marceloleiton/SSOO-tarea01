#include <global.h>
//Recibed_Signal -> función que recibe la señal de SIGUSR1 y imprime el tiempo al recibirla.
//Se ingresa por argumento un entero, el número de la señal SIGUSR1.
void Recibed_Signal(int Num_Signal_SIGUSR1){
    time_t tiempoactual;
    time(&tiempoactual);
    //Sentencias condicionales indican si recibe la señal o no, y que hacer en ambos casos.
    if (signal(SIGUSR1, Recibed_Signal) == SIG_ERR){
        perror("Error al obtener la señal");
    }
    else{
        if (tiempoactual == -1){
            printf("Error al encontrar el tiempo");
        }else{
            printf("\nSeñal SIGUSR1 recibida: %s\n", ctime(&tiempoactual));
        }
    }
}
//Manejador para el control de termino de ejecución, para que cumpla solo la condición de (ctrl+c) 2 veces.
void handler(int signal_num){
    static uint32_t End_Process = 0;
    End_Process++;
    if (End_Process == 2)
    {
        printf("\nPrograma finalizado con éxito.\n");
        exit(signal_num);
    }
}
int main(){
    //Manejo de señales para el control de termino de ejecución.
    signal(SIGTERM, handler);
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    //se recibe la señal (&Recibed_Signal), cuando el proceso reciba la interrupción SIGUSR1.
    signal(SIGUSR1, &Recibed_Signal);
    int contador = 0;
    printf("Programa hora ejecutandose. PID= %d \n", getpid());
    while (++contador){
        printf("Listo para recibir señal SIGUSR1.\n");
        sleep(100000);
    }
    return 0;
}