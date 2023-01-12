#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n =1, nRows = 50, nCol = 100, nTem = 100;
    int len;

    if(argc == 1)
    {
        char** input = (char**)malloc(nRows*sizeof(char*));
        char* temp = (char*)malloc(nTem*sizeof(char));
         for(int i=0; i<nRows; i++)
         {
             input[i] = (char*) malloc(nCol*sizeof(char));
         }

        for(int i = 0; n == 1; i++)
        {   
            n = scanf("%s\n", input[i]);
            len = i;
        }

        for(int i = 0; i< len; i++)
        {
            for(int j = i+1; j<len;j++)
            {
                if(strcasecmp(input[i],input[j]) > 0)
                {
                    strcpy(temp, input[i]);
                    strcpy(input[i], input[j]);
                    strcpy(input[j], temp);
                }
            }
        }

        printf("\n");
        for(int i = 0; i<len; i++)
        {
            printf("%s\n", input[i]);
        }
        
        for(int i = 0; i<len; i++)
        {
            free(input[i]);
        }
        free(input);
        free(temp);
    }
    else
    {
        int* num = (int*)malloc(50*sizeof(int));
        for(int i = 0; n==1; i++)
        {
            n = scanf("%d\n", &num[i]);
            len = i;
        }

        for(int i = 0; i<len; i++)
        {
            for(int j = i+1; j<len; j++)
            {
                if(num[j] < num[i])
                {
                    int temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
        printf("\n");
        for(int i = 0; i<len; i++)
        {
            printf("%d\n", num[i]);
        }
        free(num);
    }
    
    return 0;
}