#include <iostream>
#include <list>  // linked list
#include <unordered_map> // hashTable
#include <vector>

using namespace std;

typedef pair<int, string> pis;

class HashTable {
   private:
    vector<list<pis>> table;
    list<pis>::iterator lit;
    int capacity;

    int hash(int key) { return key % capacity; }

   public:
    HashTable(int capacity) {
        this->capacity = capacity;
        table.resize(capacity);
    }

    void insert(int key, string value) {
        int keyH = hash(key);

        table[keyH].push_back({key, value});
    }

    pis search(int key) {
        int keyH = hash(key);

        if (!table[keyH].empty()) {
            return *table[keyH].begin();
        }
        return {-1, ""};
    }

    void display() {
        for (int i = 0; i < table.size(); ++i) {
            cout << table[i].size() << " ";
        }
        cout << endl;
    }
};

int main() {
    HashTable* ht = new HashTable(10);

    ht->display();

    ht->insert(4, "apple");
    ht->insert(10, "orange");
    ht->insert(14, "pineapple");

    pis elem = ht->search(4);

    cout << elem.first << " " << elem.second << endl;

    ht->display();

    return 0;
}