#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int spawn (char* program, char** arg_list)
{
	pid_t child_pid;
	/* Duplicate this process. */
	child_pid = fork ();
	// sleep(10);
	if (child_pid != 0) /* This is the parent process. */
	{
		printf("child_pid=%d\n",child_pid);
		return child_pid;
	}
	else {
		/* Now execute PROGRAM, searching for it in the path. */
		execvp (program, arg_list); //En este momento el proceso hijo termina de manera exitosa
		/* The execvp function returns only if an error occurs. */
		fprintf (stderr, "an error occurred in execvp\n");
		abort ();
	}
}

int main ()
{
	int child_status;
	/* The argument list to pass to the "ls" command. */
	char* arg_list[] = {
		"ls", /* argv[0], the name of the program. */
		"-l",
		"/",
		NULL /* The argument list must end with a NULL. */
	};
	/* Spawn a child process running the "ls" command. Ignore the
	returned child process ID. */
	spawn ("ls", arg_list);
	/* Wait for the child process to complete. */
	int retorno = wait (&child_status);
	printf("retorno=%d\n",retorno);
	 sleep(10);
	printf("&child_status=%X\n",&child_status);
	printf("child_status=%d\n",child_status);
	if (WIFEXITED (child_status))
		printf ("the child process exited normally, with exit code %d\n", WEXITSTATUS (child_status));
	else
		printf ("the child process exited abnormally\n");
	return 0;
}

