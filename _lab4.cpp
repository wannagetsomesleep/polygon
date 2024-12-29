#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>
#include <chrono>

using namespace std;

// Функция для расчета стоимости данного разбиения
double calculateCost(const vector<vector<double>>& clusters) {
    double totalCost = 0.0;
    for (const auto& cluster : clusters) {
        if (cluster.empty()) continue;
        double mean = accumulate(cluster.begin(), cluster.end(), 0.0) / cluster.size();
        for (double val : cluster) {
            totalCost += abs(val - mean);
        }
    }
    return totalCost;
}

// Функция для генерации всех возможных разбиений массива на 5 кластеров
void generatePartitions(const vector<double>& arr, int start, vector<vector<double>>& current, vector<vector<vector<double>>>& result) {
    if (current.size() == 5) { // Фиксируем K = 5
        if (start == arr.size()) { // Все элементы распределены
            result.push_back(current);
        }
        return;
    }

    for (int i = start; i <= arr.size() - (5 - current.size()); ++i) {
        current.push_back({});
        for (int j = start; j <= i; ++j) {
            current.back().push_back(arr[j]);
        }
        generatePartitions(arr, i + 1, current, result);
        current.pop_back();
    }
}

// Функция для поиска оптимального разбиения
vector<vector<double>> findOptimalPartition(const vector<double>& arr) {
    vector<vector<vector<double>>> allPartitions;
    vector<vector<double>> currentPartition;
    generatePartitions(arr, 0, currentPartition, allPartitions);

    double minCost = numeric_limits<double>::max();
    vector<vector<double>> bestPartition;

    for (const auto& partition : allPartitions) {
        double cost = calculateCost(partition);
        if (cost < minCost) {
            minCost = cost;
            bestPartition = partition;
        }
    }

    return bestPartition;
}

// Функция для вывода разбиения в нужном формате
void printPartition(const vector<vector<double>>& partition) {
    for (size_t i = 0; i < partition.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < partition[i].size(); ++j) {
            cout << partition[i][j];
            if (j < partition[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < partition.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    // Тестовые данные
    vector<vector<double>> testArrays = {
        {1, 2, 3, 4, 5, 6},
        {1, 10, 9, 2, 3, 8},
    };

    for (const auto& arr : testArrays) {
        cout << "Для массива: ";
        for (double val : arr) {
            cout << val << " ";
        }
        cout << endl;

        auto start = chrono::high_resolution_clock::now();
        vector<vector<double>> result = findOptimalPartition(arr);
        auto end = chrono::high_resolution_clock::now();

        cout << "Оптимальное разбиение: ";
        printPartition(result);

        chrono::duration<double> elapsed = end - start;
        cout << "Время выполнения: " << elapsed.count() << " секунд" << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
