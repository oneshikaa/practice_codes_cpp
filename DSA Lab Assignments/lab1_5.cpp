 #include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            
            return binarySearch(arr, l, mid - 1, x);
        if    (arr[mid] < x)
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
	int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter your elements: ";
    for(int i = 0;i<n;i++)
    cin>>arr[i];
    int x;
    cout<<"Enter the element you want to search from the array: ";
    cin>>x;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"<<endl
				: cout << "Element is present at position number: " << result+1<<endl;
	return 0;
}
