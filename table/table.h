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
class Table {
  private:
    Item<ValueT> *_table = new Item<ValueT>[CAPACITY];
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
        throw invalid_argument("findIndex: element by this key does not exist");
      }
    }

  public:
    // default constructor
    Table() {
      _count = 0;
    }

  int Count() {
    return _count;
  }

  bool contain(string key) {
    bool finded = false;

    for (int i = 0; i < CAPACITY; i++) {
      if (_table[i].key == key) {
        finded = true;
        break;
      }
    }

    return finded;
  }

  void put(string key, ValueT new_value) {
    if (contain(key)) {
      int index = findIndex(key);

      _table[index].value = new_value;
    } else if (_count < CAPACITY) {
      for (int i = 0; i < CAPACITY; i++) {
        if (_table[i].key == "") {
          _table[i].key = key;
          _table[i].value = new_value;
          _count++;
          break;
        }
      }
    } else {
      throw length_error("put: table is full");
    }
  }

  void erase(string key) {
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

  void keysDo(void (*KeyDelegate)(string)) {
    for (int i = 0; i < CAPACITY; i++) {
      if (_table[i].key != "") {
        (*KeyDelegate)(_table[i].key);
      }
    }
  }

  void valuesDo(void (*ValueDelegate)(ValueT)) {
    for (int i = 0; i < CAPACITY; i++) {
      if (_table[i].key != "") {
        (*ValueDelegate)(_table[i].value);
      }
    }
  }

  string* getKeys() {
    string keys[CAPACITY];

    for (int i = 0; i < CAPACITY; i++) {
      keys[i] = _table[i].key;
    }

    return keys;
  }

  ValueT* getValues() {
    ValueT values[CAPACITY];

    for (int i = 0; i < CAPACITY; i++) {
      if (_table[i].key != "") {
        values[i] = _table[i].value;
      } else {
        values[i] = NULL;
      }
    }

    return values;
  }

  // copy constructor Table(const Table&)
  Table(const Table& copy) {
    _count = copy._count;

    for (int i = 0; i < CAPACITY; i++) {
      _table[i].key = copy._table[i].key;
      _table[i].value = copy._table[i].value;
    }
  }

  // assignment operator function
  Table operator=(const Table &tb) {
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

  ~Table() {
    delete[] _table;
  }
};
