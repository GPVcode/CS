#include <iostream>

using namespace std;

// Create three classes
	// 1. Order class - this class takes the input from customer questions and sends it to order calculator class
	// 2. Pricing class - this class holds data on pricing structure.
	// 3. Order calculator class - this class takes the input information from order class and the pricing detailes from pricing class and calculates the total.

// first let's get basic pricing to work.
	// establish a shirt cost for 10 dollars and get the total cost to output properly


// create pricing class
// create order class
// create order calculator class
main(){

	double totalCost = 0.0;

	class ShirtOrder {
		public: 
			bool printBothSides;
			int colorCount;
			int shirtCount;
			int small, medium, large, xl;

			void printOnBothSides(string n){
				if(n == "yes"){
					printBothSides = true;
				} else {
					printBothSides = false;
				};
			};
			void shirtColorCount(int n){
				colorCount = n;
			};
			void shirtCount(int n){
				shirtCount = n;
			};
			void smallCount(int n){
				small = n;
			};
			void mediumCount(int n){
				medium = n;
			};
			void largeCount(int n){
				large = n;
			};
			void xlCount(int n){
				xl = n;
			};
	};


	class CostCalculator(){

	};

	do{
		ShirtOrder

		// Print on both sides?
		cout << "Do you want to print on both sides?";
		// How many colors?
		// How many t-shirts to print?
		// Out of X shirts, type in how many small (if no more shirts left after the input and calculation, break the loop)
		// (Subtract from total shirts) out of X(updated shirt count) shirts, type how many medium( if no more shirts left after the input and calculation, break the loop)
		// (Subtract from total shirts) out of X(updated shirt count) shirts, type how many large shirts (if no more shirts left after the input and calculation, break the loop)
		// Subtract from total shirts) you want X(updates shirt counts) XL shirts correct?

		totalCost = // output from 
		// get info from order class
		// get info from pricing class
		// run order calculator

	} while(totalCost == 0.0); {


		cout << "Total cost of the order is: $ " << totalCost << endl;

	};

	return 0;
};