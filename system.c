#include<stdio.h>
#include<stdlib.h>
int main()
{
    int return_value;
    return_value=system("./system");
    printf("valor devuelto=%d\n",return_value);
    return return_value;
}
