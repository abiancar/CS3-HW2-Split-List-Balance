#include <iostream>
#include <limits.h>
using namespace std; 



void pow(int base,int power){

    long long totalResult = 1; 
    for (int i = 0; i < power; i++){
        totalResult = totalResult * base;
    }
    cout << base <<" raised to the power of " << power << " = " << totalResult << endl; 
}







int main() {
    
    int base = -1;
    int power = -1;

    while (base < 0){
        cout << "What is the base? (Must be a positive integer!) : ";       
        cin >> base;
    }
    

    cout << "What is the power?: ";
    cin >> power; 

    pow(base, power);     
    return 0; 
}
