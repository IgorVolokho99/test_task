#include <iostream>


void doubleArrayElements(int* arr, size_t size_arr) {

    if (arr == nullptr) {
        std::cerr << "Error: Not valide pointer." << std::endl;
        return;
    }


    for (size_t i = 0; i < size_arr; ++i) {
        arr[i] *= 2;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);


    doubleArrayElements(arr, arrSize);

    std::cout << "Double array: ";
    for (size_t i = 0; i < arrSize; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
