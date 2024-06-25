#include <iostream>

using namespace std;

int main()
{
    cout << "Choose size of your multidimensional array [matrix]: ";
    int size;
    cin >> size;
    int arr[3][3];
    cout << "Now enter your data [Respectively] \n";
    for(int d=0; d<size; d++)
    {
        for(int j=d+1; j<size; j++)
        {
            if (j==d)
            {
                arr[d][j] = 0;
            }
           
            else if(j>d)
            {
                cin>>arr[d][j]; 
            }
             else    
            {
                arr[d][j] = arr[j][d];
            }
        }
    }

    
    for(int d=0; d<size; d++) {
        for(int j=0; j<size; j++)
            cout << arr[d][j] << " ";
        cout << '\n';
    }

return 0;
}
