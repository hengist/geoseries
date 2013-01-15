/*--------------------------------------------------------------------------
	Title	:	B&W chapter 2 programming problem 3, Finite Geometric
				Series.
	Source	:	FGEOSERI.C
	Date	:	23 April 1996
	Modified:	15 January 2013 (removed Borland conio.h references)
	Author	:	P.A. Morris
	Input	:	Two doubles and one integer, see description for details.
	Output	:	Echoes input, then gives the solution to the series as both
				an accumulated sum and by formula.
Description	:	A finite geometric series is a summation of the form
					a+ar+arý+...ar^n.
	If r is not 1, this sum is equal to

					 Ú 1 - r^n+1 ¿
					a³ ÄÄÄÄÄÄÄÄÄ ³.
					 À   1 - r   Ù

	Write an interactive program that allows the user to demonstrate this
	result. Have the user input two doubles (a,r) and one integer (n), then
	produce output such as

	For a = 4.0, r = 2.0, and n = 3:
	Accumulated sum: ar + a(r^2) + ... + a(r^n) = 60.0, and
	Formula :		 a { [  1 - r^(n+1) ] / [ 1 - r ] } = 60.

	where the caret symbol (^) indicates exponentiation.
	Calculate the first summation value using a for-loop to accumulate the
	sum; calculate the second summation value using the given formula.
	In both calculations use another for-loop to evaluate exponentials
	such as rý, r^n, and r^n+1. For the second and third output lines, use
	strings for the expressions on the left of the equals signs.
--------------------------------------------------------------------------*/

#include	<stdio.h>

	/*	Function declarations	*/

	double	power(double base, int exponent),
			sumseries(double a, double r, int n);

int main(){
	double	a, r, accsum;
	int n;

	printf("\n\tThis program demonstrates two ways of solving a finite");
	printf("\n\tgeometric series, of the form\n\n\t\ta+ar+ar^2...ar^n.\n\n");
	printf("\tFirst, we need values for a, r and n.\n"
			"\n\tEnter a real number (a): ");
	scanf("%lf", &a);
	printf("\n\tEnter another real number (r): ");
	scanf("%lf", &r);
	printf("\n\tNow enter an integer (n): ");
	scanf("%d", &n);

		/*	calculate and print the accumulated sum	*/

	accsum = sumseries(a, r, n);
	printf("\n\n\tFor a = %6.2lf, r  = %6.2lf, and n = %d:", a, r, n);
	printf("\n\tAccumulated sum: a + ar + a(r^2) +...+ a(r^n) ="
			" %6.2lf", accsum);

		/*	calculate and print the series with the formula	*/

	accsum = a * (( 1 - power(r,(n+1))) / (1 - r));
	printf(", and\n\tFormula :   a ( [ 1 - r^(n+1) ] / [ 1 - r ] ) ="
			" %6.2lf.",	accsum);
	return 0;
}

/*--------------------------------------------------------------------------
	function sumseries(a, r, n) -
	Returns the accumulated sum of the series
*/

double	sumseries(double a, double r, int n){
	int 	i;				/* 	index variable				*/
	double	sum	= 0;		/*	return value of function	*/

	for(i = 0; i < n+1; i++){
		sum += (a * power(r, i));
	}
	return sum;
}

/*--------------------------------------------------------------------------
	function power(base, exponent) -
	Returns the power of the base to the given exponent by repeated
	multiplication of a value (initialised to 1, as n^0 is always 1) by
	the base, exponent times.
*/

double	power(double base, int exponent){
	int i;
	int value = 1;

	for( i = 0; i < exponent; i++){
		value *= base;
	}
	return value;
}

/*========================================================================*/
