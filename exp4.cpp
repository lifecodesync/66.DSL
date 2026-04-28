#include <iostream>
using namespace std;

int main() {
    int n, choice, temp;

    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Choice card"<<endl;
    cout << "1. Bubble Sort (Compare neighbors)"<<endl;
    cout << "2. Selection Sort (Find minimum)"<<endl;
    cout << "3. Insertion Sort (Pick and place)"<<endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: 
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
                    }
                }
            }
            break;

        case 2: 
            for (int i = 0; i < n - 1; i++) {
                int min_idx = i;
                for (int j = i + 1; j < n; j++)
                    if (arr[j] < arr[min_idx]) min_idx = j;
                temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
            }
            break;

        case 3: 
            for (int i = 1; i < n; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
            break;

        default:
            cout << "Invalid choice!";
            return 0;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
