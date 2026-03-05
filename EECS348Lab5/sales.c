#include <stdio.h>
#include <stdbool.h>


int main(){
    //Open the file to read
    FILE *fptr;
    fptr = fopen("sales.txt", "r");
    //Make sure the file is actually being accessed, if not quit the program.
    if(fptr==NULL){
        return 1;
    }

    int line = 0;
    char sales[100];
    float store[12];
    //Scan the line where the fptr is at and make sure it stores in the array full of values. Keep scanning while there is lines or until it hits 12 items
    while(line<12 && fscanf(fptr, "%f",&store[line])==1){
        line++;
    }
    //Array full of months for easier printing later
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
    //Print out every month and the earnings they made.
    for(int i = 0; i<12; i++) {
        printf("%s %.2f \n", months[i], store[i]);
    }

    float max = store[0];
    int max_index = 0;
    float min = store[0];
    int min_index =0;
    float sum= 0;
    //Loop through the list, if you find an item that is bigger than current maximum or smaller than current min make that the new respective value
    //Add up every value you pass through for average later
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
    //Calculate average and print values
    sum = sum/12;
    printf("\nSales summary report: \n \n");
    printf("Maximum Sales %.2f (%s) \n", max, months[max_index]);
    printf("Minimum Sales %.2f (%s) \n", min, months[min_index]);
    printf("Average Sales %.2f \n", sum);
    printf("\nSix-Month moving average report: \n \n");

    //First loop is starting month, second loop starts from starting month and counts up 6 months worth of values and adds them up to be averaged and printed after the loop ends
    for(int i =0; i<7;i++){
        float temp_sum=0;
        for(int j =i;j<i+6;j++){
            temp_sum+=store[j];
        }
        temp_sum= temp_sum/6;
        printf("%s-%s %.2f \n",months[i],months[i+5],temp_sum);
    }
    int largest[12];
    int i = 0;
    //Have a that will now be sorted by largest to smallest. It will store the index of the largest and smallest. 
    while(i<12){
        float temp_large = 0;
        int temp_index;
        //Loop through the list until you have all 12 items in the sorted list. 
        for (int j = 0; j<12;j++){
            if(store[j]>temp_large){
                bool inList = false;
                //Check that the item is not already in the list of sorted numbers, if not you can add it in
                for(int l =0; l<i;l++){
                    if(largest[l]==j){
                        inList=true;
                    }
                }
                if(inList){

                }else{
                    temp_large=store[j];
                    temp_index = j;
                }

            }
        }
        //Store whichever index ends up being highest that is not in the list
        largest[i] = temp_index;
        i++;
    }
    printf("\nSales report (highest to lowest): \n \n");
    printf("Month   Sales \n");
    for(int j = 0; j<12;j++){
        printf("%s   $%.2f \n",months[largest[j]],store[largest[j]]);
    }
    fclose(fptr); 
    return 0;
}