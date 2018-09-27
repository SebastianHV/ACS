#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t id_hijo;
    printf("1: el id del proceso es %d\n", getpid());
    sleep(60);
    printf(": me despierto y termino\n");
}
