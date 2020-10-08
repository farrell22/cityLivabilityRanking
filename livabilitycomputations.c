#include "livability.h" //contains prototypes

double computePopulationDensity(int population, int squareMileage) {
	double temp = (float) population / (float) squareMileage; 
	return temp;
}

double computePollutionRating(int pollutionAmount, double populationDensity) {
	double temp = (((float) pollutionAmount *populationDensity) / POLLUTION_CONSTANT);
	return temp;
}

double computeTrafficRating(double populationDensity, int highways) {
	double temp = ((populationDensity * TRAFFIC_CONSTANT) / (float) highways);
	return temp;
}

double computeCrimePerCapita(int crimeValue, double populationDensity) {
	double temp = (((float)crimeValue * populationDensity) / CRIME_CONSTANT);
	return temp;
}

double computeExpensePerCapita(int expenseValue, double populationDensity) {
	double temp = (((float)expenseValue * populationDensity) / EXPENSE_CONSTANT);
	return temp;
}

void compute(int population, int squareMileage, int pollutionAmount, int crimeValue, int expenseValue, int highways, double populationDensity, double *trafficRating, double *pollutionRating, double *crimePerCapita, double *expensePerCapita) {
	*pollutionRating = computePollutionRating(pollutionAmount, populationDensity);
	*trafficRating = computeTrafficRating(populationDensity, highways);
	*crimePerCapita = computeCrimePerCapita(crimeValue, populationDensity);
	*expensePerCapita = computeExpensePerCapita(expenseValue, populationDensity);
}

double livability(double pollutionRating, double trafficRating, double crimePerCapita, double expensePerCapita) {
	return 100.00 - (pollutionRating + trafficRating + crimePerCapita + expensePerCapita) / LIVABILITY_CONSTANT;
}

void update(int *cityCounter, double populationDensity, double livabilityValue, double *totalLivability, double *bestLivability, char cityName[], char *bestCityName[]) {
	*cityCounter = *cityCounter + 1;
	*totalLivability = livabilityValue + *totalLivability;
	if (livabilityValue > *bestLivability) {
		*bestLivability = livabilityValue;
		strcpy(bestCityName, cityName);
	}
}