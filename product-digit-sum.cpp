#include <iostream>
#include <limits.h>
#include <string>
using namespace std; 

//OTHER CHANGES: Make variable names more relevant : "result" and "sum" should be made into two words if possible

long long pow(int base,int power){
    long long totalResult = 1;

    for (int i = 0; i < power; i++){
        totalResult = totalResult * base;
    }
    cout << base <<"^ " << power << "= " << totalResult << endl; 
    return totalResult;
}

void sum(long long result){
    string rString = to_string(result);
    int sum = 0;
    for (unsigned int i = 0; i < rString.size(); i++ ){
        int curr = int(rString.at(i)) -48; // it felt awkward converting from long long to string and then turning a number character to an int... 
        sum += curr;                       // let's see if it can be simplified
    }
    cout << "Sum of Digits: " << sum;
}

int main() {    
    int base = -1;  //FIX ME: Let's solve this problem using signed integers when I have more time [just to make things a bit more sophisticated]
    int power = -1; // Get rid of while loop, try and catch if there are any errors, repeat prompt


    //ensure userInputs area positive integers
    while (base < 0){
        cout << "What is the base? (Must be a positive integer!) : ";       
        cin >> base;
    }

    while (power < 0){
        cout << "What is the power? (Must be a positive integer!) : ";       
        cin >> power;
    }
    cout << "base: " << base << endl << "power: " << power << endl;
    sum(pow(base, power));   //FIX ME: Code runs fine, but let's improve readability by separating sum() and pow()
    return 0; 
}
