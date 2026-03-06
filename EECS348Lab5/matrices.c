#include <stdio.h>
#define SIZE 5
void addMatrices(int r, int c,int arr1[r][c],int arr2[r][c]);
void multiplyMatrices(int r, int c,int arr[r][c], int r2, int c2,int arr2[r2][c2]);
void transposeMatrix(int r, int c,int arr[r][c]);
void print_Matrices(int r, int c,int arr[r][c]);

int main(){
    //Declare matrices and then add, multiply, and transpose them
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
    printf("Adding m1 and m2: \n");
    addMatrices(SIZE,SIZE,m1,m2);
    printf("Multiplying m1 and m2: \n");
    multiplyMatrices(SIZE,SIZE,m1,SIZE,SIZE,m2);
    printf("Transposing m1: \n");
    transposeMatrix(SIZE,SIZE,m1);
    return 0;
}

void addMatrices(int r, int c,int arr1[r][c],int arr2[r][c]){
    //Define a third matrix
    int arr3[r][c];
    //Loop through every value and add up arr1 and arr2 at that place and put that into arr3
    for (int i=0; i<r;i++){
        for(int j = 0; j<c;j++){
            arr3[i][j] = arr1[i][j]+arr2[i][j];
        }
        
    }
    //print the completed added matrix arr3
    print_Matrices(r,c,arr3);
}

void multiplyMatrices(int r, int c,int arr[r][c], int r2, int c2,int arr2[r2][c2]){
    //Make sure the arrays are the correct size to multiple
    if(c!=r2){
        printf("Cannot multiply these matrices \n");
    }else {
        //Define new third array to store values that is the size of arr1's rows and arr2's columns
        int arr3[r][c2];
        
        for (int i = 0; i <r; i++){
            for(int j =0; j<c2;j++){
                //Matrix multiplication has you multiple each value in a row, add those values together, and then place them in the multiplied array
                int temp = 0;
                for (int k = 0; k < c; k++){
                    temp += (arr[i][k])*(arr2[k][j]);

                }
                //Set the value in the matrix to the temp value and reset temp
                arr3[i][j] = temp;
                temp = 0;
                
            }
            
        }
        //Print out the completed result
        print_Matrices(r,c2,arr3);
    }
}

void transposeMatrix(int r, int c,int arr[r][c]){
    //arr2 will be the transpose with flipped sizes compared to arr1
    int arr2[c][r];
    for(int i =0; i<r;i++){
        for(int j =0; j<c;j++){
            //arr1's values are moved in a reversed way to arr2 so, the orders of arr2[j][i] taking on the values of arr[i][j] will give the transpose
            arr2[j][i]=arr[i][j];
        }
    }
    //print out the transposed result
    print_Matrices(c,r,arr2);
}


void print_Matrices(int r, int c,int arr[r][c]){
    //Print each value per row and then end each row with a newline
    for (int i = 0; i<r;i++){
        for(int j = 0; j<c;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}