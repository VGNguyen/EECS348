#include <stdio.h>
#include <ctype.h>
float celsius_to_fahrenheit (float celsius);
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
void categorize_temperature(float celsius);


int main(){
    //Initialize a loop variable, original temperature unit, what temperature, and which unit to conver to
    int pass = 1;
    char og;
    float temp;
    char change;
    //Scan each unit in and save values
    printf("Enter what unit for original temperature, 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
    scanf(" %c",&og);
    printf("Enter the temperature: ");
    scanf(" %f",&temp);
    printf("Enter which temperature to convert to 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
    scanf(" %c",&change);
    //This variable is to hold the Celcius value of the temperature whenever it gets converted so it can be used later for categorize temperature
    float later_weather = 0;
    //Loop until there is a valid inputs
    while(pass ==1){
        //If celcius save the later temp immediately, check if it is valid kelvin, convert to seperate units and change the while loop variable to no longer continue
        if(tolower(og)=='c'){
            later_weather=temp;
            if(celsius_to_kelvin(temp)<0){
                printf("Invalid temperature, below 0 Kelvin");
            }else{
                if(tolower(change)=='k'){
                    temp = celsius_to_kelvin(temp);
                    pass = 0;
                }else if(tolower(change)=='f'){
                    temp = celsius_to_fahrenheit(temp);
                    pass = 0;
                }else{
                    printf("Can't convert to that unit");
                }
            }
        //If fahrenheit, go through celcius and save the later weather for that value and check kelvin also for valid temp.
        }else if(tolower(og)=='f'){
            if (tolower(change)=='k'){
                temp = fahrenheit_to_celsius(temp);
                later_weather = temp;
                if(celsius_to_kelvin(temp)<0){
                    printf("Invalid temperature, below 0 Kelvin");
                }else{
                    temp =celsius_to_kelvin(temp);
                    pass=0;
                }
            }else if(tolower(change)=='c'){
                temp = fahrenheit_to_celsius(temp);
                later_weather = temp;
                if(celsius_to_kelvin(temp)<0){
                    printf("Invalid temperature, below 0 Kelvin");
                }else{
                    pass = 0;
                }
            }else{
                printf("Can't convert to that unit");
            }
        //Repeated proccess of the other ones but this can check immediately if its invalid kelvin and switch later
        }else if(tolower(og)=='k'){
            if(temp<0){
                printf("Invalid temperature, below 0 Kelvin");
            }if(tolower(change)=='c'){
                temp = kelvin_to_celsius(temp);
                later_weather = temp;
                pass=0;
            }else if(tolower(change)=='f'){
                temp = kelvin_to_celsius(temp);
                later_weather = temp;
                temp = celsius_to_fahrenheit(temp);
                pass = 0;
            }else{
                printf("Can't convert to that unit");
            }
            
        }else{
            printf("Not a valid starting unit");
        }
        //If the checks for valid temperatures and units did not pass then ask for every value again
        if(pass==1){
            printf("\n");
            printf("Enter what unit for original temperature, 'F'ahrenheit,'C'elcius, or 'K'elvin: ");
            scanf(" %c",&og);
            printf("Enter the temperature: ");
            scanf(" %f",&temp);
            printf("Enter which temperature to convert to 'F'ahrenheit,'C'elcius, or 'K'elvin:");
            scanf(" %c",&change);
        }
        

    }
    //Print the converted temperature and call the categorize_temperature function
    printf("Converted temperature: %f \n",temp);
        
    categorize_temperature(later_weather);


    return 0;
}
//Conversion functions between units
float celsius_to_fahrenheit (float celsius){
    return celsius*9/5+32;
}
float fahrenheit_to_celsius (float fahrenheit){
    return (fahrenheit-32)*5/9;
}
float celsius_to_kelvin (float celsius){
    return celsius-273.15;
}
float kelvin_to_celsius (float kelvin){
    return kelvin+273.15;
}
//Depending on the temperature tell the user about what they should do in accordance to the temperature outside.
void categorize_temperature(float celsius){
    if(celsius<=0){
        printf("Wear a coat");
    }else if(celsius<=10){
        printf("Wear a jacket");
    }else if(celsius<=25){
        printf("Its nice weather");
    }else if(celsius<=35){
        printf("Drink lots of water");
    }else{
        printf("Stay indoors with some air conditioning");
    }
}
