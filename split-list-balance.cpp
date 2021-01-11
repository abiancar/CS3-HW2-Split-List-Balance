#include <iostream>
#include <climits>
#include <vector>
using namespace std;


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

//finds maximum number of a vector
int findMax(vector<int> vector){
    int max = vector.at(0);
    for (size_t  i = 0; i < vector.size(); i++){
        int curr = vector.at(i);
        if(curr > max){
            max = curr;
        }
    }
    return max;
}

//algorithm
int split_vec(vector<int> vec, int m){
    int maxMin = INT_MAX; // used to see if maximum at every split is smaller than curr maxima
    int size = vec.size();
    
    // if the size is greater than m, or if m is 0, there is a user error
    if(m == 0 || m > size){
        cout << endl<< "ERROR: CANNOT SPLIT WITH GIVEN M AND VECTOR" << endl;
        exit(1);
    }
    
    //if m is equal to the size, and the size is greater than 1
    // we have a list like this: {1,2,3} m = 3.
    // split into sublists for printing purposes, find max and return max
    if(m == size && size > 1){
        return findMax(vec);
    }
    
    // if we are left with a list like: {1,2,3,4} with m =1
    // this is as small as a sublist can get, add all digits and return sum
    else if (m == 1){
        return sum_vector(vec);
    }

    // m is greater than 2, we need to recursively call split_vector()
    // test all different ways m = 1 can be called using the first number of the vector
    // during each test, the rest of the list is considered substring 2
    // compare substring 1 and 2 to find maximum, add maximum to maxima for later use

    else{
        for (size_t i = 0; i < vec.size()-m+1; i++){   // iterates till size -m + 1, stopping to avoid creating an impossible sublist with m = 1 during each iteration
            unsigned j = i + 1;
            vector<int> subList1;
            vector<int> subList2;

            for(size_t k = 0; k < j; k++){
                subList1.push_back(vec.at(k));
            }
            for(size_t k = j; k < vec.size(); k++){
                subList2.push_back(vec.at(k));
            }

            int result1 = split_vec(subList1,1);
            int result2 = split_vec(subList2,m-1);
        
            int curr_max; 
            if (result1 > result2){
                curr_max = result1;   
            }
            else{            
                curr_max = result2;
            }
            if(curr_max < maxMin){
                maxMin = curr_max;
            }
        }
        return maxMin;
    }
    return 0;
}


int main(){
    int m = 3;     
    vector<int> vec = {1, 4, 4};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;    
    
    m = 2;
    vec = {7,2,5,10,8};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;

    m = 2;
    vec = {2,3,4,5,6};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;    
    
    m = 4;
    vec = {7,6,2,5,3,4};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;
    return 0;
}
