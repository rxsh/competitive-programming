#include <iostream>
#include <vector>

using namespace std;

void sumMatrix(int x[3][3], int y[3][3], int result[3][3]){

    for(size_t i = 0; i<3; i++){
        for(size_t j = 0; j<3; j++){
            result [i][j] = x[i][j] + y[i][j];
        }
    }

    for(size_t i=0; i<3;i++){
        for(size_t j=0; j<3; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}

void multMatrixHadamard(int x[3][3], int y[3][3], int result[3][3]){

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            result[i][j] = x[i][j] * y[i][j];
        }
    }

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void multMatrix(int x[3][2], int y[2][3], int result[3][3]){

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            result[i][j] = 0;
            for(size_t k=0; k<2; k++){
                result[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}


void transpuesta(int x[2][3], int transpuesta[3][2]){


    for(size_t i=0; i<2;i++){
        for(size_t j=0; j<3; j++){
            transpuesta[j][i] = x[i][j];
        }
    }

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<2; j++){
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }
}

void diagonalMatrix(int x[3][3]){

    for(size_t i=0; i<3;i++){
        for(size_t j=0; j<3; j++){
            if(i == j){
                cout << x[i][j] << " ";
            } else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void sumDiagonal(int x[3][3]){

    int sum = 0;

    for(size_t i=0 ;i<3; i++){
        for(size_t j=0; j<3; j++){
            if(i == j){
                sum += x[i][j];
            }
        }
    }

    cout << "Suma diagonal: " << sum << endl;
}

void searchNumMatrix(int x[3][3], int element){

    bool encontrado = false;

    for(size_t i=0; i<3; i++){
        for(size_t j=0; j<3; j++){
            if(x[i][j] == element){
                encontrado = true;
                cout << "Number found\n";
            }
        }
    }
}

int main(){

    int x[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int y[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int result[3][3];

    int x1[3][2] = {{1,5},{8,4},{10,15}};
    int y1[2][3] = {{7,4,1},{10,5,16}};

    int result2[3][2];

    sumMatrix(x,y, result);
    multMatrixHadamard(x, y, result);
    multMatrix(x1,y1,result);

    transpuesta(y1, result2);
    diagonalMatrix(x);
    sumDiagonal(x);
    searchNumMatrix(x,9);

    return 0;
}
