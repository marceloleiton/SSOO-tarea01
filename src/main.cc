#include "global.hh"

#include <unistd.h> 

//Para sali de un proceso (ctrl+c)2 veces
void signal_handler( int signal_num ) { 
	static uint32_t trials = 0;
	
	trials++;
	std::cout << " Para interrumpir programa (ctrl+c) (" << signal_num << ") veces.\n";

	if(trials == 2){
		std::cout << "\nPrograma finalizado con éxito.\n";
		exit(signal_num);  
	} 
} 

int main(int argc, char* argv[])
{
	int count = 0; 
	
	// register the signals and the signal handler   
	std::signal(SIGTERM, signal_handler);   
	std::signal(SIGINT, signal_handler);  
	   
	  
	while(++count) { 
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Programa en ejecución ... PID=" << getpid() << std::endl;
		std::cout << "En espera de señal SIGUSR1"<< std::endl;
		if( count == 100 ) {
			std::raise(SIGTERM); 
		} 
	}
	
	return EXIT_SUCCESS;
}
