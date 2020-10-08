//Emily Farrell
//CSC 362 Programming Assignment 2
//This program calculates the livability of various cities and outputs them for comparison. 
//To do this, the program inputs a text file using fscanf and stores information about the city into a string and integer variables.
//The ints are passed to five functions: computePopulationDensity(...), computePollutionRating(...), computeTrafficRating(...),
//computeCrimeRating(...), and computeExpensePerCapita(...). These functions use the basic info about the city provided
//by input(...) to store ratings about the quality of the city as doubles. The last four doubles are passed to another function,
//compute(...), which is called in main and runs the other functions when called. Each city is looped through and its information is
//output into columns to console. At the end of the loop, each city's ratings are compared inside the update() function. 
//The city with the highest livability rating, alongside the average livability, is printed after the while loop when summary() is called.

#include "livability.h" //contains prototypes

void main() {
	int squareMileage; int population; int crimeValue; int highways; int expenseValue; int pollutionAmount; // variables to hold int values from file
	double crimePerCapita; double expensePerCapita; double pollutionRating; double populationDensity; double trafficRating; // doubles hold results of computational functions
	char cityName[15] = ""; // holds city name which is input from file 
	double livabilityValue; // holds result of compute() 
	FILE* fp1; // the input file
	int cityCounter = 0; //counter for the output function to test if first output
	double totalLivability = 0; double bestLivability = 0; // variables in the summary function that hold total livability and the best livability for that point in the while loop
	char bestCityName[15] = ""; // to hold the best city name after each iteration of update()

	fp1 = fopen("cities2-1.txt", "r"); // open file for input
	//insert the 7 function calls, while next line is not end of file
	while (input(fp1, cityName, &population, &squareMileage, &pollutionAmount, &crimeValue, &expenseValue, &highways) != EOF) {
		populationDensity = computePopulationDensity(population, squareMileage); // calculate and store population density
		compute(population, squareMileage, pollutionAmount, crimeValue, expenseValue, highways, populationDensity, &trafficRating, &pollutionRating, &crimePerCapita, &expensePerCapita); // pass the rest of the basic info (ints from file, doubles to store the scores) needed to rank the city on its traffic, population, crime, and expensiveness
		livabilityValue = livability(pollutionRating, trafficRating, crimePerCapita, expensePerCapita); // assign an overall "livability" score to the city by using the above calculated categorical rankings
		output(cityName, populationDensity, livabilityValue, &cityCounter); // output the city's information formatted into columns
		update(&cityCounter, populationDensity, livabilityValue, &totalLivability, &bestLivability, cityName, &bestCityName); //check if the current city's score is better than the best city's so far
	}
	summary(cityCounter, totalLivability, bestCityName, bestLivability); //print results of comparisons
	fclose(fp1); //close file when done with it
}

/*		City                     Population Dens.        Livability
        Atlanta                  451.209                 52.363
        Boston                   517.143                 36.146
        Cincinnati               298.633                 72.542
        Dallas                   251.294                 77.090
        Las_Vegas                158.677                 83.462
        Los_Angeles              576.612                 16.672
        Minneapolis              303.487                 72.202
        New_York_City            730.751                 6.360
        Seattle                  370.022                 64.140
        Washington_DC            493.871                 41.381
Best city: Las_Vegas, with a livability of 83.462
The 10 cities have an average livability of 52.236
\\fileserv2.hh.nku.edu\farrelle2$\Desktop\CSC 362\csc362program2\Debug\csc362program2.exe (process 8532) exited with code 0.
*/