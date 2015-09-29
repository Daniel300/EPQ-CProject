#include <stdio.h>

long double interval_bisection(char eqn,int iterations,int interval) {

}

long double eval_func(char eqn, int x) {
	
}

int main()
{
	char str[3];
	str[0] = 0;
	printf("Numerical Methods: \nIntervalBisection('IB')\nPlease enter a numerical method to use: ");
	scanf("%s",str);
	printf("Input: '%s'\n",str);
	if (strcmp(str, "IB") == 0) {
		printf("Interval Bisection\n");
	}
    return 0;
}