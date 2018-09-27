#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid_hijo;
    pid_hijo = fork();
    if (pid_hijo!=0){
        printf("Proceso padre, cuenta de 0 a 10\n");
        for(int i=1;i<=10;i++)
            printf("%d\n",i);
        }
    else{
        printf("Proceso hijo, cuenta de 10 a 0\n");
        for(int i=10;i>=1;i--)
        printf("%d\n",i);
    }
    
}
