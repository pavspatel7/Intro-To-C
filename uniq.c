#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char** input = (char**)malloc(50*sizeof(char*));

    int n= 1, len;

   for(int i = 0; n==1; i++)
   {
        input[i] = malloc(100 * sizeof(char));
        n = scanf("%s\n", input[i]);
        
        len = i;
   }

   int count = 1; 
   for(int i = 0; i<len; i+= count)
   {
        count = 1;
        for(int j = i+1; j < len; j++)
        {
            if(strcmp(input[i],input[j]) == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        printf("%d: %s\n", count, input[i]);
   }

   for(int i = 0; i<len; i++)
   {
        free(input[i]);
   }

   free(input);
   return 0;
}