#define _CRT_SECURE_NO_WARNINGS // to avoid the fscanf error message
#include <stdio.h> // for printf and fscanf
#include <string.h> // in order to use strcpy

#define POLLUTION_CONSTANT 1112.2 //constant for use in calculating pollution
#define TRAFFIC_CONSTANT 2.13 //constant for use in calculating traffic
#define CRIME_CONSTANT 924.6 //constant for use in calculating crime per capita
#define EXPENSE_CONSTANT 1217.1 //constant for use in calculating expense
#define LIVABILITY_CONSTANT 13.81 // constant for use in calculating livability

//Function prototypes

int input(FILE*, char[], int*, int*, int*, int*, int*, int*); // receives the input text file and inputs the values for what will be 
// String cityName, int population, int squareMileage, int pollutionValue, int crimeValue, int expenseValue, and int highways.
double computePopulationDensity(int, int); //receives int population and int squareMileage, then uses these values to 
// compute and return double populationDensity

double computePollutionRating(int, double); // computes double pollutionRating and returns it
double computeTrafficRating(double, int); // computes double trafficRating and returns it
double computeCrimePerCapita(int, double); // computes double crimePerCapita and returns it
double computeExpensePerCapita(int, double); // computes double expensePerCapita and returns it
void compute(int, int, int, int, int, int, double, double*, double*, double*, double*); // call functions to compute city's (1) pollution rating, (2) traffic rating, (3) crime per capita, 
// and (4) expense per capita. store these values in their respective variables, updating them in main (return void)

double livability(double, double, double, double); // takes pollutionRating, trafficRating, crimePerCapita, and expensePerCapita and totals them up, 
//subtracts the value from 100 and divides by a constant, to return the livability rating used to judge the cities in the program
void output(char[], double, double, int*); // outputs the information about the current city in the loop (its name, populationDensity and livabilityValue). this 
//function also receives the cityCounter in order to determine if the city being output is the first of the loop. If so, it prints column headers before the city info.
void update(int*, double, double, double*, double*, char[], char*[]); //receive the number of cities, the current city’s name and livability rating, the total livability 
// of the cities so far, and the best livability and that city’s name, and perform an update by adding 1 to the number 
// of cities, update the total livability by adding this city’s livability to it, determine if this city’s livability 
// is better than that previous bestand if so, update both the best livability and the best livability city’s name.
void summary(int, double, char[], double); //receive the number of cities, total livability, best city name and livability, compute the avg livability
// and output the number of cities, avg livability and best city name and livability, all in a formatted way