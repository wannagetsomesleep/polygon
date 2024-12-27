#include <iostream>
#include <vector>
#include <algorithm> // ��� std::sort

void bucketSort(std::vector<float>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    // 1. ������ k ����
    std::vector<std::vector<float>> buckets(k);

    // 2. ������������ �������� �� �����
    for (int i = 0; i < n; i++) {
        // ���������, ����� ������� ��������� � �������� [0, 1)
        if (arr[i] < 0 || arr[i] >= 1) {
            throw std::invalid_argument("�������� ������� ������ ���������� � ��������� [0, 1).");
        }
        int bucketIndex = static_cast<int>(k * arr[i]); // ������ �����
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. ��������� ������ �����
    for (int i = 0; i < k; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. ���������� ���� � �������� ������
    int index = 0;
    for (int i = 0; i < k; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    // ������ �������� � ��������� [0, 1)
    std::vector<float> arr = { 0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51 };
    int k = 10; // ���������� ����

    std::cout << "�������� ������: ";
    for (float i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    try {
        bucketSort(arr, k);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "������: " << e.what() << "\n";
        return 1; // ��������� � �������
    }

    std::cout << "��������������� ������: ";
    for (float i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}