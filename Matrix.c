#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int rows,columns,rowsA,columnsA,rowsB,columnsB;
int MatrixA[10][10],MatrixB[10][10],MatrixH[10][10],resMatrix[10][10];

void Matrix();
void Input_Matrix(int Matrix[10][10],int rows,int columns);
void Print_Matrix(int Matrix[10][10],int rows,int columns);

void Matrix_Addition(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns);
void Matrix_Subtraction(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns);
void Matrix_Transpose(int MatrixH[10][10],int rows,int columns);
void Scaler_Multiplication(int MatrixH[10][10],int rows,int columns,int value);
void Matrix_Multiplication(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns,int mid);

void main()
{
    int ch,value,mid;
    char c;
    MENU:
    do {
    printf("****************************************");
    printf("\nSelect Operations: ");
    printf("\n   1. Matrix Addition. ");
    printf("****************************************");
    printf("\n   2. Matrix Subtraction. ");
    printf("\n   3. Scaler Multiplication. ");
    printf("\n   4. Matrix Multiplication. ");
    printf("\n\tMATRIX CALCULATOR\n");
    printf("\n   5. Transpose of Matrix. ");
    printf("\n   0. Exit. ");
    printf("\n****************************************");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    Matrix();
    
    switch(ch)
    {
        case 1: printf("****************************************");
                printf("\n\t   MATRIX ADDITION\n");
                printf("****************************************");
                printf("\nMatrix A:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsA);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsA);
                printf("\nMatrix B:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsB);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsB);
                while((rowsA != rowsB) || (columnsA != columnsB))
                {
                    printf("\nMatrices must be of the same size\n");
                    printf("\nMatrix A:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsA);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsA);
                    printf("\nMatrix B:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsB);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsB);
                }
                printf("\nMatrix A:\n");
                Print_Matrix(MatrixA,rowsA,columnsA);
	            Input_Matrix(MatrixA,rowsA,columnsA);
                printf("\nMatrix A:\n");
	            Print_Matrix(MatrixA,rowsA,columnsA);
                printf("\n");
                printf("\nMatrix B:\n");
                Print_Matrix(MatrixB,rowsB,columnsB);
	            Input_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix B:\n");
	            Print_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix A + Matrix B: \n");
                rows = rowsA = rowsB;
                columns = columnsA = columnsB;
                Matrix_Addition(MatrixA,MatrixB,rows,columns);
                Print_Matrix(resMatrix,rows,columns);
                break;
                
        case 2: printf("****************************************");
                printf("\n\t  MATRIX SUBTRACTION\n");
                printf("****************************************");
                printf("\nMatrix A:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsA);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsA);
                printf("\nMatrix B:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsB);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsB);
                while((rowsA != rowsB) || (columnsA != columnsB))
                {
                    printf("\nMatrices must be of the same size\n");
                    printf("\nMatrix A:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsA);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsA);
                    printf("\nMatrix B:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsB);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsB);
                }
                printf("\nMatrix A:\n");
                Print_Matrix(MatrixA,rowsA,columnsA);
	            Input_Matrix(MatrixA,rowsA,columnsA);
                printf("\nMatrix A:\n");
	            Print_Matrix(MatrixA,rowsA,columnsA);
                printf("\n");
                printf("\nMatrix B:\n");
                Print_Matrix(MatrixB,rowsB,columnsB);
	            Input_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix B:\n");
	            Print_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix A - Matrix B: \n");
                rows = rowsA = rowsB;
                columns = columnsA = columnsB;
                Matrix_Subtraction(MatrixA,MatrixB,rows,columns);
                Print_Matrix(resMatrix,rows,columns);
                break;
                
        case 3: printf("****************************************");
                printf("\n\tSCALER MULTIPLICATION\n");
                printf("****************************************");
                printf("\nEnter the Scaler value: ");
                scanf("%d", &value);
                printf("\nMatrix:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rows);
	            printf("Enter Columns: ");
	            scanf("%d", &columns);
                printf("\n");
                Print_Matrix(MatrixH,rows,columns);
	            Input_Matrix(MatrixH,rows,columns);
                printf("\nMatrix:\n");
	            Print_Matrix(MatrixH,rows,columns);
                Scaler_Multiplication(MatrixH,rows,columns,value);
                printf("\nThe Scaler Multiplication of Matrix with %d is: \n",value);
                Print_Matrix(resMatrix,rows,columns);
                break;
                
        case 4: printf("****************************************");
                printf("\n\tMATRIX MULTIPLICATION\n");
                printf("****************************************");
                printf("\nMatrix A:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsA);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsA);
                printf("\nMatrix B:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rowsB);
	            printf("Enter Columns: ");
	            scanf("%d", &columnsB);
                while(columnsA != rowsB)
                {
                    printf("\nColumn of Matrix A  must be equal to Row of Matrix B\n");
                    printf("\nMatrix A:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsA);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsA);
                    printf("\nMatrix B:\n");
                    printf("Enter Rows: ");
	                scanf("%d", &rowsB);
	                printf("Enter Columns: ");
	                scanf("%d", &columnsB);
                }
                printf("\nMatrix A:\n");
                Print_Matrix(MatrixA,rowsA,columnsA);
	            Input_Matrix(MatrixA,rowsA,columnsA);
                printf("\nMatrix A:\n");
	            Print_Matrix(MatrixA,rowsA,columnsA);
                printf("\n");
                printf("\nMatrix B:\n");
                Print_Matrix(MatrixB,rowsB,columnsB);
	            Input_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix B:\n");
	            Print_Matrix(MatrixB,rowsB,columnsB);
                printf("\nMatrix A - Matrix B: \n");
                rows = rowsA;
                columns = columnsB;
                mid = rowsB = columnsA;
                Matrix_Multiplication(MatrixA,MatrixB,rows,columns,mid);
                Print_Matrix(resMatrix,rows,columns);
                break;
                
        case 5: printf("****************************************");
                printf("\n\tMATRIX TRANSPOSE\n");
                printf("****************************************");
                printf("\nMatrix:\n");
                printf("Enter Rows: ");
	            scanf("%d", &rows);
	            printf("Enter Columns: ");
	            scanf("%d", &columns);
                printf("\n");
                Print_Matrix(MatrixH,rows,columns);
	            Input_Matrix(MatrixH,rows,columns);
                printf("\nMatrix:\n");
	            Print_Matrix(MatrixH,rows,columns);
                Matrix_Transpose(MatrixH,rows,columns);
                printf("\nThe Transpose of Matrix is: \n",value);
                Print_Matrix(resMatrix,columns,rows);
                break;
                
        case 0: exit(0);
                break;

        default: printf("\nInvalid Option...Choose a valid one...\n\n");
                 goto MENU;
    }
    printf("\n\nDo you want to try again?? (Y/N)  ");
        scanf(" %c", &c);
    }while((c == 'Y') || (c == 'y'));
    
}

void Matrix()
{
    int i,j;
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			resMatrix[i][j] = MatrixA[i][j] = MatrixB[i][j] = MatrixH[i][j] = 0;
		}
	}

}

void Input_Matrix(int Matrix[10][10],int rows,int columns)
{
	int i,j;
    printf("\n");
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			printf("Enter a number: ");
			scanf("%d", &Matrix[i][j]);
            Print_Matrix(Matrix,rows,columns);
		}
	}
}

void Print_Matrix(int Matrix[10][10],int rows,int columns)
{
    int i,j;
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			printf("%02d ",Matrix[i][j]);
		}
		printf("\n");
	}
}

void Matrix_Addition(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns)
{
    int i,j;
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			resMatrix[i][j] = MatrixA[i][j] + MatrixB[i][j];
		}
	}
}

void Matrix_Subtraction(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns)
{
    int i,j;
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			resMatrix[i][j] = MatrixA[i][j] - MatrixB[i][j];
		}
	}
}

void Matrix_Multiplication(int MatrixA[10][10],int MatrixB[10][10],int rows,int columns,int mid)
{
    int i,j,k;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++) 
        {
            resMatrix[i][j] = 0;
            for (k = 0; k < mid; k++) 
            {
                resMatrix[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
}

void Scaler_Multiplication(int Matrix[10][10],int rows,int columns,int value)
{
    int i,j;
    for(i=0 ; i < rows ; i++)
	{
		for(j=0 ; j < columns ; j++)
		{
			resMatrix[i][j] = MatrixH[i][j] * value;
		}
	}
}

void Matrix_Transpose(int MatrixH[10][10],int rows,int columns)
{
    int i, j; 
    for (i = 0; i < rows; i++)
    { 
        for (j = 0; j < columns; j++) 
        { 
            resMatrix[j][i] = MatrixH[i][j]; 
        }
    }
}