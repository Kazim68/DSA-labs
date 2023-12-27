#include <vector>
#include <list>
#include <iostream>

using namespace std;

class HashChain{
public:
    vector<list<int>> map;

    HashChain(){
        map = vector<list<int>>(10);
    }

    void insert(int key, int value){
        map[index(key)].push_back(value);
    }

    int index(int key){
        return key % 10;
    }

    bool search(int key, int value){
        return exploreList(map[index(key)], key);
    }

    int exploreList(list<int> temp, int key){
        for (auto itr = temp.begin(); itr != temp.end(); itr++){
            if (*(itr) == key)
                return true;
        }
    }

    void printMap(){
        for (int i = 0; i < map.size(); i++){
            cout << i << ": ";

            list<int> temp = map[i];

            for (auto itr = temp.begin(); itr != temp.end(); itr++){
                cout << *(itr) << " ";
            }

            cout << endl;
        }
    }
};

int main(){
    HashChain map;

    map.insert(2, 8);
    map.insert(22, 9);
    map.insert(45, 90);
    map.insert(5, 2);

    cout << map.search(22, 9) << endl;

    map.printMap();

    return 0;
}