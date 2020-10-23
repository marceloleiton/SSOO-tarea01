# Teoría de Sistemas Operativos - Tarea #1
_Procesos y Señales en Linux Escuela de Ingeniería Civil Informática Universidad de Valparaíso._

### Diseño de la solución 🔧
_El diseño para la solución de la problematica planteada se basa en recibir y manejar, ¿que quiere decir esto? el proceso el cual tiene su PID definido siempre esta esperando una "interrupción" a este para "hacer algo", por ende de ahí viene el recibir. El proceso recibe una señal ya sea de forma remota o local y la maneja. Cabe recalcar que la practica para esté problema esta abordada en un sistema UNIX y el sistema operativo es MacOS. esté sistema funciona con los mismos comando que cualquier LINUX, por ende el proceso para este caso se ejecutaba en una terminal y desde otra terminal se hacia la solicitus del proceso SIGUSR1 y el programa recibia la señal e indica la fecha actual. El programa está diseñado para que el manejo de esa señal la reciba de esa forma mediante ciertas funciones que funcionan como "HANDLER" las cuales se encargan de ejecutar ciertos manejos, además se manjó la solicitud de no terminal el programa con un solo cltr(+c), sinó que con dos de estos el proceso terminaría, ese proceso también fué manejado por las funciones._

### Funciones utilizadas ⌨️
_Función: Recibed_Signal(). Es la función encargada de manejar la situación cuando se genere la interupción o solucitus a la señal SIGUSR1. dado que cuando se haga la solicitud desde otra consola esta determinará que hacer. Para esta problematica se le indica que actue como handler y que imprima la fecha mediante la librería time() cada vez que se genere la interrupción por SIGUSR1, obviamente tiene sus sentencias condicionales para así generar un uso a las excepciones que se puedan generar_

## Autor ✒️
* **Marcelo Osvaldo Leiton Valdés** - *marcelo.leiton@alumnos.uv.cl* - [GitHub](https://github.com/marceloleiton)

http://www.chuidiang.org/clinux/senhales/senhales.php