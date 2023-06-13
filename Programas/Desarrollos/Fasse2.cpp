#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++){
        swapped = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Ingrese la cantidad de numeros que desea ordenar: ";
    cin >> n;
    int arr[n], arr_b[n], arr_s[n], arr_q[n];
    cout << "Ingrese la lista de numeros: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr_b[i] = arr[i];
        arr_s[i] = arr[i];
        arr_q[i] = arr[i];
    }
    cout << endl << "Lista de numeros ingresada: ";
    printArray(arr, n);
    cout << endl;

    // Método de burbuja
    auto start_bubble = chrono::steady_clock::now();
    bubbleSort(arr_b, n);
    auto end_bubble = chrono::steady_clock::now();
    cout << "Lista ordenada por el metodo de Burbuja: ";
    printArray(arr_b, n);
    cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::microseconds>(end_bubble - start_bubble).count() << " microsegundos" << endl << endl;

    // Método de Clam Shell
    auto start_shell = chrono::steady_clock::now();
    shellSort(arr_s, n);
    auto end_shell = chrono::steady_clock::now();
    cout << "Lista ordenada por el metodo de Clam Shell: ";
    printArray(arr_s, n);
    cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::microseconds>(end_shell - start_shell).count() << " microsegundos" << endl << endl;
    auto start_quick = chrono::steady_clock::now();
    quickSort(arr_q, 0, n - 1);
    auto end_quick = chrono::steady_clock::now();
    cout << "Lista ordenada por el metodo Quick Sort: ";
    printArray(arr_q, n);
    cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::microseconds>(end_quick - start_quick).count() << " microsegundos" << endl << endl;
    system("pause");
    return 0;

}
