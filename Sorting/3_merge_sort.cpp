#include <iostream>

using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge(arr, left, mid);       // Recursively sort the first half
    merge(arr, mid + 1, right);  // Recursively sort the second half

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array: ";
    printArray(arr, size);

    merge(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
