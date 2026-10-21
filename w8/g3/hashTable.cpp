#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

class HashTable {
   private:
    vector<list<pair<int, string>>> hashTable;
    int capacity;
    list<pair<int, string>>::iterator it;

    int hash(int key) {
        int x = key & 0xFFFFFFFF;

        x ^= x >> 16;
        x = (x * 0x85ebca6b) & 0xFFFFFFFF;
        x ^= x >> 13;
        x = (x * 0xc2b2ae35) & 0xFFFFFFFF;
        x ^= x >> 16;

        // return key % capacity;
        return x % capacity;
    }

   public:
    HashTable(int capacity) : capacity(capacity) { hashTable.resize(capacity); }

    void insert(int key, string val) {
        int keyIdx = hash(key);
        hashTable[keyIdx].push_back({key, val});
    }

    pair<int, string> search(int key) {
        int keyIdx = hash(key);

        list<pair<int, string>> x = hashTable[keyIdx];
        for (it = x.begin(); it != x.end(); ++it) {
            if ((*it).first == key) {
                return {(*it).first, (*it).second};
            }
        }

        return {-1, ""};
    }

    void display() {
        int i = 0;
        for (list<pair<int, string>> x : hashTable) {
            cout << i << ": [";
            for (it = x.begin(); it != x.end(); ++it) {
                cout << (*it).first << "-" << (*it).second << ", ";
            }
            cout << "]\n";
        }
    }
};

int main() {
    HashTable* ht = new HashTable(5);
    ht->display();

    ht->insert(10, "phone");
    ht->insert(20, "tv");
    ht->insert(7, "fruit");
    ht->insert(27, "ps5");

    cout << "after insertion\n";
    ht->display();

    pair<int, string> elem = ht->search(10);

    cout << elem.first << " " << elem.second << "\n";

    return 0;
}