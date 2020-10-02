#include<iostream>
#include<math.h>
#include<cstring>
#define INTEGER_MAX 2147483647

using namespace std;

double formula(int n, double x0, double x1, double a0, double a1) {	

	double alfa0= (double) (a1 - x1 * a0) / (double) (x0 - x1); // preko sustava lin. jed.
	double alfa1 = a0  - alfa0; //  takoder
	double sol = (double) alfa0 * pow(x0, n) + (double) alfa1 * pow(x1, n);
	
	return sol;
	
}

double rek(double arr[], int n, double* x0, double* x1, double* a0, double* a1, double* b, double* c) {
		if(arr[n] == INTEGER_MAX){
			if (n == 1) {
				arr[n] = *a1;	
			}
			else if(n == 0) {
				arr[n] = *a0;
				
			}
			else {
				arr[n] =  *b * rek(arr, n -1, x0, x1, a0, a1, b, c) +  *c * rek(arr, n -2, x0, x1, a0, a1, b, c);
				
			}
			
		}
		
		return arr[n];
}
		

int main(void) {
	double x0, x1, a0, a1;
	int n;
	cout << "Enter first solution of characteristic equation x_0: ";
	cin >> x0;
	cout << "Enter second solution of characteristic equation x_1: ";
	cin >> x1;
	cout << "Enter third solution of characteristic equation x_2: ";
	cin >> a0;
	cout << "Enter value of the first number in sequnce a_1: ";
	cin >> a1;
	cout  << "Enter n- nth number in sequnce will be calculated: ";
	cin >> n;
	
	double arr[n + 1];
	for(int i = 0; i < n + 1; i++)
		arr[i] = INTEGER_MAX;
	double b = (x0 + x1); // koef uz A(n-1) 
	double c =  -(x0 * x1); // koef uz A(n -2)
	
	printf("Value of nth number in sequence calculated with formula: %lf\n",formula(n, x0, x1, a0, a1));
	printf("Value of nth number in sequence calculated with recurson: %lf",rek(arr, n, &x0, &x1, &a0, &a1, &b, &c));

	return 0;
	
}