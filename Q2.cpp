//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <cassert>
//using namespace std;
//template <class v>
//struct HashItem {
//    int key;
//    v value;
//    short status;
//
//    HashItem()  {
//        key = 0;
//        value = v();
//        status = 0;
//    }  
//};
//
//template <class v>
//class HashMap {
//
//    HashItem<v>* hasharr;
//
//    int currele;
//
//    virtual int getNextCandidateind(int key, int i) {
//        return (key + i) % cap;
//    }
//
//    void doublecap() {
//        int newcap = cap * 2;
//        HashItem<v>* newhasharr = new HashItem<v>[newcap]();
//
//        for (int i = 0; i < cap; ++i) {
//            if (hasharr[i].status == 2) {
//                int newHash = hasharr[i].key % newcap;
//                int j = 1;
//                while (newhasharr[newHash].status == 2) {
//                    newHash = getNextCandidateind(hasharr[i].key, j);
//                    j++;
//                }
//                newhasharr[newHash] = hasharr[i];
//            }
//        }
//
//        delete[] hasharr;
//        hasharr = newhasharr;
//        cap = newcap;
//    }
//
//public:
//    int cap;
//    HashMap(){
//        cap = 10;
//        currele = 0;
//        hasharr = new HashItem<v>[cap]();
//    }
//
//    HashMap(int const cap)  {
//        currele = 0;
//        assert(cap > 0);
//        this->cap = cap;
//        hasharr = new HashItem<v>[cap]();
//    }
//
//    void insert(int const key, v const value) {
//        if (currele >= 0.75 * cap) {
//            doublecap();
//        }
//
//        int ind = key % cap;
//        int i = 1;
//
//        while (hasharr[ind].status == 2) {
//            ind = getNextCandidateind(key, i);
//            i++;
//        }
//
//        hasharr[ind].key = key;
//        hasharr[ind].value = value;
//        hasharr[ind].status = 2;
//        currele++;
//    }
//
//    bool deleteKey(int const key) {
//        int ind = key % cap;
//        int i = 0;
//
//        while (hasharr[ind].status != 0 && i < cap) {
//            if (hasharr[ind].key == key && hasharr[ind].status == 2) {
//                hasharr[ind].status = 1;
//                currele--;
//                return true;
//            }
//
//            ind = getNextCandidateind(key, i);
//            i++;
//        }
//
//        return false;
//    }
//
//    v* get(int const key) {
//        int ind = key % cap;
//        int i = 0;
//
//        while (hasharr[ind].status != 0 && i < cap) {
//            if (hasharr[ind].key == key && hasharr[ind].status == 2) {
//                return &(hasharr[ind].value);
//            }
//
//            ind = getNextCandidateind(key, i);
//            i++;
//        }
//
//        return NULL;
//    }
//
//    ~HashMap() {
//        delete[] hasharr;
//    }
//};
//
//template <class v>
//class QHashMap : public HashMap<v> {
// int getNextCandidateind(int key, int i) override {
//        return (key + i * i) % this->cap;
//    }
//public:
//    QHashMap() : HashMap<v>() {}
//    QHashMap(int const cap) : HashMap<v>(cap) {}
//};
//
//template <class v>
//class DHashMap : public HashMap<v> {
//
//    const int pr = 31;
//
//int getNextCandidateind(int key, int i) override {
//        int firstval = key % this->cap;
//        int secval = (pr - (key % pr));
//        return (firstval + i * secval) % this->cap;
//    }
//public:
//    DHashMap() : HashMap<v>() {}
//    DHashMap(int const cap) : HashMap<v>(cap) {}    
//};
//
//void populateHash(const  string& filename, HashMap< string>* hash) {
//    ifstream inputFile(filename);
//    if (!inputFile.is_open()) {
//        cerr << "Error: Unable to open file " << filename << endl;
//        return;
//    }
//    string line;
//    while (getline(inputFile, line)) {
//        istringstream iss(line);
//        string id, name;
//
//        if (!(iss >> id >> name)) {
//            cerr << "Error: Failed to read <id, name> pair from line: " << line << endl;
//            continue;
//        }
//        hash->insert(stoi(id), name);
//    }
//    inputFile.close();
//}
//
//int main() {
//    HashMap< string>* map;
//    map = new HashMap<string>;
//    populateHash("students.txt", map);
//    cout << *map->get(9);
//    map->deleteKey(9);
//    assert(map->get(9) == nullptr);
//    delete map;
//
//    map = new QHashMap<string>;
//    populateHash("students.txt", map);
//    cout << *map->get(98);
//    map->deleteKey(98);
//    assert(map->get(98) == nullptr);
//    delete map;
//
//    map = new DHashMap<string>;
//    populateHash("students.txt", map);
//    cout << *map->get(101);
//    map->deleteKey(101);
//    assert(map->get(101) == nullptr);
//    delete map;
//
//}
////6837