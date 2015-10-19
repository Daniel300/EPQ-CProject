#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

char** split_func(char* eqn)
{
	char** result = 0;
	size_t count = 0;

	char delim[2];
	delim[0] = ',';
	delim[1] = 0;

	char* count_str = eqn;
	char* last_delim = 0;

	/* Check how much memory is required */
	while (*count_str)
	{
		if (delim[0] == *count_str)
		{
			count++;
			last_delim = count_str;
		}
		count_str++;
	}

	count += last_delim < (eqn + strlen(eqn) - 1);

	count++;

	/* Allocate memory for result */
	result = malloc(sizeof(char*) * count);

	/* Split string */
	if (result)
	{
		size_t idx = 0;
		char* token = strtok(eqn, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

long double eval_func(char eqn, double x)
{
	/*char** tokens;
	tokens = split_func(eqn);
	int i;
	for (i = 0; *(tokens + i); i++) {
		if (!isdigit(*(tokens + i))) {

		}
	}*/
	return (3 * pow(x, 2) + 2*x - 2);
}

long double interval_bisection(char* eqn,int iterations,double* interval)
{
	int i;
	long double zero = 0;
	long double lower = 0;
	long double upper = 1;
	int valid = 1;
	/*printf("%lf, %lf, ", interval[0], eval_func(eqn,interval[0]));*/
	if (eval_func(eqn, interval[0]) < zero)
	{
		lower = interval[0];
		if (eval_func(eqn, interval[1]) > zero) {
			upper = interval[1];
		}
		else {
			valid = 0;
		}
	}
	else {
		upper = interval[0];
		if (eval_func(eqn, interval[1]) < zero) {
			lower = interval[1];
		}
		else {
			valid = 0;
		}
	}
	for (i = 0; i < iterations; i++)
	{
		double newVal = (upper + lower) / 2;
		double res = eval_func(eqn, newVal);
		if (res < zero) {
			lower = newVal;
				printf("\nNew lower: %lf", lower);
		}
		else if (res > zero) {
			upper = newVal;
			printf("\nNew upper: %lf", upper);
		}
		else {
			return newVal;
			printf("exact");
		}
	}
	return upper;
}

int main()
{
	char eqn[26];
	printf("Input your equation to be solved: ");
	scanf("%s", eqn);
	char** tokens;
	tokens = split_func(eqn);
	int i;
	for (i = 0; *(tokens + i); i++)
		printf("%s\n", *(tokens + i));

	char str[3];
	printf("Numerical Methods: \nIntervalBisection('IB')\nPlease enter a numerical method to use: ");
	scanf("%s",str);
	printf("Input: '%s'\n",str);
	if (strcmp(str, "IB") == 0) 
	{
		long double interval[2];
		int iterations;
		printf("\nInterval Bisection\n\nInput your interval: \nFirst value: ");
		scanf("%lf", &interval[0]);
		printf("Second value: ");
		scanf("%lf", &interval[1]);
		printf("\nInput the number of iterations: ");
		scanf("%i", &iterations);

		printf("\n\nResult: %lf",interval_bisection(eqn, iterations, interval));
	}
	getch();
    return 0;
}