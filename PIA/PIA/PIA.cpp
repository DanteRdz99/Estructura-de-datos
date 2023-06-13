#include <iostream>
#include <vector>

using namespace std;

// Estructura de nodo para la pila
struct Node {
    int data;
    Node* next;
};

// Clase para implementar una pila
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "La pila esta vacia." << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void print() {
        if (isEmpty()) {
            cout << "La pila esta vacia." << endl;
        }
        else {
            cout << "Elementos en la pila: ";
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Estructura de nodo para la cola
struct QueueNode {
    int data;
    QueueNode* next;
};

// Clase para implementar una cola
class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "La cola esta vacia." << endl;
        }
        else {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void print() {
        if (isEmpty()) {
            cout << "La cola esta vacia." << endl;
        }
        else {
            cout << "Elementos en la cola: ";
            QueueNode* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Clase para implementar una tabla hash con hashing abierto
class HashTable {
private:
    vector<int> table;
    int size;

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size, -1);
    }

    void insert(int value) {
        int index = hashFunction(value);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % size;
            if (index == originalIndex) {
                cout << "La tabla hash esta llena." << endl;
                return;
            }
        }

        table[index] = value;
    }

    int hashFunction(int value) {
        return value % size;
    }

    void print() {
        cout << "Elementos en la tabla hash: ";
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << table[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int opcion;
    Stack pila;
    Queue cola;
    int tamanoTabla;
    HashTable tablaHash(10);

    do {
        cout << "========== Menu ==========" << endl;
        cout << "1. Pilas" << endl;
        cout << "2. Colas" << endl;
        cout << "3. Tablas Hash" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int valorPila;
            int opcionPila;

            do {
                cout << "========== Menu de Pilas ==========" << endl;
                cout << "1. Insertar elemento" << endl;
                cout << "2. Eliminar elemento" << endl;
                cout << "3. Imprimir pila" << endl;
                cout << "0. Volver al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionPila;

                switch (opcionPila) {
                case 1: {
                    cout << "Ingrese el valor a insertar en la pila: ";
                    cin >> valorPila;
                    pila.push(valorPila);
                    break;
                }
                case 2: {
                    pila.pop();
                    break;
                }
                case 3: {
                    pila.print();
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
                    break;
                }
                }
            } while (opcionPila != 0);

            break;
        }
        case 2: {
            int valorCola;
            int opcionCola;

            do {
                cout << "========== Menu de Colas ==========" << endl;
                cout << "1. Insertar elemento" << endl;
                cout << "2. Eliminar elemento" << endl;
                cout << "3. Imprimir cola" << endl;
                cout << "0. Volver al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionCola;

                switch (opcionCola) {
                case 1: {
                    cout << "Ingrese el valor a insertar en la cola: ";
                    cin >> valorCola;
                    cola.enqueue(valorCola);
                    break;
                }
                case 2: {
                    cola.dequeue();
                    break;
                }
                case 3: {
                    cola.print();
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
                    break;
                }
                }
            } while (opcionCola != 0);

            break;
        }
        case 3: {
            int valorHash;
            int opcionHash;

            do {
                cout << "========== Menu de Tablas Hash ==========" << endl;
                cout << "1. Insertar elemento" << endl;
                cout << "2. Imprimir tabla hash" << endl;
                cout << "0. Volver al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionHash;

                switch (opcionHash) {
                case 1: {
                    cout << "Ingrese el valor a insertar en la tabla hash: ";
                    cin >> valorHash;
                    tablaHash.insert(valorHash);
                    break;
                }
                case 2: {
                    tablaHash.print();
                    break;
                }
                case 0: {
                    break;
                }
                default: {
                    cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
                    break;
                }
                }
            } while (opcionHash != 0);

            break;
        }
        case 0: {
            cout << "Saliendo del programa." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
            break;
        }
        }
    } while (opcion != 0);
    system("pause");
    return 0;
}
