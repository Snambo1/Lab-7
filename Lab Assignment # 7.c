#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[],int swapArr[],int size){
    int swaps=0;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[i]){
                swaps++;
                swapArr[j]++;
                swapArr[i]++;
                swap(&arr[i],&arr[j]);
                swap(&swapArr[i],&swapArr[j]);
            }
        }
    }
    for (int i=0;i<size;i++) printf("%d # times %d is swapped\n",swapArr[i],arr[i]);
    printf("%d total swaps\n\n",swaps);
}
void selectionSort(int arr[],int swapArr[],int size){
    int min; 
    int swaps=0;
    for (int i = 0; i < size-1; i++){ 
        min = i; 
        for (int j = i+1; j < size; j++) 
            if (arr[j] < arr[min]) min = j; 
        if(min != i){
            swaps++;
            swapArr[min]++;
            swapArr[i]++;
            swap(&arr[min],&arr[i]);
            swap(&swapArr[min],&swapArr[i]);
        }
    } 
    for (int i=0;i<size;i++) printf("%d # times %d is swapped\n",swapArr[i],arr[i]);
    printf("%d total swaps\n\n",swaps);
}
int main(void){
    int array1[]={97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72};
    int array1Swaps[9]={0};
    int array1Cpy[]={97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72};
    int array1SwapsCpy[9]={0};
    int array2[]={90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10};
    int array2Swaps[9]={0};
    int array2Cpy[]={90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10};
    int array2SwapsCpy[9]={0};
    bubbleSort(array1,array1Swaps,9);
    selectionSort(array1Cpy,array1SwapsCpy,9);
    bubbleSort(array2,array2Swaps,9);
    selectionSort(array2Cpy,array2SwapsCpy,9);
}