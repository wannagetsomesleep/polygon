#include <iostream>
#include <vector>

void shakerSort(std::vector<int>& arr) {
    // ���������, ���� �� ������
    if (arr.empty()) return;

    int left = 0; // ����� �������
    int right = arr.size() - 1; // ������ �������
    bool swapped = true; // ���� ��� ������������ ������������

    while (swapped) {
        swapped = false;

        // ������ ����� �������
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--; // ��������� ������ �������

        // ���� �� ���� ������������, ������ ��� ������������
        if (!swapped) break;

        swapped = false;

        // ������ ������ ������
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++; // ����������� ����� �������
    }
}

int main() {
    std::vector<int> arr = { 5, 1, 4, 2, 8, 0, 2 };

    std::cout << "�������� ������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    shakerSort(arr);

    std::cout << "��������������� ������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}