#include <iostream>
#include "map_array.h"

using std::cin;
using std::cout;
using std::endl;


void square(int & n)
{
  n = (n * n);
}

void print(const int & n)
{
  cout << "[ " << n << " ] ";
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

  array.map(square);

  cout << "-- After Square Mapping -- " << endl << endl;

  array.map(print);

  cout << endl;

  return 0;
}
