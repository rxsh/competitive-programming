#include <iostream>
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

void twoSum(vector<int>& vec, int target){

    vector<int> resultados;
    vector<pair<int,int>> results;

    for(size_t i = 0; i < vec.size(); i++){
        for(size_t j = i+1; j < vec.size(); j++){
            if((vec[i] + vec[j]) == target){
                results.push_back({i,j});
            }
        }
    }

    for(auto x : results){
        cout << "[" << x.first << ", " << x.second << "]\n";
    }

}


int main(){

    vector<int> vec = {5,2,8,12,10,3,11};
    int x = 3;
    vector<int> vec2 = {1,2,2,3,4,4,5};
    /*
    sumElements(vec);
    findMenor(vec);
    promedio(vec);
    countEvenAndOdd(vec);
    invertVec(vec);
    searchElement(vec, x);
    deleteDuplicates(vec2);
    rotateVector(vec);
 */

    vector<int> vec3 = {2, 5, 8, 10, 7};
    vector<int> two = {2,7,11,15};
    int targ = 9;
    twoSum(two, targ);
    twoSum(vec3, targ);

    return 0;
}
