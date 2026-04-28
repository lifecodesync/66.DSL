#include <iostream>
#include <algorithm> 
using namespace std;


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}


int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, choice, key, result;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

     {
        cout << "Choice card" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter the element to search: ";
            cin >> key;
        }

        switch (choice) {
            case 1:
                result = linearSearch(arr, n, key);
                (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
                break;

            case 2:
                
                sort(arr, arr + n);
                cout << "Sorted array for Binary Search: ";
                for(int i=0; i<n; i++) cout << arr[i] << " ";
                
                result = binarySearch(arr, 0, n - 1, key);
                (result != -1) ? cout << "\nElement found at index " << result : cout << "\nElement not found";
                break;

            default:
                cout << "Invalid choice!";
        }
        cout << endl;
    } 

    return 0;
}
