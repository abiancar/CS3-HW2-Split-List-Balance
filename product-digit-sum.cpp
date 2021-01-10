#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std; 


//performs exponentiation, returns result
unsigned long long pow(int base,int power){ //unsigned long long to allow for largest possible number
    long long totalResult = 1;

    for (int i = 0; i < power; i++){
        totalResult = totalResult * base;
    }
    return totalResult;
}

//adds all values in an integer vector, returns sum
int sum_vector(vector<int> result){
    int sum = 0;

    for (size_t i = 0; i < result.size() ; i++){
    sum+= result.at(i) ;
    }
    return sum;
}

//takes number values and converts it to int vector
vector<int> vectorize_digits(unsigned long long n){
    unsigned long long originalNum = n; // copy of n, so that the original number can be preserved
    int numDigits = 0;
    
    //hard coded for n==0, without this if statement, while loop never breaks
    if(n == 0){
        return {0};
    }
    //counts number of digits in n
    while (n == 0){
        n = n / 10;
        numDigits++;
    }
    vector<int> numList(numDigits);// creates list of size of the number of digits    

    // fill list with appropriate values from right to left
    for(int i = numList.size()-1; i >= 0; i--){
        numList.at(i) = originalNum % 10;
        originalNum = originalNum / 10;
    }
    return numList;
}

// used for debugging, not called in main()
string vector_to_string(vector<int> numList){
    string numString ("[");
    for (size_t i = 0; i < numList.size();i++){
        numString += to_string(numList.at(i)); 
        if(i != numList.size()-1){numString += ',';}
    }
    numString += "]";
    return numString;
}

// test function, not called in main()
int test(){
    cout << "TESTING: pow(a,b)" << endl;
    assert (pow(0,0)==1);       // edge case 0 ^ 0
    assert (pow(0,1) == 0);     // edge case 0 ^ 1
    assert (pow(25,0)== 1);     // case n ^ 0
    assert (pow (68, 1)==68);   // case n ^ 1
    assert (pow (3,9)==19683);  // regular use 

    cout << "TESTING: sum_vector(c)" << endl;
    vector<int> vec = {};           // edge case empty list {}
    assert (sum_vector(vec) == 0);
    vec.push_back(0);               // edge case single value {}
    assert (sum_vector(vec) == 0);
    vec.push_back(6);               // regular case, 2 number list
    assert (sum_vector(vec) == 6);
    vec = {0,1,2,3,4,5,6,7,8,9,10}; // regular case, 13 number list
    assert (sum_vector(vec) == 55);
    
    cout << "TESTING: vectorize_digits(d)" << endl;
    vector<int> test = {0};                     //testing 0
    assert (vectorize_digits(0) == test);
    test = {9};                                 //testing single digit
    assert (vectorize_digits(9) == test);
    test = {1,3,8,9,7,5,4,6,8,8,7};             //testing multi digit digit
    assert (vectorize_digits(13897546887) == test);
    
    cout << "TESTING: vector_to_string(e)" << endl;
    test = {};                                  //testing empty vector
    assert (vector_to_string(test)=="[]");
    test.push_back(7);                          // testing single number vector
    assert (vector_to_string(test)=="[7]");
    test = {1,2,3,4,5,6,7,8,9,1,0};             // testing regular use case, multiple numbers
    assert(vector_to_string(test)== "[1,2,3,4,5,6,7,8,9,1,0]");
    
    cout << "ALL TESTS COMPLETED!" << endl;
    return 0;
}

int main() { 
    int base;
    int power;
    
    //take user base and power user inputs, print them 
    cout << "What is the base? (Must be a positive integer!) : ";       
    cin >> base;
    cout << "What is the power? (Positive integer!) : ";
    cin >> power; cout << endl << "RESULTS: " << endl;

    //Basic check: If Integer is negative, print guidance and exit program
    if( (power < 0) || (base < 0) ){
        cout << "USER ERROR: MUST BE POSITIVE INT!" << endl << endl;
        return 1; 
    }
    
    //Compute base ^ power and find the sum of the result's digits
    long long result = pow(base,power);
    cout << "base: " << base << endl << "power: " << power << endl;
    cout << base <<"^" << power << "= " << result << endl;
    cout << "Sum of Digits: " << sum_vector(vectorize_digits(result)) << endl; 

    return 0; 

}
