#include <iostream>
#include <limits>
#include <iomanip> // for setprecision

using namespace std;

// Create three classes
// 1. Order class - this class takes the input from customer questions and sends it to order calculator class
// 2. Pricing class - this class holds data on pricing structure.
// 3. Order calculator class - this class takes the input information from order class and the pricing details from pricing class and calculates the total.

class ShirtOrder {
public: 
    bool printBothSides;
    int colorCount;
    int shirtCount;
    int youth, small, medium, large, xl, xlPlus;
    // bool shirtSizeSegmentationConfirmation;

    void printOnBothSides(string n){
        printBothSides = (n == "yes");
    }
    void shirtColorCount(int n){
        colorCount = n;
    }
    void shirtOrderCount(int n){
        shirtCount = n;
    }
    void youthCount(int n){
        youth = n;
    }
    void smallCount(int n){
        small = n;
    }
    void mediumCount(int n){
        medium = n;
    }
    void largeCount(int n){
        large = n;
    }
    void xlCount(int n){
        xl = n;
    }
    void xlPlusCount(int n){
        xlPlus = n;
    }
};

class Pricing {
public:
    double column1Prices[5][3] = {
        {19.69, 19.99, 21.64},
        {20.69, 21.99, 22.64},
        {21.69, 22.99, 23.64},
        {22.69, 23.99, 24.64},
        {23.69, 24.99, 25.64}
    };
    double column2Prices[5][3] = {
        {9.69, 9.99, 11.64},
        {11.69, 11.99, 12.64},
        {12.69, 12.99, 13.64},
        {13.69, 13.99, 14.64},
        {14.69, 14.99, 15.64}
    };
    double column3Prices[5][3] = {
        {7.70, 8.00, 9.65},
        {9.70, 10.00, 11.65},
        {10.70, 11.00, 12.65},
        {11.70, 12.00, 13.65},
        {12.70, 13.00, 14.65}
    };
    double column4Prices[5][3] = {
        {6.70, 7.00, 8.65},
        {8.70, 9.00, 10.65},
        {9.70, 10.00, 11.65},
        {10.70, 11.00, 12.65},
        {11.70, 12.00, 13.65}
    };

    // this function takes input from order class and halps to calculate the price of the shirt order per shirt.
    double getPricePerTshirt(int numTshirts, int colorCount, int sizeIndex) const {
        if ((numTshirts >= 12) && (numTshirts <= 24)){
            return column1Prices[colorCount - 1][sizeIndex];
        }
        else if ((numTshirts >= 25) && (numTshirts <= 49)){
            return column2Prices[colorCount - 1][sizeIndex];
        }
        else if ((numTshirts >= 50) && (numTshirts <= 199)){
            return column3Prices[colorCount - 1][sizeIndex];
        }
        else if ((numTshirts >= 200) && (numTshirts <= 299)){
            return column4Prices[colorCount - 1][sizeIndex];
        }
        else{
            return -1; // call for a quote.
        }
    }
};

class OrderCalculator {
public:
    double calculateTotalCost(const ShirtOrder& order, const Pricing& pricing) {
        int totalShirts = order.youth + order.small + order.medium + order.large + order.xl + order.xlPlus;
        
        if (totalShirts != order.shirtCount) {
            cout << "Error: Sizes do not add up to the total shirt count." << endl;
            return 0.0;
        }

        if (totalShirts >= 300){
            cout << "Please call for your order." << endl;
        }

        double totalCost = 0.0;
        totalCost += order.youth * pricing.getPricePerTshirt(order.shirtCount, order.colorCount, 0); // Youth prices
        totalCost += (order.small + order.medium + order.large + order.xl) * pricing.getPricePerTshirt(order.shirtCount, order.colorCount, 1); // S, M, L, XL prices
        totalCost += order.xlPlus * pricing.getPricePerTshirt(order.shirtCount, order.colorCount, 2); // XL Plus prices

        double additionalCharge = order.printBothSides ? 3.0 : 0.0;
        totalCost += additionalCharge * order.shirtCount;

        return totalCost;
    }
};

bool isValid(string input, int &output) {
    try {
        output = stoi(input);  // Attempt to convert string input to integer.
        return true;           // Return true if conversion works.
    } catch (exception &e) {
        return false;          // Return false if an exception is caught or conversion fails.
    }
}

int main() {
    double totalCost = 0.0;
    ShirtOrder order;
    Pricing pricing;
    OrderCalculator calculator;

    string printBothSidesInput;
    string colorCountInputStr;
    string shirtCountInputStr;
    string youthInputStr, smallInputStr, mediumInputStr, largeInputStr, xlInputStr, xlPlusInputStr;
    int colorCountInput;
    int shirtCountInput;
    int youthInput, smallInput, mediumInput, largeInput, xlInput;
    int shirtsRemaining;

    do {
        cout << "Do you want to print on both sides? Type yes or no." << endl;
        cin >> printBothSidesInput;
        cout << endl;
        if (printBothSidesInput != "yes" && printBothSidesInput != "no") {
            cout << "Invalid input. Please type yes or no." << endl;
        }
    } while (printBothSidesInput != "yes" && printBothSidesInput != "no");
    order.printOnBothSides(printBothSidesInput);

    do {
        cout << "How many colors are in the print? (Type an integer from 1-5.)" << endl;
        cin >> colorCountInputStr;
        cout << endl;

        while (!isValid(colorCountInputStr, colorCountInput) || colorCountInput < 1 || colorCountInput > 5) {
            cout << "Invalid input. Please type an integer from 1-5" << endl;
            cin >> colorCountInputStr;
        }
    } while (colorCountInput < 1 || colorCountInput > 5);
    order.shirtColorCount(colorCountInput);

    do {
        cout << "How many t-shirts do you need? Type a number from 12 or over. Orders over 300 require a call." << endl;
        cin >> shirtCountInputStr;
        cout << endl;

        while (!isValid(shirtCountInputStr, shirtCountInput) || shirtCountInput < 12) {
            cout << "Please enter a number 12 or over." << endl;
            cin >> shirtCountInputStr;
        }
    } while (shirtCountInput < 12);
    order.shirtOrderCount(shirtCountInput);

    shirtsRemaining = order.shirtCount;

    do {
        cout << "From the " << shirtCountInput << " shirts, how many youth shirts do you need?" << endl;
        cin >> youthInputStr;
        cout << endl;

        while (!isValid(youthInputStr, youthInput) || youthInput > shirtsRemaining) {
            cout << "Please enter a valid number. " << shirtsRemaining << " remaining." << endl;
            cin >> youthInputStr;
        }
    } while (youthInput > shirtsRemaining);
    order.youthCount(youthInput);
    shirtsRemaining -= order.youth;

    do {
        cout << "From the " << shirtsRemaining << " shirts, how many small shirts do you need?" << endl;
        cin >> smallInputStr;
        cout << endl;

        while (!isValid(smallInputStr, smallInput) || smallInput > shirtsRemaining) {
            cout << "Please enter a valid number. " << shirtsRemaining << " remaining." << endl;
            cin >> smallInputStr;
        }
    } while (smallInput > shirtsRemaining);
    order.smallCount(smallInput);
    shirtsRemaining -= order.small;

    do {
        cout << "From the " << shirtsRemaining << " shirts, how many medium shirts do you need?" << endl;
        cin >> mediumInputStr;
        cout << endl;

        while (!isValid(mediumInputStr, mediumInput) || mediumInput > shirtsRemaining) {
            cout << "Please enter a valid number. " << shirtsRemaining << " remaining." << endl;
            cin >> mediumInputStr;
        }
    } while (mediumInput > shirtsRemaining);
    order.mediumCount(mediumInput);
    shirtsRemaining -= order.medium;

    do {
        cout << "From the " << shirtsRemaining << " shirts, how many large shirts do you need?" << endl;
        cin >> largeInputStr;
        cout << endl;

        while (!isValid(largeInputStr, largeInput) || largeInput > shirtsRemaining) {
            cout << "Please enter a valid number. " << shirtsRemaining << " remaining." << endl;
            cin >> largeInputStr;
        }
    } while (largeInput > shirtsRemaining);
    order.largeCount(largeInput);
    shirtsRemaining -= order.large;

    do {
        cout << "From the " << shirtsRemaining << " shirts, how many XL shirts do you need?" << endl;
        cin >> xlInputStr;
        cout << endl;

        while (!isValid(xlInputStr, xlInput) || xlInput > shirtsRemaining) {
            cout << "Please enter a valid number. " << shirtsRemaining << " remaining." << endl;
            cin >> xlInputStr;
        }
    } while (xlInput > shirtsRemaining);
    order.xlCount(xlInput);
    shirtsRemaining -= order.xl;

    cout << shirtsRemaining << " remaining shirts will be for XL Plus shirts" << endl << endl;
    order.xlPlusCount(shirtsRemaining);

    totalCost = calculator.calculateTotalCost(order, pricing);
    cout << "Total cost of the order is: $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}
