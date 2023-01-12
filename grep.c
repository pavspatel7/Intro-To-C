#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char *input=malloc(sizeof(char) * 50);
    int i=0;
    int n = scanf("%[^\n]%*c", input);
    while(n==1)
    {
        if(argc==2 && strstr(input, argv[1]))
        {
            printf("%s\n", input);
        }
        else if(argc==3)
        {
            char *temp=malloc(sizeof(char) * 20);
            for(int i=0; input[i] != '\0'; i++)
            {
                temp[i]=tolower(input[i]);
            }
            if(strstr(temp, argv[2]))
            {
                printf("%s\n", input);
            }
        }
        n = scanf("%[^\n]%*c", input);
    }
    free(input);
    return 0;
}