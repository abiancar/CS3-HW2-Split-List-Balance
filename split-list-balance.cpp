#include <iostream>
#include <vector>
using namespace std;

// adds digits in vector
int sum_vector(vector<int> result){
    int sum = 0;

    for (size_t i = 0; i < result.size() ; i++){
    sum+= result.at(i) ;
    }
    return sum;
}

//turns number into vector
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

//converts vector into string
string vector_to_string(vector<int> numList){
    string numString ("[");
    for (size_t i = 0; i < numList.size();i++){
        numString += to_string(numList.at(i)); //ascii 48 is where numbers begin
        if(i != numList.size()-1){numString += ',';}
    }
    numString += "]";
    return numString;
}

//algorithm
int split_vec(vector<int> vec, int m){
    vector<int> maxima;
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
        int max = 0;
        for (int i = 0; i < size; i++){
            vector<int> subVector;
            subVector.push_back(vec.at(i));
            cout << vector_to_string(subVector);
            if (vec.at(i) > max){

                max = vec.at(i);
            }
        }
        return max;
    }
    
    // if we are left with a list like: {1,2,3,4} with m =1
    // this is as small as a sublist can get, add all digits and return sum
    else if (m == 1){
        cout << vector_to_string(vec);
        return sum_vector(vec);
    }
    
    //if m ==2, we have a list like: {1,2,3,4}
     
    else if (m == 2){
        for (size_t i = 0; i < vec.size()-1; i++){
            
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
            int result2 = split_vec(subList2,1);
            


  //          cout << vector_to_string(subList1) << " ";
  //          cout << vector_to_string(subList2) << " ";

            if (result1 > result2){
                maxima.push_back(result1);
            }else{
                maxima.push_back(result2);
            }
            cout << endl;
        }
    }

    // if m is larger than 2, we need to recursively call
    // split_vector() on all possible sublists
    else{
        for (size_t i = 0; i < vec.size()-m+1; i++){
            unsigned j = i + 1;
            vector<int> subList1;
            vector<int> subList2;

            for(size_t k = 0; k < j; k++){
                subList1.push_back(vec.at(k));
            }
            for(size_t k = j; k < vec.size(); k++){
                subList2.push_back(vec.at(k));
            }

            cout << vector_to_string(subList1) << " ";
 //           cout << vector_to_string(subList2) << endl;



            int result1 = split_vec(subList1,1);
            int result2 = split_vec(subList2,m-1);
            

            if (result1 > result2){
                maxima.push_back(result1);
            }else{
                maxima.push_back(result2);
            }

        }
    }

    int min = maxima.at(0);
    for(size_t i = 0; i < maxima.size(); i++){
        int curr = maxima.at(i);
        if (curr < min){
            min = curr;
        }
    }
    //cout << "MAX MINIMUM: " << min << endl;     
    return 0;
}


int main(){

    int m = 3;
    vector<int> vec = {1,2,3,4,5,6};
    cout << endl << "ORIGINAL VECTOR: " << vector_to_string(vec) << endl;
    cout << endl << split_vec(vec, m) << endl;    
    return 0;
}
