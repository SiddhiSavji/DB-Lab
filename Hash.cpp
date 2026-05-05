#include <iostream>
using namespace std;

class HashTable {
    int size;
    int table[100];   // fixed size array (simple)

public:
    // Constructor
    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++)
            table[i] = -1;   // -1 means empty
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Insert (Linear Probing)
    void insert(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % size;

            if (index == start) {
                cout << "Hash Table is full\n";
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // Search
    int search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return index;

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        return -1;
    }

    // Display
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    int keys[] = {15, 25, 35, 20, 30};

    // Insert keys
    for (int i = 0; i < 5; i++) {
        ht.insert(keys[i]);
    }

    cout << "\nHash Table:\n";
    ht.display();

    cout << "\nSearch 25: " << ht.search(25) << endl;
    cout << "Search 99: " << ht.search(99) << endl;

    return 0;
}