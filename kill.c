#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
     pid_t pid, pid2;
     if (( pid = fork()) == 0) {
         while(1) {
             printf("HIJO 1 getpid()=%d pid = %d\n", getpid(), pid);
             sleep(1);
         }
     }
     if (( pid2 = fork()) == 0) {
         while(1) {
             printf("HIJO 2 getpid()=%d pid = %d\n", getpid(), pid2);
             sleep(1);
         }
     }
     sleep(10);
     printf("PADRE Terminacion proceso %d\n", pid);
     kill (pid,SIGTERM);
     sleep(10);
     printf("PADRE Terminacion proceso %d\n", pid2);
     kill (pid2,SIGTERM);
     exit(0);
}
