#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef pair<int, string> pis;

class HashTable {
   private:
    vector<list<pis>> table;
    int capacity;
    list<pis>::iterator it;

    int hash(int key) { return key % capacity; }

   public:
    HashTable(int capacity) : capacity(capacity) { table.resize(capacity); }

    void insert(int key, string value) {
        int keyIdx = hash(key);

        table[keyIdx].push_back({key, value});
    }

    list<pis> search(int key) {
        int keyIdx = hash(key);

        list<pis> result;

        for (it = table[keyIdx].begin(); it != table[keyIdx].end(); ++it) {
            if ((*it).first == key) {
                result.push_back(*it);
            }
        }
        return result;
    }

    void display() {
        int i = 0;
        for (list<pis> l : table) {
            cout << i << ": [";
            for (it = l.begin(); it != l.end(); ++it) {
                cout << (*it).first << ": " << (*it).second << ", ";
            }
            cout << "]\n";
            i++;
        }
    }
};

int main() {
    HashTable* ht = new HashTable(3);

    ht->display();

    ht->insert(10, "apple");
    ht->insert(9, "orange");
    ht->insert(3, "blueberry");
    ht->insert(5, "pineapple");

    ht->display();

    list<pis> result = ht->search(5);
    cout << result.size() << endl;

    return 0;
}