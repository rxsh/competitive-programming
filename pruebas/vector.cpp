#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <stack>
#include <unordered_set>


using namespace std;

void sumElements(vector<int> vec){

    int sum = 0;
    for(int i=0; i<vec.size(); i++){
        sum += vec[i];
    }

    cout << "Total sum: " << sum << endl;
}

void findMenor(vector<int> vec){

    int size = vec.size();
    int position = 0;
    int menor = vec[0];

    for(int i=1; i<vec.size(); i++){
        if(menor > vec[i]){
            menor = vec[i];
            position = i;
        }
    }

    cout << "Menor: " << menor << endl;
    cout << "Posicion: " << position << endl;

}

void promedio(vector<int> vec){

    double promedio = 0;
    double sum = 0;

    for(int i=0;i<vec.size();i++){
        sum += vec[i];
    }

    promedio = sum / vec.size();

    cout << "Promedio: " << promedio << endl;

}

void countEvenAndOdd(vector<int> vec){

    int odd = 0;
    int even = 0;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }


    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;

}

void invertVec(vector<int>& vec){

    vector<int> newVector;
    int size = vec.size() -1;

    for(int i=size; i>=0; i--){
        newVector.push_back(vec[i]);
    }
    cout << endl;

}

void searchElement(vector<int> vec, int x){


    for(int i=0; i<vec.size(); i++){
        if(vec[i] == x){
            cout << "Found in position: " << i << endl;
        }
        else{
            cout << "Not found" << endl;
        }
    }

}

void deleteDuplicates(vector<int> vec){

    vector<int> newVector;
    bool leido;

    for(int i=0; i<vec.size(); i++){
        leido = false;
        for(int j=0; j<newVector.size(); j++){
            if(vec[i] == newVector[j]){
                leido = true;
                break;
            }
        }
        if(!leido){
            newVector.push_back(vec[i]);
        }
    }

    vec = newVector;
    for(auto x : vec){
        cout << x << " ";
    }
    cout << endl;
}

void rotateVector(vector<int>& vec){

    int temp = 0;

    for(int i=0; i<vec.size(); i++){
        if(vec[0] && vec[vec.size()-1] && i==0){
            temp = vec[0];
            vec[0] = vec[vec.size()-1];
            vec[vec.size()-1] = temp;
        }
    }

    for(auto x : vec){
        cout << x << " ";
    }
    cout << endl;


}

void secondHighestNumber(vector<int>& vec){

    int mayor = vec[0];
    int secondHighest = vec[0];

    for(size_t i = 1; i< vec.size(); i++){
        if(vec[i] > mayor){
            secondHighest = mayor;
            mayor = vec[i];
        } else if(vec[i] > secondHighest && vec[i] != mayor){

            secondHighest = vec[i];
        }
    }

    cout << "Highest number: " << mayor << endl;
    cout << "Highest 2 number: " << secondHighest << endl;

}

void thirdHighestNumber(vector<int>& vec){

    int mayor = numeric_limits<int>::min();
    int second = numeric_limits<int>::min();
    int third = numeric_limits<int>::min();

    for(size_t i=0; i<vec.size(); i++){
        if(vec[i] > mayor){
            second = mayor;
            mayor = vec[i];
        } else if(vec[i] > second && vec[i] != mayor){
            third = second;
            second = vec[i];
        } else if(vec[i] > third && vec[i] != second && vec[i] != mayor ){
            third = vec[i];
        }
    }

    cout << "Highest number: " << mayor << endl;
    cout << "Highest 2 number: " << second << endl;
    cout << "Highest 3 number: " << third << endl;
}


int main(){

    vector<int> vec = {5,2,8,12,10,3,11};
    int x = 3;
    vector<int> vec2 = {1,2,2,3,4,4,5};
    vector<int> vec3 = {10,5,8,20,15};

    sumElements(vec);
    findMenor(vec);
    promedio(vec);
    countEvenAndOdd(vec);
    invertVec(vec);
    searchElement(vec, x);
    deleteDuplicates(vec2);
    rotateVector(vec);
    secondHighestNumber(vec3);
    thirdHighestNumber(vec3);


    return 0;
}
