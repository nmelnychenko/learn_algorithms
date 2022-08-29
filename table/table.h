#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

const int CAPACITY = 1000;

// template <typename KeyT, typename ValueT>
struct Item
{
	string key;
  string value;
};

class Table {
  private:
    Item* _table = new Item[CAPACITY];
    int _count;

    int findIndex(string key) {
      int index;
      bool finded = false;

      for (int i = 0; i < CAPACITY; i++) {
        if (_table[i].key == key) {
          index = i;
          finded = true;
          break;
        }
      }

      if (finded) {
        return index;
      } else {
        throw invalid_argument('element by this key does not exist');
      }
    }

  public:
    // default constructor
    Table() {
      _table = nullptr;
      _count = 0;
    }

  int Count() {
    return _count;
  }

  bool contain(string key) {
    try {
      int index = findIndex(key);
      return true;
    } catch(const invalid_argument& err) {
      cerr << "Invalid argument: " << err.what() << '\n';
      return false;
    }
  }

  void put(string key, string new_value) {
    if (contain(key)) {
      int index = findIndex(key);

      _table[index].value = new_value;
    } else if (_count < CAPACITY) {
      for (int i = 0; i < CAPACITY; i++) {
        if (_table[i].key == null) {
          _table[i].key = key;
          _table[i].value = new_value;
          _count++;
          break;
        }
      }
    } else {
      throw length_error('table is full');
    }
  }

  void erase(string key) {
    if (contain(key)) {
      int index = findIndex(key);

      _table[index].key = null;
      _table[index].value = null;
      _count--;
    } else {
      throw invalid_argument('element by this key does not exist');
    }
  }

  string valueAt(string key) {
    if (contain(key)) {
      int index = findIndex(key);

      return _table[index].value;
    } else {
      throw invalid_argument('element by this key does not exist');
    }
  }

  // copy constructor Table(const Table&)
  // Table(const Table& copy) {
    // 0. Initialize fields

  // }

  // assignment operator function
  // Table operator=(const Table &st) {
    /* SELF ASSIGNMENT CHECK */
    // if(this != &st) {
      // 1. Deallocate old memory
      
    // }

    // 4. Return current object
    // return *this;
  // }

  ~Table() {
    delete[] _table;
  }
};
