#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int spawn (char* program, char** arg_list)
{
 pid_t child_pid;  //Se define una variable tipo pid_t
 child_pid = fork ();  //Se crea un proceso hijo
 if (child_pid != 0)  //Es el proceso padre, sigue con la ejecución del programa
 return child_pid;  //Regresa el valor del proceso hijo, el cual es diferente de 0 y continúa con la ejecución del programa
 else { //Es el proceso hijo
 execvp (program, arg_list); //Se ejecuta la función execvp y este proceso hijo termina, lo que continua con la ejecución del programa ls con sus respectivos argumentos
                             //defindos anteriormente en arg_list
 fprintf (stderr, "an error occurred in execvp\n");  //Nunca debería llegar aquí la ejecución del programa ya que fue reemplazado por execvp, a menos que execvp falle
 abort ();  //Si por algún error se llega a ejecutar esta parte del programa
            //abort prende la señal SIGABRT y causa una terminación anormal del programa
 }
}
int main () //El programa ejecuta la función spawn, que crea un proceso hijo que ejecuta la función execvp, y el proceso padre sigue la ejecución hasta terminar el proceso
{
 char* arg_list[] = {  //Se define la lista de argumentos del proceso a ejecutar
 "ls",
 "-l",
 "/",
 NULL
 };

 spawn ("ls", arg_list); //Se llama a la función spawn
 printf ("done with main program\n"); //Es ejecutado por el proceso padre, independientemente de lo que ha ejecutado el proceso hijo
 return 0;  //Termina la ejecución del proceso padre
}

