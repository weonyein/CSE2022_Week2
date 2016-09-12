#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getrandom(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}

bool circle(const double x, const double y)
{
	const double x_c = 1;
	const double y_c = 0.5;
	const double b = 0.5;
	const double a = 1;

	const double f = b*b*(x - x_c)*(x - x_c) + a*a*(y - y_c)*(y - y_c) - a*a*b*b;

	if (f > 0.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("elipse.text", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getrandom(0.0, 2.0);
		double y = getrandom(0.0, 1.0);

		if (circle(x, y) == true)
			fprintf(of, "%f %f\n", x, y);
	}
	fclose(of);
}