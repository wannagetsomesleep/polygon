#include <iostream>
#include <vector>
#include <algorithm> // для std::swap
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time

// Функция для перемешивания массива
void shuffleArray(std::vector<int>& arr) {
    // Инициализация генератора случайных чисел
    std::srand(std::time(0));

    // Алгоритм Фишера-Йетса
    for (int i = arr.size() - 1; i > 0; --i) {
        // Генерация случайного индекса от 0 до i
        int j = std::rand() % (i + 1);

        // Меняем местами arr[i] и arr[j]
        std::swap(arr[i], arr[j]);
    }
}

int main() {
    // Пример входных данных
    std::vector<int> arr = {1, 100, 10, 2};

    // Перемешиваем массив
    shuffleArray(arr);

    // Выводим результат
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
