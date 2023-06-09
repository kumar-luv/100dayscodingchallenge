#include <iostream>
using namespace std;

void customSort(int arr[], int size) {
    int low = 0, high = size - 1, mid = 0;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else if (arr[mid] == 2) {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main() {
    int numbers[] = {0, 1, 1, 2, 0, 1, 1, 2};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    customSort(numbers, size);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
