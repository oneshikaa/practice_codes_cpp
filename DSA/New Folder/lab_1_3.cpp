#include <iostream>
using namespace std;

int main() {
  int arr[5] = {1};
  cout << "Prints 1 followed by zeros" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
