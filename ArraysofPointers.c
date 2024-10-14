//Lian Welch
//10/05/24
//CIS 2107 1
//Lab 6
//To design and implement array of function pointer

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void printArray();
void minimum();
void maximum();
void average();

int main(int argc, char** argv){
    int students;
    int exams;

    printf("How many students? ");
    scanf("%d", &students);

    printf("How many exams? ");
    scanf("%d", &exams);
    printf("\n");

    int grades[MAX_ROWS][MAX_COLS];

    for(int i = 0; i < students; i++){
        for(int j =0; j < exams; j++){
            printf("Enter grade for student [%d] exam [%d] ", i, j);
            scanf("%d", &grades[i][j]);
        }
    }
    printf("\n");

    void (*f[4])(int, int, int[MAX_ROWS][MAX_COLS]) = {printArray, minimum, maximum, average};

    printf("Enter a choice:\n");
    printf("\t0  Print the array of grades \n");
    printf("\t1  Print the minimum grade \n");
    printf("\t2  Print the maximum grade \n");
    printf("\t3  Print the average of each student \n");
    printf("\t4  End Program \n");
    int choice;
    scanf("%u", &choice);

    while(choice >= 0 && choice < 4){
        (*f[choice])(students, exams, grades);
        printf("Enter a choice:\n");
        printf("\t0  Print the array of grades \n");
        printf("\t1  Print the minimum grade \n");
        printf("\t2  Print the maximum grade \n");
        printf("\t3  Print the average of each student \n");
        printf("\t4  End Program \n");
        scanf("%u", &choice);
    }
    printf("Thanks");
    exit(0);
}

//prints an array of the grades
void printArray(int students, int exams, int grades[students][exams]){
    printf("\n");
    for(int i = 0; i < students; i++){
        printf("[");
        for(int j = 0; j < exams; j++){
            printf("%d ", grades[i][j]);
            if(j < exams -1){
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("\n");
}

//Finds the lowest exam grade
void minimum(int students, int exams, int grades[students][exams]){
    int min = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] < min){
                min = grades[i][j];
            }
        }
    }
    printf("%d\n", min);
}

//Finds the highest exam grade
void maximum(int students, int exams, int grades[students][exams]){
    int max = grades[0][0];
    for(int i = 0; i < students; i++){
        for(int j = 0; j < exams; j++){
            if(grades[i][j] > max){
                max = grades[i][j];
            }
        }
    }
    printf("%d\n", max);
}

//prints the average of each student
void average(int students, int exams, int grades[students][exams]){
    for(int i = 0; i < students; i++){
        int sum = 0;
        for(int j =0; j < exams; j++){
            sum += grades[i][j];
        }
        int avg = sum/exams;
        printf("Average for student %d: %d\n", i+1, avg);
    }
}
