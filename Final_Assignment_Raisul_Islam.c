#include <stdio.h>

/*
Name: Raisul Islam
ID: 2023000010059
Course Code: CSE161
Section: 11

Task: Daily temperature readings for a city over a certain period.

I've added a navigation menu system with exit functionality to help the user operate the program. Added some major functions.

Function 1: I have added a function to show all temperature data in a set of tables.
Function 2: Added a function to calculate and show the highest and lowest temperature.
Function 3: Added a function to calculate and show average temperature.
Function 4: Added a function to calculate Celsius to Fahrenheit or Fahrenheit to Celsius.
*/


#define MAX_DAYS 90 //I have define maximum of 90 days value for input as a days.

//Here is the functions for usage
void inputTemperature(double temperature[], int daysData);
void tableData(double temperature[], int daysData);
double averageCalculate(double temperature[], int daysData);
void minimumMaximum(double temperature[], int daysData, int *minTemperature, int *maxTemperature);
void temperatureConvert(double temperature[], int daysData, char convertFrom, char convertTo);

//This is the main function start 
int main() {
    int daysData; //input from user how many days need to collect the data as a days
    printf("Enter the number of days, how many days you need: ");
    scanf("%d", &daysData);

    if (daysData <= 0 || daysData > MAX_DAYS) {
        printf("Invalid number of days. Please enter a value 1 to 90. It supports a maxium of 3 months.\n");
        return 1;
    }

    double temperature[MAX_DAYS];

    inputTemperature(temperature, daysData);
    
    
    int userInput; //Declare the variable to use user input for menu
    char unitChoice; //Declare the variable to use convert Celsius or Fahrenheit

    do {
        //User navigation section
        printf("\nNavigation Menu:\n");
        printf("1--> Show ALL Temperature Data Table.\n");
        printf("2--> Calculate Highest and Lowest Temperatures.\n");
        printf("3--> Calculate Average Temperature.\n");
        printf("4--> Convert Temperatures.\n");
        printf("5--> Exit\n");
        printf("Enter your choice, navigate using numbers: ");
        scanf("%d", &userInput);

        if (userInput == 1) {
            //Display all temperature data table sets
            tableData(temperature, daysData);
        } else if (userInput == 2) {
            //Calculate and display highest and lowest temperature, i've declare .2f because of temperature normally define by 2 decimal
            int minTemperature, maxTemperature;
            minimumMaximum(temperature, daysData, &minTemperature, &maxTemperature);
            printf("The Lowest Temperature: Day %d : %.2f\n", minTemperature + 1, temperature[minTemperature]);
            printf("The Highest Temperature: Day %d : %.2f\n", maxTemperature + 1, temperature[maxTemperature]);
        } else if (userInput == 3) {
            //Calculate and display average temperature
            printf("The Average of Temperatures: %.2f\n", averageCalculate(temperature, daysData));
        } else if (userInput == 4) {
            //Convert temperatures Celsius or Fahrenheit
            printf("Type the value (C or F) to convert from Celsius or Fahrenheit: ");
            scanf(" %c", &unitChoice);
            temperatureConvert(temperature, daysData, unitChoice, (unitChoice == 'C' || unitChoice == 'c') ? 'F' : 'C');
            tableData(temperature, daysData);
        } else if (userInput == 5) {
            //Close the program
            printf("Thank you, program has been closed.\n");
        } else {
            printf("Invalid choice. Please enter a valid number to navigate the program.\n");
        }

    } while (userInput != 5);

    return 0;
}

//Use this function to help the user how the temperature data collect 
void inputTemperature(double temperature[], int daysData) {
    printf("Enter daily temperature data that you've choose before:\n");
    for (int i = 0; i < daysData; ++i) {
        printf("Day %d: ", i + 1);
        scanf("%lf", &temperature[i]);
    }
}

//Use this function to calculate the average
double averageCalculate(double temperature[], int daysData) {
    double sum = 0.0;
    for (int i = 0; i < daysData; ++i) {
        sum = sum + temperature[i];
    }
    return sum / daysData;
}

//Use this function to calculate minimum or maximum temperature
void minimumMaximum(double temperature[], int daysData, int *minTemperature, int *maxTemperature) {
    *minTemperature = *maxTemperature = 0;

    for (int i = 1; i < daysData; ++i) {
        if (temperature[i] < temperature[*minTemperature]) {
            *minTemperature = i;
        }
        if (temperature[i] > temperature[*maxTemperature]) {
            *maxTemperature = i;
        }
    }
}

//Use this function to show all temperature data that user input as a table
void tableData(double temperature[], int daysData) {
    printf("Temperature Data Table:\n");
    for (int i = 0; i < daysData; ++i) {
        printf("Day %d: %.2f%s", i + 1, temperature[i], (i < daysData - 1) ? ", " : "\n");
    }
}

//Use this function to show convert Celsius or Fahrenheit
void temperatureConvert(double temperature[], int daysData, char convertFrom, char convertTo) {
    if (convertFrom == 'C' || convertFrom == 'c') {
        if (convertTo == 'F' || convertTo == 'f') {
            //Celsius to Fahrenheit (Temperature in degrees Celsius (°C) * 9/5) + 32
            for (int i = 0; i < daysData; ++i) {
                temperature[i] = (temperature[i] * 9 / 5) + 32;
            }
        } else {
            printf("Invalid choice. Please type 'F' or 'f' for Fahrenheit.\n");
        }
    } else if (convertFrom == 'F' || convertFrom == 'f') {
        if (convertTo == 'C' || convertTo == 'c') {
            //Fahrenheit to Celsius (32°F − 32) × 5/9 = 0°C
            for (int i = 0; i < daysData; ++i) {
                temperature[i] = (temperature[i] - 32) * 5 / 9;
            }
        } else {
            printf("Invalid choice. Please type 'C' or 'c' for Celsius.\n");
        }
    } else {
        printf("Invalid choice. Please type 'C' or 'c' for Celsius convert, 'F' or 'f' for Fahrenheit convert.\n");
    }
}
