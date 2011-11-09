#include <iostream>
#include <vector>
#include <algorithm>

#include <stdint.h> // for size-specific names of integers, like uint32_t

using namespace std;

void dumpList( vector<uint32_t> &list ) {
  for (vector<uint32_t>::iterator i = list.begin();
       i != list.end();
       i++) {
    if (i != list.begin()) cout << ", ";
    cout << *i;
  }
  cout << endl;
}


int main() {
  vector<uint32_t> numbers;

  // Read positive integers from STDIN. Put them in the vector.
  uint32_t read_int = 0xFFFFFFFF; // anything non-zero
  while (read_int != 0) {
    cout << "Please enter a positive number (or zero to stop entering numbers)"
         << endl
         << "# ";
    cin >> read_int;
    if (cin.eof()) break;
    if (cin.fail()) {
      cerr << "Bad data! Aborting..." << endl;
      exit(1);
    }
    cout << endl << endl;

    cout << "Read '" << read_int << "'" << endl;
    cout << endl << endl;

    if (read_int != 0) numbers.push_back(read_int);
  }

  cout << numbers.size() << " positive numbers read." << endl;
  dumpList(numbers);
  cout << endl << endl;


  ////////////////////////////////////////////////////////////////////////
  // Sort the vector
  ////////////////////////////////////////////////////////////////////////

  // Method 1 (integer indices; similar to using an array)
  vector<uint32_t> method1_list = numbers;
  for (size_t i=0; i<method1_list.size()-1; i++) {
    size_t min = i;
    for (size_t j=i+1; j<method1_list.size(); j++) {
      if (method1_list[j] < method1_list[min]) min = j;
    }
    if (min != i) {
      uint32_t tmp = method1_list[i];
      method1_list[i] = method1_list[min];
      method1_list[min] = tmp;
    }
  }
  cout << "Sorted numbers (method 1):" << endl;
  dumpList(method1_list);
  cout << endl;


  // Method 2 (iterators)
  vector<uint32_t> method2_list = numbers;
  for (vector<uint32_t>::iterator i = method2_list.begin();
       i != method2_list.end();
       i++) {
    vector<uint32_t>::iterator min = i;
    for (vector<uint32_t>::iterator j=i+1;
         j != method2_list.end();
         j++) {
      if (*j < *min) min = j;
    }
    if (min != i) {
      uint32_t a = *i, b = *min;
      *i = b;
      *min = a;
    }
  }
  cout << "Sorted numbers (method 2):" << endl;
  dumpList(method2_list);
  cout << endl;


  // Method 2 (STL algorithm)
  vector<uint32_t> method3_list = numbers;
  sort(method3_list.begin(),method3_list.end());
  cout << "Sorted numbers (method 3):" << endl;
  dumpList(method3_list);
  cout << endl;

}
