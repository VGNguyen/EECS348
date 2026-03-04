#include <stdio.h>



int main(){
    FILE *fptr;
    fptr = fopen("sales.txt", "r");
    
    if(fptr==NULL){
        return 1;
    }
    int line = 0;
    char sales[12];
    float store[12];

    while(!feof(fptr) && !ferror(fptr)){
        if (fgets(sales[line],12,fptr) !=NULL){
            store[line] = (float)sales[line];
            line++;
        }
    }

    printf("January %f",store[0]);
    printf("Feburary %f",store[1]);
    printf("March %f",store[2]);
    printf("April %f",store[3]);
    printf("May %f",store[4]);
    printf("June %f",store[5]);
    printf("July %f",store[6]);
    printf("August %f",store[7]);
    printf("September %f",store[8]);
    printf("October %f",store[9]);
    printf("November %f",store[10]);
    printf("December %f",store[11]); 

    fclose(fptr); 
    return 0;
}