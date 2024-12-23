#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>

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

// Функция для генерации всех возможных разбиений массива на K кластеров
void generatePartitions(const vector<double>& arr, int K, int start, vector<vector<double>>& current, vector<vector<vector<double>>>& result) {
    if (K == 1) {
        current.back().insert(current.back().end(), arr.begin() + start, arr.end());
        result.push_back(current);
        current.back().erase(current.back().end() - (arr.size() - start), current.back().end());
        return;
    }

    for (int i = start; i <= arr.size() - K; ++i) {
        current.back().push_back(arr[i]);
        current.push_back({});
        generatePartitions(arr, K - 1, i + 1, current, result);
        current.pop_back();
        current.back().pop_back();
    }
}

// Функция для поиска оптимального разбиения
vector<vector<double>> findOptimalPartition(const vector<double>& arr, int K) {
    vector<vector<vector<double>>> allPartitions;
    vector<vector<double>> currentPartition = { {} };
    generatePartitions(arr, K, 0, currentPartition, allPartitions);

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

// Пример использования
int main() {
    vector<double> arr1 = { 1, 2, 3, 4, 5, 6 };
    int K1 = 2;
    vector<vector<double>> result1 = findOptimalPartition(arr1, K1);
    cout << "Example 1:" << endl;
    for (const auto& cluster : result1) {
        for (double val : cluster) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<double> arr2 = { 1, 10, 9, 2, 3, 8 };
    int K2 = 2;
    vector<vector<double>> result2 = findOptimalPartition(arr2, K2);
    cout << "\nExample 2:" << endl;
    for (const auto& cluster : result2) {
        for (double val : cluster) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<double> arr3 = { 99.5, -1.1, 101 };
    int K3 = 2;
    vector<vector<double>> result3 = findOptimalPartition(arr3, K3);
    cout << "\nExample 3:" << endl;
    for (const auto& cluster : result3) {
        for (double val : cluster) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
