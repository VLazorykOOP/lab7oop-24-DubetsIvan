#include <iostream>
#include <cstring> 

using namespace std;

template <typename T>
void swapFirstMinMax(T arr[], int size) {
    if (size <= 1) return;

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    T temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

template <>
void swapFirstMinMax<char*>(char* arr[], int size) {
    if (size <= 1) return;

    int minLengthIndex = 0;
    int maxLengthIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (strlen(arr[i]) < strlen(arr[minLengthIndex])) minLengthIndex = i;
        if (strlen(arr[i]) > strlen(arr[maxLengthIndex])) maxLengthIndex = i;
    }

    char* temp = arr[minLengthIndex];
    arr[minLengthIndex] = arr[maxLengthIndex];
    arr[maxLengthIndex] = temp;
}

template<typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

template<>
int binarySearch<char*>(char* arr[], int size, char* key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int comparison = strcmp(arr[mid], key);
        if (comparison == 0) return mid;
        if (comparison < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

template<typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArr[] = { 5, 2, 8, 1, 9 };
    char* strArr[] = { (char*)"apple", (char*)"banana", (char*)"cherry", (char*)"date" };
    int intArrSize = sizeof(intArr) / sizeof(intArr[0]);
    int strArrSize = sizeof(strArr) / sizeof(strArr[0]);
    swapFirstMinMax(intArr, intArrSize);
    swapFirstMinMax(strArr, strArrSize);
    cout << "After swapping first and min/max elements:\n";
    printArray(intArr, intArrSize);
    printArray(strArr, strArrSize);

    double doubleArr[] = { 3.5, 1.2, 8.9, 5.4, 2.1 };
    int doubleArrSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    bubbleSort(doubleArr, doubleArrSize);
    cout << "After sorting using bubble sort:\n";
    printArray(doubleArr, doubleArrSize);

    char* searchKey = (char*)"banana";
    int searchResult = binarySearch(strArr, strArrSize, searchKey);
    if (searchResult != -1) {
        cout << "The key '" << searchKey << "' is found at index: " << searchResult << endl;
    }
    else {
        cout << "The key '" << searchKey << "' is not found.\n";
    }

    return 0;
}
