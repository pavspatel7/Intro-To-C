#include <stdio.h>
#include <stdlib.h>

// Display the grid and position of characters
void displayboard(char **carr, int *boardX, int *boardY, int *plrX, int *plrY, int *goalX, int *goalY, int *monX, int *monY)
{
    for(int i=(*boardY-1); i>-1; i--)
    {
        for(int j=0; j<*boardX; j++)
        {
            if(j==*plrX && i==*plrY)
            {
                carr[i][j]='P';
            }
            else if(j==*goalX && i==*goalY)
            {
                carr[i][j]='G';
            }
            else if(j==*monX && i==*monY)
            {
                carr[i][j]='M';
            }
            else
            {
                carr[i][j]='.';
            }
            printf("%c ", carr[i][j]);
        }
        printf("\n");
    }
}

// checks who won the game
void checkscorevalid(int *plrX, int *plrY, int *goalX, int *goalY, int *monX, int *monY, int *flag)
{
    if(*plrX==*goalX && *plrY==*goalY)
    {
        printf("player wins!\n");
        *flag=0;
    }
    else if(*plrX==*monX && *plrY==*monY)
    {
        printf("monster wins!\n");
        *flag=0;
    }
    else if(*monX==*goalX && *monY==*goalY)
    {
        printf("player wins!\n");
        *flag=0;
    }
}

// method that determines how the player moves. Also, make sures that the player stays on grid.
void playermove(char **carr, int *plrX, int *plrY, int *goalX, int *goalY, int *monX, int *monY, char *pmove, int *flag)
{
l1: carr[*plrX][*plrY]='.';
    if(*pmove=='E' && *plrX+1<10)
    {
        *plrX+=1;
    }
    else if(*pmove=='W' && *plrX-1>0)
    {
        *plrX-=1;
    }
    else if(*pmove=='N' && *plrY+1<10)
    {
        *plrY+=1;
    }
    else if(*pmove=='S' && *plrY-1>0)
    {
        *plrY-=1;
    }
    else
    {
        carr[*plrX][*plrY]='P';
        printf("invalid move! enter again: ");
        scanf(" %c", pmove);
        goto l1;
    }
    carr[*plrX][*plrY]='P';
    checkscorevalid(plrX, plrY, goalX, goalY, monX, monY, flag);
}

// method that determines the moves of the monster
void monstermove(char **carr, int *plrX, int *plrY, int *goalX, int *goalY, int *monX, int *monY, int *flag)
{
    int a=(*plrX-*monX);
    int b=(*plrY-*monY);
    carr[*monX][*monY]='.';

    if(abs(a) > abs(b))
    {
        if(a<0)
        {
            *monX-=1;
            printf("monster moves W\n");
        }
        else
        {
            *monX+=1;
            printf("monster moves E\n");
        }
    }
    else
    {
        if(b<0)
        {
            *monY-=1;
            printf("monster moves S\n");
        }
        else
        {
            *monY+=1;
            printf("monster moves N\n");
        }
    }
    carr[*monX][*monY]='M';
    checkscorevalid(plrX, plrY, goalX, goalY, monX, monY, flag);
}

// main
int main(int argc, char *argv[])
{
    int boardX = atoi(argv[1]);
    int boardY = atoi(argv[2]);
    int plrX = atoi(argv[3]);
    int plrY = atoi(argv[4]);
    int goalX = atoi(argv[5]);
    int goalY = atoi(argv[6]);
    int monX = atoi(argv[7]);
    int monY = atoi(argv[8]);
    char *pmove = malloc(sizeof(char));
    int flag = 1;

//  2D array for grid
    char **carr = malloc(sizeof(char*) * boardY);
    for(int i=0; i<boardY; i++)
    {
        carr[i]=malloc(sizeof(char) * boardX);
    }

    while(flag==1)
    {
        displayboard(carr, &boardX, &boardY, &plrX, &plrY, &goalX, &goalY, &monX, &monY);
        scanf(" %c", pmove);
        playermove(carr, &plrX, &plrY, &goalX, &goalY, &monX, &monY, pmove, &flag);
        if(flag==0)
        {
            break;
        }
        monstermove(carr, &plrX, &plrY, &goalX, &goalY, &monX, &monY, &flag);
    }
 
 // freeing dynamic memory
    for(int i=0; i<boardY; i++)
    {
        free(carr[i]);
    }
    free(carr);
    free(pmove);
    return 0;
}