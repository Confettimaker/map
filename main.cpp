#include <iostream>
#include "map_array.h"

using std::cin;
using std::cout;
using std::endl;


int square(int n)
{
  return (n * n);
}

int print(const int n)
{
  cout << "[ " << n << " ] ";
  return n;
}

int main()
{
  int size;
  int item;

  cout << "How big do you want the array to be?: ";
  cin >> size;

  MapArray<int> array(size);

  for (int i = 0;i < size;i++)
  {
    cout << "Element (" << i + 1 << "): ";
    cin >> item;
    array.push(item);
  }

  cout << "-- Before Square Mapping --" << endl << endl;

  array.map(print);

  cout << endl;

  array = array.map(square);

  int * item_ = &array.at(size - 1);

  *item_ = 900;

  cout << "-- After Square Mapping -- " << endl << endl;

  array.map(print);

  cout << endl;

  cout << "-- Pop Test --" << endl << endl;

  while (array.pop())
  {
    cout << "Array Size: " << array.size() << endl;
  }

  cout << endl;

  cout << "Item: " << *item_ << endl;

  return 0;
}
