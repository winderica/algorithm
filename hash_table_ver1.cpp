#include <iostream>
using namespace std;

const int TABLE_SIZE = 256;

class HashItem {
private:
    int key;
    int value;
public:
    HashItem(int key, int value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }
};

class HashTable {
private:
    HashItem **table;
public:
    HashTable() {
        table = new HashItem*[TABLE_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i]) {
                delete table[i];
            }
        }
        delete[] table;
    }

    int get(int key) {
        int hash = key % TABLE_SIZE;
        while (table[hash] && table[hash]->getKey() != key) {
            hash = (hash + 1) % TABLE_SIZE;
        }
        return table[hash] ? table[hash]->getValue() : -1;
    }

    void set(int key, int value) {
        int hash = key % TABLE_SIZE;
        while (table[hash] && table[hash]->getKey() != key) {
            hash = (hash + 1) % TABLE_SIZE;
        }
        if (!table[hash]) {
            delete table[hash];
        }
        table[hash] = new HashItem(key, value);
    }

    void remove(int key) {
        int hash = key % TABLE_SIZE;
        while (!table[hash] && table[hash]->getKey() != key) {
            hash = (hash + 1) % TABLE_SIZE;
        }
        table[hash] = nullptr;
        delete table[hash];
    }
};

int main() {
    HashTable* a = new HashTable;
    for (int i = 100; i <= 110; i++) {
        a->set(i, 11 - i);
    }
    for (int i = 100; i <= 110; i++) {
        cout << a->get(i) << endl;
    }
    for (int i = 100; i <= 110; i++) {
        a->remove(i);
    }
    for (int i = 100; i <= 110; i++) {
        cout << a->get(i) << endl;
    }
    for (int i = 100; i <= 110; i++) {
        a->set(i, 11 - i);
    }
    for (int i = 100; i <= 110; i++) {
        cout << a->get(i) << endl;
    }
}
