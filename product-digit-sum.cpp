#include <iostream>
#include <string>
using namespace std; 


//unsigned long long to maximize size of output (more bytes to use)
unsigned long long pow(int base,int power){
    long long totalResult = 1;

    for (int i = 0; i < power; i++){
        totalResult = totalResult * base;
    }
    return totalResult;
}

int sum(long long result){
    string rString = to_string(result);
    int sum = 0;

    //convert eachs character number into temporary integers, adds each of them together
    for (unsigned int i = 0; i < rString.size(); i++ ){
        int curr = int(rString.at(i)) -48; // substract by 48 because ascii valus begin at 48: http://www.asciitable.com/
        sum += curr;                       
    }
    return sum;
}

int main() { 
    int base;
    int power;
    
    //take user base and power user inputs, print them 
    cout << "What is the base? (Must be a positive integer!) : ";       
    cin >> base;
    cout << "What is the power? (Positive integer!) : ";
    cin >> power; cout << endl << "RESULTS: " << endl;

    //Basic check: If Integer is negative, print guidance and restart the program
    if( (power < 0) || (base < 0) ){
        cout << "USER ERROR: MUST BE POSITIVE INT!" << endl << endl;
        main();
    }
    
    //Compute base ^ power and find the sum of the result's digits
    long long result = pow(base,power);
    cout << "base: " << base << endl << "power: " << power << endl;
    cout << base <<"^" << power << "= " << result << endl; 
    cout << "Sum of Digits: " <<sum(result) << endl; 

    return 0; 
}
