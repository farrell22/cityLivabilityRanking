#include "livability.h" //contains prototypes

int input(FILE *fp1, char cityName[], int *population, int *squareMileage, int *pollutionValue, int *crimeValue, int *expenseValue, int *highways) {
	return fscanf(fp1, "%s %i %i %i %i %i %i", cityName, population, squareMileage, pollutionValue, crimeValue, expenseValue, highways);
}

void output(char cityName[], double populationDensity, double livabilityValue, int *cityCounter) {
	if (*cityCounter == 0) {
		printf("\t%15CCity \t\t\t%.3 Population Dens. \t%.3 Livability\n");
	}
	printf("\t%-15s \t %.3f \t\t %.3f\n", cityName, populationDensity, livabilityValue);
}

void summary(int cityCounter, double totalLivability, char bestCityName[], double bestLivability) {
	double averageLivability = totalLivability / (float)cityCounter;
	printf("Best city: %s, with a livability of %.3f\n", bestCityName, bestLivability);
	printf("The %i cities have an average livability of %.3f", cityCounter, averageLivability);
}