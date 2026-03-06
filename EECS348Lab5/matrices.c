#include <stdio.h>
#define SIZE 5
void addMatrices(int r, int c,int arr1[r][c],int arr2[r][c]);
void multiplyMatrices(int r, int c,int arr[r][c], int r2, int c2,int arr2[r2][c2]);
//void transposeMatrix(int r, int c,int arr[r][c]);
void print_Matrices(int r, int c,int arr[r][c]);

int main(){
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };

    addMatrices(SIZE,SIZE,m1,m2);
    multiplyMatrices(SIZE,SIZE,m1,SIZE,SIZE,m2);
    return 0;
}

void addMatrices(int r, int c,int arr1[r][c],int arr2[r][c]){
    int arr3[r][c];
    for (int i=0; i<r;i++){
        for(int j = 0; j<c;j++){
            arr3[i][j] = arr1[i][j]+arr2[i][j];
        }
        
    }
    print_Matrices(r,c,arr3);
}
void multiplyMatrices(int r, int c,int arr[r][c], int r2, int c2,int arr2[r2][c2]){
    if(c!=r2){
        printf("Cannot multiply these matrices \n");
    }else {
        int arr3[r][c2];
        for (int i = 0; i <r; i++){
            for(int j =0; j<c2;j++){
                int temp = 0;
                for (int k = 0; k < c; k++){
                    temp += (arr[i][k])*(arr2[k][j]);

                }
                arr3[i][j] = temp;
                temp = 0;
                
            }
            
        }
        print_Matrices(r,c2,arr3);
    }
    

}

void print_Matrices(int r, int c,int arr[r][c]){
    for (int i = 0; i<r;i++){
        for(int j = 0; j<c;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}