//Lian Welch
//9/25/24
//CIS 2107 1
//Lab 5
//Design and implement functions to proccess 2D Arrays

#include <stdio.h>
#include <stdlib.h>

int max();
void rowSum();
void columnSum();
void isSquare();
void displayOutputs();

static int rows, cols;

int main(int argc, char** argv){
    int rows;
    int cols;

    printf("Let's create a 2Dim array!\n");

    printf("How many rows? ");
    scanf("%d", &rows);

    printf("How many columns? ");
    scanf("%d", &cols);
    printf("\n");

    int array[100][100];

    for(int i = 0; i < rows; i++){
        for(int j =0; j < cols; j++){
            printf("enter [%d] [%d] ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    printf("\n");

    max(array, rows, cols);
    rowSum(array, rows, cols);
    columnSum(array, rows, cols);
    isSquare(rows, cols);
    displayOutputs(array, rows, cols);

    return 0;
}
//returns the maximum value in the 2d array
int max(int array[][100], int rows, int cols){
    int max = array[0][0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(array[i][j] > max){
                max = array[i][j];
            }
        }
    }
    return max;
}
//returns the sum of the elements in Row x of the 2d array
void rowSum(int array[][100], int rows, int cols){
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < cols; j++){
            sum += array[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, sum);
    }
    printf("\n");
    
}
//returns the sum of the elements in Column x of the 2d array
void columnSum(int array[][100], int rows, int cols){
    for(int j = 0; j < cols; j++){
        int sum = 0;
        for(int i = 0; i < rows; i++){
            sum += array[i][j];
        }
        printf("Sum of collumn %d = %d\n", j+1, sum);
    }
    printf("\n");
}
//checks if the array is square (i.e. every row has the same length as the 2d array itself).
void isSquare(int rows, int cols){
    if(rows == cols){
        printf("This is a square array.\n");
        printf("\n");
    }
    if(rows != cols){
        printf("This is not a square array.\n");
        printf("\n");
    }
    
}
//displays the 2 dim-array elements
void displayOutputs(int array[][100], int rows, int cols){
    printf("Here is your 2Dim array: \n");
    for(int i = 0; i < rows; i++){
        printf("[");
        for(int j = 0; j < cols; j++){
            printf("%d ", array[i][j]);
            if(j < cols -1){
                printf(", ");
            }
        }
        printf("]\n");
    }
}