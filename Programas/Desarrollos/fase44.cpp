#include <iostream>
#include <vector>

using namespace std;

// Función hash
int hash_function(int key, int size) {
    return key % size;
}

// Clase para el elemento a insertar
class HashNode {
public:
    int key;
    int value;
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

// Clase para la tabla hash
class HashMap {
private:
    vector<HashNode*> table;
    int size;
public:
    HashMap(int size) {
        this->size = size;
        table.resize(size, nullptr);
    }
    ~HashMap() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
    }
    // Función para insertar un elemento
    void insert(int key, int value) {
        int hash_key = hash_function(key, size);
        HashNode* node = new HashNode(key, value);
        // Hashing cerrado
        while (table[hash_key] != nullptr && table[hash_key]->key != key) {
            hash_key++;
            hash_key %= size;
        }
        if (table[hash_key] != nullptr) {
            delete table[hash_key];
        }
        table[hash_key] = node;
    }
    // Función para buscar un elemento
    int find(int key) {
        int hash_key = hash_function(key, size);
        // Hashing abierto
        while (table[hash_key] != nullptr && table[hash_key]->key != key) {
            hash_key++;
            hash_key %= size;
        }
        if (table[hash_key] == nullptr) {
            return -1;
        }
        return table[hash_key]->value;
    }
    // Función para eliminar un elemento
    void remove(int key) {
        int hash_key = hash_function(key, size);
        // Hashing abierto
        while (table[hash_key] != nullptr && table[hash_key]->key != key) {
            hash_key++;
            hash_key %= size;
        }
        if (table[hash_key] != nullptr) {
            delete table[hash_key];
            table[hash_key] = nullptr;
        }
    }
    // Función para imprimir la tabla hash
    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                cout << "key: " << table[i]->key << ", value: " << table[i]->value << endl;
            }
        }
    }
};

// Función principal
int main() {
    // Crear una tabla hash de tamaño 10
    HashMap hash_table(10);
    // Insertar elementos
    hash_table.insert(3, 30);
    hash_table.insert(4, 40);
    hash_table.insert(13, 130);
    hash_table.insert(24, 240);
    // Imprimir la tabla hash
    hash_table.print();
    // Buscar y eliminar elementos
    int value = hash_table.find(13);
    cout << "value: " << value << endl;
    hash_table.remove(13);
    // Imprimir la tabla hash actualizada
    hash_table.print();
    system("pause");
    return 0;
}
