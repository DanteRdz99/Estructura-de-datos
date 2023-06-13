#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;

// Definicion de una entrada de la tabla hash
struct HashEntry {
    int key;
    bool deleted;

    HashEntry() : key(-1), deleted(false) {}
};

// Definicion de la tabla hash
vector<HashEntry> hash_table(TABLE_SIZE);

// Funcion de hashing
int hash_function(int key) {
    return key % TABLE_SIZE;
}

// Funcion de insercion
void insert(int key) {
    int index = hash_function(key);

    // Si la posicion está vacía o eliminada, inserta el elemento directamente
    if (hash_table[index].key == -1 || hash_table[index].deleted) {
        hash_table[index].key = key;
        hash_table[index].deleted = false;
        return;
    }

    // En caso contrario, resuelve colision con hashing cerrado
    int i = 1;
    while (hash_table[(index + i * i) % TABLE_SIZE].key != -1 && !hash_table[(index + i * i) % TABLE_SIZE].deleted) {
        i++;
    }
    hash_table[(index + i * i) % TABLE_SIZE].key = key;
    hash_table[(index + i * i) % TABLE_SIZE].deleted = false;
}

// Funcion de búsqueda
int search(int key) {
    int index = hash_function(key);

    // Si la posicion coincide con la llave y no está eliminada, devuelve el índice
    if (hash_table[index].key == key && !hash_table[index].deleted) {
        return index;
    }

    // En caso contrario, resuelve colision con hashing cerrado
    int i = 1;
    while (hash_table[(index + i * i) % TABLE_SIZE].key != key && hash_table[(index + i * i) % TABLE_SIZE].key != -1) {
        i++;
    }

    if (hash_table[(index + i * i) % TABLE_SIZE].key == key && !hash_table[(index + i * i) % TABLE_SIZE].deleted) {
        return (index + i * i) % TABLE_SIZE;
    }

    return -1;
}

// Funcion de eliminacion
void remove(int key) {
    int index = search(key);

    // Si la llave no existe en la tabla, devuelve un mensaje de error
    if (index == -1) {
        cout << "Error: elemento no encontrado." << endl;
        return;
    }

    // En caso contrario, marca la entrada como eliminada
    hash_table[index].deleted = true;
}

// Funcion para imprimir la tabla hash
void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Posicion " << i << ": ";
        if (hash_table[i].key != -1 && !hash_table[i].deleted) {
            cout << hash_table[i].key;
        } else {
            cout << "Vacía";
        }
        cout << endl;
    }
}

int main() {
    // Insercion de elementos
    insert(2);
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);
    insert(62);
    insert(72);
    insert(82);
    insert(92);

    // Impresion de la tabla hash
    cout << "Tabla hash:" << endl;
    print_table();

    // Búsqueda
int index = search(42);
if (index == -1) {
    cout << "Elemento no encontrado." << endl;
} else {
    cout << "El elemento 42 está en la posicion " << index << "." << endl;
}

// Eliminacion
remove(42);

// Impresion de la tabla hash después de eliminar el elemento 42
cout << "Tabla hash despues de eliminar el elemento 42:" << endl;
print_table();
system("pause");
return 0;
}