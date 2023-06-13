#include <iostream>
#include <chrono>
#include <locale.h>

using namespace std;

int captureList(int arr[], int max) {
    int n;
    setlocale(LC_CTYPE,"Spanish");
    do {
        cout << "Ingresa el tamano de la lista (max " << max << "): ";
        cin >> n;
    } while (n < 1 || n > max);

    cout << "Ingresa " << n << " numeros separados por espacios: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return n;
}

int sequentialSearch(int arr[], int n, int x, int &comparisons) {
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x, int &comparisons) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        comparisons++;
        if (arr[mid] == x) {
            return mid;
        }
        comparisons++;
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x, comparisons);
        }
        return binarySearch(arr, mid + 1, r, x, comparisons);
    }
    return -1;
}

void search(int arr[], int n, int method) {
    int x;
    cout << "Ingresa el numero a buscar: ";
    cin >> x;

    int comparisons = 0;
    int position;
    auto start = chrono::high_resolution_clock::now();
    if (method == 2) {
        position = sequentialSearch(arr, n, x, comparisons);
    }
    else {
        position = binarySearch(arr, 0, n - 1, x, comparisons);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Cantidad de elementos sobre los que se busca: " << n << endl;
    cout << "Tiempo total de la busqueda: " << duration.count() << " microsegundos" << endl;
    if (position == -1) {
            cout<< "El elemento no existe en la lista." << endl;
    }
    else {
        cout << "Posicion en la cual se encuentra el elemento buscado: " << position << endl;
    }
    cout << "Cantidad de comparaciones realizadas: " << comparisons << endl;
}

int main() {
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int n = 0;

    int option;
    do {
        cout << "1. Capturar lista de numeros." << endl;
        cout << "2. Realizar una busqueda usando el metodo de busqueda secuencial." << endl;
        cout << "3. Realizar una busqueda usando el metodo de busqueda binaria." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingresa una opcion: ";
        cin >> option;

        switch (option) {
            case 1:
                n = captureList(arr, MAX_SIZE);
                break;
            case 2:
                if (n > 0) {
                    search(arr, n, 1);
                }
                else {
                    cout << "La lista esta vacia. Captura una lista primero." << endl;
                }
                break;
            case 3:
                if (n > 0) {
                    search(arr, n, 2);
                }
                else {
                    cout << "La lista esta vacia. Captura una lista primero." << endl;
                }
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }

        cout << endl;

    } while (option != 4);
    system("pause");
    return 0;
}

