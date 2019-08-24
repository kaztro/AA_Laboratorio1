#include <iostream>

using namespace std;

void selection();

/*Suma de la primera cantidad n de datos del arreglo*/
int sumArrDataPos(int n, int a[]) {
    if (n == 0) {
        return a[n];
    } else {
        n--;
        return a[n + 1] + sumArrDataPos(n, a);
    }
}

int sumArrDataTail(int n, int a[], int aux, int result) {
    if(aux < n) {
        result += a[aux];
        sumArrDataTail(n, a, aux + 1, result);
    } else return result;
}

int auxSumTailArr(int limitSum) {
    int genericA[10] = {1, 20, 565, 9, 163, 15, 6, 8, 54, 5};
    sumArrDataTail(limitSum, genericA, 0, 0);
}

/*Fibonacci Posposicion*/
int fibonacciPos(int n) {
    return (n == 0) ? 0 : n - 1 + fibonacciPos(n - 1);
}

/*Fibonacci Cola*/
int fibonacciTail(int n, int trivialA, int trivialB) {
    if(n == 0) return trivialA;
    if(n == 1) return trivialB;
    return fibonacciTail(n - 1, trivialB, trivialA + trivialB);
}

//Funcion auxiliar
int auxFibFunc(int n) {
    int tA = 0, tB = 1;
    return fibonacciTail(n, tA, tB);
}

/*Suma de matrices*/
void matrixSum(int A[][3], int B[][3], int C[][3], int fila, int column) {
    if(fila == 2 && column == 2) {
        C[fila][column] = A[fila][column] + B[fila][column];
        cout << C[fila][column] << " " << endl;
        selection();
    } else {
        if(column > 2){
            fila++;
            column = 0;
            //cout << endl;
        } else {
            C[fila][column] = A[fila][column] + B[fila][column];

            cout << C[fila][column] << " " << endl;

            column++;
        }
        matrixSum(A, B, C, fila, column);
    }
}

//Para llenar matrices
int llenadoMatrix(int matrix[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Ingrese un entero: " << endl;
            cin >> matrix[i][j];
        }
    }
    return **matrix;
}

/*Exponente recursivo*/
int equisALaN(int base, int exponente) {
    return (exponente == 1) ? base : base * equisALaN(base, exponente - 1);
}

/*Busqueda de el menor numero en un arreglo*/
int busMenNumArray(int array[], int menor, int aux){
    if(aux < 0) return menor;
    else{
        if(array[aux] < menor) menor = array[aux];
        busMenNumArray(array, menor, aux - 1);
    }
}

//Funcion para llenar el arreglo
int llenadoArray(int *array, int tamA, int aux) {
    if (aux < tamA) {
        cout << "Ingresa el " << aux + 1 << " valor:" << endl;
        cin >> array[aux];
        llenadoArray(array, tamA, aux + 1);
    } else busMenNumArray(array, tamA, array[0]);
    return 0;
}

/*Funcionalidad del Menú*/
void mainMenu() {
    cout << "<------------------------------------------------------>" << endl;
    cout << "Ingresa que quieres hacer: " << endl;
    cout << "1-Fibonacci (Posposicion)" << endl;
    cout << "2-Fibonacci (Cola)" << endl;
    cout << "3-Suma de un arreglo (Posposicion)" << endl;
    cout << "4-Suma de un arreglo (Cola)" << endl;
    cout << "5-Suma de Matrices" << endl;
    cout << "6-Exponente recursivo" << endl;
    cout << "7-Busqueda menor valor en arreglo" << endl;
    cout << "8-Salir" << endl;
    cout << "<------------------------------------------------------>" << endl;
}

void selection() {
    int s = 0;
    mainMenu();
    cin >> s;
    switch(s) {
        case 1: {
            int nP;
            cout << "Ingrese el valor de 'n'" << endl;
            cin >> nP;
            cout << "Fibonacci(" << nP << ") = " << fibonacciPos(nP) << endl;
            selection();
            break;
        }

        case 2: {
            int nT;
            cout << "Ingrese el valor de 'n'" << endl;
            cin >> nT;
            cout << "Fibonacci(" << nT << ") = " << auxFibFunc(nT) << endl;
            selection();
            break;
        }
        case 3: {
            int cantidad1;
            int genericA[10] = {1, 20, 565, 9, 163, 15, 6, 8, 54, 5};
            cout << "Ingrese la cantidad que quiere sumar, "
                    "tome en cuenta que el arreglo es de 10 items..." << endl;
            cin >> cantidad1;
            cout << "El resultado es: " << sumArrDataPos(cantidad1, genericA) << endl;
            selection();
            break;
        }
        case 4: {
            int cantidad;
            cout << "Ingrese la cantidad que quiere sumar, "
                    "tome en cuenta que el arreglo es de 10 items..." << endl;
            cin >> cantidad;
            cout << "El resultado es: " << auxSumTailArr(cantidad) << endl;
            selection();

            break;
        }
        case 5: {
            int A[3][3], B[3][3], C[3][3] = {{0, 0, 0},
                                             {0, 0, 0},
                                             {0, 0, 0}};
            llenadoMatrix(A);
            llenadoMatrix(B);
            matrixSum(A, B, C, 0, 0);
            break;
        }
        case 6: {
            int base, exponente;
            cout << "Ingresa el numero que quieres elevar: " << endl;
            cin >> base;
            cout << "Ingresa el exponente: " << endl;
            cin >> exponente;
            cout << "Resultado: " << equisALaN(base, exponente);
            selection();
            break;
    }
        case 7: {
            int t;
            cout << "Ingresa el tamaño del arreglo: " << endl;
            cin >> t;
            int a[t];
            cout << "El valor 'menor' es: " << llenadoArray(a, t, 0) << endl;
            selection();
            break;
        }
        case 8:{
                exit(-1);
        }
        default:{
                selection();
        }
    }
}

/*Fin de la funcionalidad del menú*/

int main() {
    selection();
    return 0;
}