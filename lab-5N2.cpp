#include <iostream>
#include <vector>

// Функция для преобразования поддерева в max-кучу
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если наибольший элемент не корень
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция для пирамидальной сортировки
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Проверка на пустой массив
    if (n == 0) return;

    // Построение max-кучи
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // Преобразуем уменьшенную кучу
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    std::cout << "Исходный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n"; // Используем "\n" для повышения производительности

    heapSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n"; // Используем "\n"

    return 0;
}