#include <stdio.h>



int main(){
    FILE *fptr;
    fptr = fopen("sales.txt", "r");
    
    if(fptr==NULL){
        return 1;
    }
    int line = 0;
    char sales[100];
    float store[12];

    while(line<12 && fscanf(fptr, "%f",&store[line])==1){
        line++;
    }
    const char *months[12];
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
    for(int i = 0; i<12; i++) {
        printf("%s %.2f \n", months[i], store[i]);
    }

    float max = store[0];
    int max_index = 0;
    float min = store[0];
    int min_index =0;
    float sum= 0;
    for(int i =0; i<12;i++){
        if(store[i]<min){
            min= store[i];
            min_index=i;

        }
        if(store[i]>max){
            max= store[i];
            max_index=i;
        }
        sum+=store[i];
    }
    sum = sum/12;
    printf("Maximum Sales %.2f (%s) \n", max, months[max_index]);
    printf("Minimum Sales %.2f (%s) \n", min, months[min_index]);
    printf("Average Sales %.2f \n", sum);

    for(int i =0; i<7;i++){
        float temp_sum=0;
        for(int j =i;j<i+6;j++){
            temp_sum+=store[j];
        }
        temp_sum= temp_sum/6;
        printf("%s-%s %.2f \n",months[i],months[i+5],temp_sum);
    }
    fclose(fptr); 
    return 0;
}