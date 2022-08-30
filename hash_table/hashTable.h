#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

const int CAPACITY = 1000;

template <typename ValueT> struct Item {
	string key;
  ValueT value;
};

template <typename ValueT>
class HashTable {
  private:
    Item<ValueT> *_table = new Item<ValueT>[CAPACITY];
    int _count;

    int hash_function(string key, int iteration = 0) {
      int result = iteration;

      for (int i = 0; i != key.size(); i++) {
        result += (key[i]);
      }

      result *= (CAPACITY * 0,618033) % CAPACITY;

      return result;
    }

  public:
    // default constructor
    HashTable() {
      _count = 0;
    }

  int Count() {
    return _count;
  }

  int findIndex(string key) {
    int iter = 0;
    int index = hash_function(key, iter);

    while (_table[index].key != "" || iter < CAPACITY) {
      iter++;
    }

    return index;
  }

  bool contain(string key) {
    int iter = 0;


    while (_table[hash_function(key, iter)].key != key || iter < CAPACITY) {
      iter++;
    }

    return _table[hash_function(key, iter)].key == key;
  }

  void put(string key, ValueT new_value) {
    int iter = 0;
    int index = hash_function(key, iter);

    while (_table[index].key != "" || iter < CAPACITY) {
      iter++;
    }

    if (iter == CAPACITY) {
      throw length_error("put: table is full");
    } else {
      _table[index].key = key;
      _table[index].value = new_value;
      _count++;
    }
  }

  void erase(string key) {
    int iter = 0;

    if (contain(key)) {
      int index = findIndex(key);

      _table[index].key = "";
      _table[index].value = nullptr;
      _count--;
    } else {
      throw invalid_argument("erase: element by this key does not exist");
    }
  }

  ValueT valueAt(string key) {
    if (contain(key)) {
      int index = findIndex(key);

      return _table[index].value;
    } else {
      throw invalid_argument("valueAt: element by this key does not exist");
    }
  }

  // copy constructor Table(const Table&)
  HashTable(const HashTable& copy) {
    _count = copy._count;

    for (int i = 0; i < CAPACITY; i++) {
      _table[i].key = copy._table[i].key;
      _table[i].value = copy._table[i].value;
    }
  }

  // assignment operator function
  HashTable operator=(const HashTable &tb) {
    /* SELF ASSIGNMENT CHECK */
    if(this != &tb) {
      _count = tb._count;

      // 3. Copy data from tb
      for (int i = 0; i < CAPACITY; i++) {
        _table[i].key = tb._table[i].key;
        _table[i].value = tb._table[i].value;
      }
    }

    // 4. Return current object
    return *this;
  }

  ~HashTable() {
    delete[] _table;
  }
};
