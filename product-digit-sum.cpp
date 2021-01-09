#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std; 


//unsigned long long to maximize size of output (more bytes to use)
unsigned long long pow(int base,int power){
    long long totalResult = 1;

    for (int i = 0; i < power; i++){
        totalResult = totalResult * base;
    }
    return totalResult;
}

int sum_vector(vector<int> result){
    int sum = 0;

    for (size_t i = 0; i < result.size() ; i++){
    sum+= result.at(i) ;
    }
    return sum;
}

vector<int> vectorize_digits(unsigned long long n){
    unsigned long long originalNum = n; // copy of num
    int numDigits = 0;
    while (n > 0){
        n = n / 10;
        numDigits++;
    }

    vector<int> numList(numDigits);    

    for(int i = numList.size()-1; i >= 0; i--){
        numList.at(i) = originalNum % 10;
        originalNum = originalNum / 10;
    }
    return numList;
}


string vector_to_string(vector<int> numList){
    string numString ("[");
    for (size_t i = 0; i < numList.size();i++){
        numString += to_string(numList.at(i)); //ascii 48 is where numbers begin
        if(i != numList.size()-1){numString += ',';}
    }
    numString += "]";
    return numString;
}

int test(){
    return 0;
}











int main() { 

    //QUICK TEST: VECTORIZE_DIGITS()
    long long n = 1234567;
    vector<int> list = {1,2,3,4,5,6,7};
    cout << sum_vector (list);
    cout << sum_vector(vectorize_digits(n)) << endl;
    cout << vector_to_string(vectorize_digits(n)) << endl;

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
        main();  //FIX ME: BAD PRACTICE TO RECURSIVELY CALL MAIN(), look at professor's feedback
    }
    
    //Compute base ^ power and find the sum of the result's digits
    long long result = pow(base,power);
    cout << "base: " << base << endl << "power: " << power << endl;
    cout << base <<"^" << power << "= " << result << endl; 
   // cout << "Sum of Digits: " <<sum_vector(result) << endl; 

    return 0; 







}
