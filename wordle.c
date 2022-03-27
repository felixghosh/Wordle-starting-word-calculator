#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 12947
int indices[SIZE];

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1]){
              swap(&arr[j], &arr[j+1]);
              swap(&indices[j], &indices[j+1]);
           }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

int main(){
    FILE* res = fopen("res.txt", "w");
    int points[SIZE];
    char** words = calloc(SIZE, sizeof(char*));
    for(int i = 0; i < SIZE; i++)
        words[i] = calloc(6, sizeof(char));
    char word[5];
    char dictWord[5];
    memset(word, 0, 5);
    memset(dictWord, 0, 5);
    int c, i, j;
    for(i = 0; i < SIZE; i++){
        points[i] = 0;
        indices[i] = i;
        for(int j = 0; j < 5; j++)
            words[i][j] = getchar();
        getchar();
    }
    for(i = 0; i < SIZE; i++){  //for each word
        for(j = 0; j < 5; j++)
            word[j] = words[i][j];
        for(int k = 0; k < SIZE; k++){  //load and check against each word
            for(j = 0; j < 5; j++)
                dictWord[j] = words[k][j];
            for(j = 0; j < 5; j++){
                c = word[j];
                if(c == dictWord[j])
                    points[i] += 2;
                for(int h = 0; h < 5; h++){
                    if(c == dictWord[h]){
                        points[i]++;
                        //break;
                    }
                }
            }
        }
    }
    
    bubbleSort(points, SIZE);
    //printArray(points, SIZE);
    //printArray(indices, SIZE);
    char buf[100];
    
    for(i = 0; i < SIZE; i++){
        memset(buf, 0, 100);
        strcpy(buf, words[indices[i]]);
        strcat(buf, ": ");
        char point[20];
        memset(point, 0, 20);
        sprintf(point, "%d", points[i]);
        strcat(buf, point);
        strcat(buf, "\n");
        fputs(buf, res);
    }
    fclose(res);
    free(words);
    return 0;
}   