#include<stdio.h>
#include<conio.h>

void printBoard();
int checkWin();

char arr[] = {'1','2','3','4','5','6','7','8','9'};

void main()
{
    
    int n, player=1,check;
    char mark;
    printf("\tWELCOME TO TIC-TAC-TOE GAME\n");
    do
    {
        printBoard();
        mark = (player%2) ? 'X' : 'O';
        printf("\n\nPlayer %c, Enter your move: ",mark);
        scanf("%d",&n);
        if (arr[n-1] == 'X' || arr[n-1] == 'O') 
        {
            printf("Invalid move..");
            continue;
        }
        arr[n-1] = mark;
        check = checkWin();
        player++;
    }while(check==-1);
    
    
    if(check==1) 
    {   
        printBoard();
        printf("\nPlayer %c won the Game...",mark);
    }
    
    else if(check==0)
    {
        printBoard();
        printf("\nNo Win...Match draw...");
    }
}

void printBoard()
{
    printf("\n\t\t %c | %c | %c ",arr[0],arr[1],arr[2]);
    printf("\n\t\t --------- ");
    printf("\n\t\t %c | %c | %c ",arr[3],arr[4],arr[5]);
    printf("\n\t\t --------- ");
    printf("\n\t\t %c | %c | %c ",arr[6],arr[7],arr[8]);
}

int checkWin()
{
    if(arr[0] == arr[1] && arr[1] == arr[2]) 
        return 1;
        
    else if(arr[3] == arr[4] && arr[4] == arr[5]) 
        return 1;
        
    else if(arr[6] == arr[7] && arr[7] == arr[8]) 
        return 1;
        
    else if(arr[0] == arr[3] && arr[3] == arr[6]) 
        return 1;
        
    else if(arr[1] == arr[4] && arr[4] == arr[7]) 
        return 1;
        
    else if(arr[2] == arr[5] && arr[5] == arr[8]) 
        return 1;
        
    else if(arr[0] == arr[4] && arr[4] == arr[8]) 
        return 1;
        
    else if(arr[2] == arr[4] && arr[4] == arr[6]) 
        return 1;
        
    else if(arr[0]!='1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' &&arr[6]!='7' &&arr[7]!='8' &&arr[8]!='9') 
        return 0;
        
    else return -1;   
}