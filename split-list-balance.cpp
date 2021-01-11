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

/* 

GENERAL ALGORITHM:
0) At each given level, create a variable that stores the min max
1) Assume function (at base level) returns the minimum maximum given a vector
2) Split given string into two valid sublists
3) The left most substring will be called with m = 1
4) The right substring will be called with m-1 as a parameter
5) Store the results of each, compare them
6) Find the maximum at each given split
7) If it is the smallest maximum, update the min max to this value
8) At the end of this split, return min maximum

*/

int split_vec(vector<int> vec, int m){
    int maxMin = INT_MAX; // used to store the smallest maximum
    int size = vec.size();
    
    // if the size is greater than m, or if m is 0, there is a user error
    if(m == 0 || m > size){
        cout << endl<< "ERROR: CANNOT SPLIT WITH GIVEN M AND VECTOR" << endl;
        exit(1);
    }
    
    // if we have a list like this: {1,2,3} m = 3.
    // find and return maximum
    if(m == size && size > 1){
        return findMax(vec);
    }
    
    // if we are left with a list like: {1,2,3,4} with m =1
    // this is as small we can split a given list, add all digits and return sum
    else if (m == 1){
        return sum_vector(vec);
    }

    // if m >= 2, we need to use recurive calls to find the minMax
    else{
        for (size_t i = 0; i < vec.size()-m+1; i++){  // iterates till size -m + 1 to avoid creating an impossible split
            unsigned j = i + 1;
            vector<int> subList1;
            vector<int> subList2;

            //creates two sublists given the current split
            for(size_t k = 0; k < j; k++){
                subList1.push_back(vec.at(k));
            }
            for(size_t k = j; k < vec.size(); k++){
                subList2.push_back(vec.at(k));
            }

            // leftmost sublist is created as single value vector, with m =1
            // rightmost sublist contains remainder of original vector
            int result1 = split_vec(subList1,1);
            int result2 = split_vec(subList2,m-1);

            //every time a vector is called, find the maximum between the left and right
            //vector at the given split
            int curr_max; 
            if (result1 > result2){
                curr_max = result1;   
            }
            else{            
                curr_max = result2;
            }
            // if the maximum at this split is smaller than maxMin, update maxMin to this value
            if(curr_max < maxMin){
                maxMin = curr_max;
            }
        }
        // at this point we have tested all maxima in the given split
        // return the smallest for output or further recursive calls
        return maxMin;
    }
    return 2;
}


int main(){
    
    //test: m = vector size 4
    int m = 3;     
    vector<int> vec = {1, 4, 4};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;    
    
    //test: m = 2 with non consecutive numbers, answer should be 18
    m = 2;
    vec = {7,2,5,10,8};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;

    //test: m = 2 with consecutive numbers, answer should be 11
    m = 2;
    vec = {2,3,4,5,6};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;    
    
    //test: m = 4 with moderately sized list, answer should be 7
    m = 4;
    vec = {7,6,2,5,3,4};
    cout << "INPUT: " << vector_to_string(vec) << "  m: " << m << endl;
    cout << "ans: " << split_vec(vec, m) << endl << endl;
    return 0;
}
