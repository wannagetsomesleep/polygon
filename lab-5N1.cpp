#include <iostream>
#include <vector>

void shakerSort(std::vector<int>& arr) {
    // Проверяем, пуст ли массив
    if (arr.empty()) return;

    int left = 0; // Левая граница
    int right = arr.size() - 1; // Правая граница
    bool swapped = true; // Флаг для отслеживания перестановок

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--; // Уменьшаем правую границу

        // Если не было перестановок, массив уже отсортирован
        if (!swapped) break;

        swapped = false;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++; // Увеличиваем левую границу
    }
}

int main() {
    std::vector<int> arr = { 5, 1, 4, 2, 8, 0, 2 };

    std::cout << "Исходный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    shakerSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}