#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para determinar si se puede obtener un flujo de caja determinado
bool canAchieveCashFlow(const vector<int>& transactions, int N, int flow, vector<char>& result) {
    int totalPossible = pow(2, N);  // Número total de combinaciones de ingresos y gastos
    vector<bool> possible(N, false);  // Para almacenar si es posible saber que es ingreso/gasto
    bool valid = false;  // Indica si es posible obtener el flujo de caja

    // Probar todas las combinaciones posibles
    for (int mask = 0; mask < totalPossible; ++mask) {
        int sum = 0;
        vector<int> transactionSign(N, 0);  // Vector para almacenar signos de transacciones

        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += transactions[i];  // Consideramos la transacción como ingreso (+)
                transactionSign[i] = 1;
            } else {
                sum -= transactions[i];  // Consideramos la transacción como gasto (-)
                transactionSign[i] = -1;
            }
        }

        // Si el flujo de caja coincide
        if (sum == flow) {
            valid = true;  // Marcamos como válido

            // Actualizamos las posibilidades de cada transacción
            for (int i = 0; i < N; ++i) {
                if (result[i] == 'X') {
                    result[i] = transactionSign[i] == 1 ? '+' : '-';
                } else if ((result[i] == '+' && transactionSign[i] == -1) || 
                           (result[i] == '-' && transactionSign[i] == 1)) {
                    result[i] = '?';
                }
            }
        }
    }

    return valid;
}

int main() {
    while (true) {
        int N, F;
        cin >> N >> F;
        if (N == 0 && F == 0) break;

        vector<int> transactions(N);
        for (int i = 0; i < N; ++i) {
            cin >> transactions[i];
        }

        vector<char> result(N, 'X');  // Inicialmente marcamos todas como indefinidas ('X')

        // Si no se puede obtener el flujo de caja exacto, imprimimos '*'
        if (!canAchieveCashFlow(transactions, N, F, result)) {
            cout << "*" << endl;
        } else {
            for (char c : result) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
