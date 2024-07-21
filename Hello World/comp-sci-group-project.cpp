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
class ShirtOrder {
	public: 
		bool printBothSides;
		int colorCount;
		int shirtCount;
		int small, medium, large, xl;
		bool shirtSizeSegmentationConfirmation;

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
		void shirtOrderCount(int n){
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
		void shirtSegmentationConfirmation(string n){
			if(n == "yes"){
				shirtSizeSegmentationConfirmation = true;
			} else{
				shirtSizeSegmentationConfirmation = false;
			}
		}
};

// class CostCalculator(){

// };

int main(){

	double totalCost = 0.0;
	ShirtOrder order;

	do{
		string printBothSidesInput;
		int colorCountInput;
		int shirtCountInput;
		int smallInput, mediumInput, largeInput;
		int shirtsRemaining;

		// helper function
		auto shirtsRemainingFunction = [&order](int n) {
			return order.shirtCount - n;
		};

		cout << "Do you want to print on both sides? Type yes or no."<< endl;
		cin >> printBothSidesInput;
		order.printOnBothSides(printBothSidesInput);

		cout << "How many colors are in the print? (Type a number from 1-5.)"<< endl;
		cin >> colorCountInput;
		order.shirtColorCount(colorCountInput);

		cout << "How many t-shirts do you need? Type a number from 12 or over."<< endl;
		cin >> shirtCountInput;
		order.shirtOrderCount(shirtCountInput);

		shirtsRemaining = order.shirtCount;

		do{
			cout << "From the " << shirtCountInput << " shirts, how many small shirts do you need?"<< endl;
			cin >> smallInput;
			if(smallInput > shirtsRemaining){
				cout << "You cannot order more small shirts than available. Please enter a valid number." << endl;
			}
		} while(smallInput > shirtsRemaining);
		order.smallCount(smallInput);
		shirtsRemaining -= order.small;
		
		// shirtsRemaining = shirtsRemainingFunction(order.small);

		do{
			cout << "From the " << shirtsRemaining << " shirts, how many medium shirts do you need?" << endl;
			cin >> mediumInput;
			if(mediumInput > shirtsRemaining){
				cout << "You cannot order more small shirts than available. Please enter a valid number." << endl;
			}
		} while(mediumInput > shirtsRemaining);
		order.mediumCount(mediumInput);
		shirtsRemaining -= order.medium;

		do{
			cout << "From the " << shirtsRemaining << " shirts, how many large shirts do you need?" << endl;
			cin >> largeInput;
			if(largeInput > shirtsRemaining){
				cout << "You cannot order more small shirts than available. Please enter a valid number." << endl;
			}
		} while(largeInput > shirtsRemaining);
		order.largeCount(largeInput);
		shirtsRemaining -= order.large;
		
		cout << shirtsRemaining << " remaining shirts will be for XL shirts" << endl;
		order.xlCount(shirtsRemaining);
		shirtsRemaining -= order.xl;

		// output from 
		// get info from order class
		// get info from pricing class
		// run order calculator
		
		totalCost = 2;
	} while(totalCost == 0.0); {

		// cout << "Total cost of the order is: $ " << totalCost << endl;
		cout << "testing print both sides: " << order.printBothSides << endl;
		cout << "testing color count: " << order.colorCount << endl;
		cout << "testing shirt count: " << order.shirtCount << endl;
		cout << "testing shirt sizes: " << order.small << endl;
		cout << "testing shirt sizes: " << order.medium << endl;
		cout << "testing shirt sizes: " << order.large << endl;
		cout << "testing shirt sizes: " << order.xl << endl;
		cout << "testing shirt size confirmation: " << order.shirtSizeSegmentationConfirmation << endl;


	};


	return 0;
};

