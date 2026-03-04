#include <stdio.h>
void print_possible_scores(int n);


int main(){
    int score = 0;
    printf("Enter 0 or 1 to STOP \n");
    printf("Enter the NFL score: \n");
    scanf("%d",&score);
    if(score ==1 || score ==0){

    }else if(score<0){
        printf("That is not a valid value");
        
    }else{
        print_possible_scores(score);
    }
    
    return 0;
}

void print_possible_scores(int n) {
    
    //Keep looping for each value until it reaches a value greater than the wanted score and then add one to the next greater variable and keep looping

    for(int m = 0; m<=n/8;m++){
        for(int l = 0; l<=n/7;l++){
            for(int k = 0; k<=n/6;k++){
                for(int j = 0; j<=n/3;j++){
                    for(int i = 0; i<=n/2;i++){
                        //Variable to see if the current values of the loop equal the wanted score
                        int count = m*8+l*7+k*6+j*3+i*2;
                        if(count==n){
                            //print out the score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", m,l,k,j,i);
                        //If the total of all the values is greater than the wanted score, end the current iteration and add 1 to next loop
                        }else if(count>n){
                            break;
                        }


                    }
                }
            }
        }
    }
}

