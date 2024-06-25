#include <iostream>
using namespace std;

/*
1
22
333
4444
55555
*/

int main()
{
    int counter = 0;
   
    for (int i = 0; i < 6; i++)
    { 
   
        for (int j = 0; j < i; j++)
        {
            cout << counter;
            
           
        }
          counter++;
        cout << "\n";
    }
}