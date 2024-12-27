#include <iostream>
#include <vector>

// ������� ��� �������������� ��������� � max-����
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // �������������� ���������� ������� ��� ������
    int left = 2 * i + 1; // ����� �������� �������
    int right = 2 * i + 2; // ������ �������� �������

    // ���� ����� �������� ������� ������ �����
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // ���� ������ �������� ������� ������ �������� �����������
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // ���� ���������� ������� �� ������
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // ���������� ����������� ���������� ���������
        heapify(arr, n, largest);
    }
}

// �������� ������� ��� ������������� ����������
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // �������� �� ������ ������
    if (n == 0) return;

    // ���������� max-����
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // ���������� ��������� �� ����
    for (int i = n - 1; i > 0; i--) {
        // ���������� ������� ������ � �����
        std::swap(arr[0], arr[i]);

        // ����������� ����������� ����
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    std::cout << "�������� ������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n"; // ���������� "\n" ��� ��������� ������������������

    heapSort(arr);

    std::cout << "��������������� ������: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n"; // ���������� "\n"

    return 0;
}