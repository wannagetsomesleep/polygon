#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>
#include <chrono>
#include <random> // Для генерации случайных чисел

using namespace std;


// Функция для расчета стоимости разбиения
double calculateCost(const vector<vector<double>>& clusters) {
    double totalCost = 0.0;
    for (const auto& cluster : clusters) {
        if (cluster.empty()) continue;
        double mean = accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size(); // Вычисляется среднее значение для текущего кластера.
        for (double val : cluster) {
            totalCost += abs(val - mean); //Вычисляется модуль разности между текущим числом val и средним значением mean, и добавляется к общей стоимости 
        }
    }
    return totalCost;
}

// Функция для генерации всех возможных разбиений массива на 5 кластеров
void generatePartitions(const vector<double>& arr, int start, vector<vector<double>>& current, vector<vector<vector<double>>>& result) {
    if (current.size() == 5) { // Фиксируем K = 5 : Проверяем, сформировано ли разбиение на 5 кластеров.
         if (start == arr.size()) { // Все элементы распределены
            result.push_back(current);
        }
        return;
    }

    for (int i = start; i <= arr.size() - (5 - current.size()); ++i) { //: Этот цикл перебирает все возможные индексы, чтобы сформировать новый кластер.
        current.push_back({}); //создаем новый кластер (пустой вектор)
        for (int j = start; j <= i; ++j) {
            current.back().push_back(arr[j]); // заполняем новый вектор элементами из исходного массива
        }
        generatePartitions(arr, i + 1, current, result);
        current.pop_back(); // убираем последний кластер, чтобы попробовать другие варианты
    }
}

// Функция для поиска оптимального разбиения
vector<vector<double>> findOptimalPartition(const vector<double>& arr) { 
    vector<vector<vector<double>>> allPartitions; // Создаем вектор allPartitions для хранения всех возможных разбиений.
    vector<vector<double>> currentPartition; //  Создаем вектор currentPartition для хранения текущего разбиения при генерации.
    generatePartitions(arr, 0, currentPartition, allPartitions); // Вызываем функцию generatePartitions для генерации всех разбиений.

    double minCost = numeric_limits<double>::max(); // Создаем переменную minCost для хранения минимальной стоимости
    vector<vector<double>> bestPartition;

    for (const auto& partition : allPartitions) {
        double cost = calculateCost(partition); // Вычисляем стоимость текущего разбиения с помощью функции calculateCost.
        if (cost < minCost) { //Если стоимость текущего разбиения меньше, чем минимальная стоимость, то обновляем минимальную стоимость и оптимальное разбиение.
            minCost = cost;
            bestPartition = partition;
        }
    }

    return bestPartition;
}


int main() {
    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0); // Числа от 0.0 до 10.0

    // Размеры тестовых массивов
    vector<int> sizes = {5, 10, 15, 20, 25}; 

    for (int size : sizes) {
        // Создаем тестовый массив случайных чисел
        vector<double> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = dis(gen); // генерируем случайное число
        }

        cout << "Для массива размера: " << size << endl;

        auto start = chrono::high_resolution_clock::now();
        vector<vector<double>> result = findOptimalPartition(arr);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;

        cout << "Время выполнения: " << elapsed.count() << " секунд" << endl;
        //printPartition(result); // Закомментируй вывод!

        cout << "-------------------------" << endl;
    }

    return 0;
}

