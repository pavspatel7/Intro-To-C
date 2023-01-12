// Program to calculate factors of a number entered by a user
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count=argc;
    const char *cnum=argv[1];
    int num = atoi(cnum);

    while(num!=1)
    {
        while(num%count==0 && num!=1)
        {
            num=num/count;
            printf("%d ", count);
        }
        count++;
    }

    printf("\n");
    return 0;
}