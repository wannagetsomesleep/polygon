#include <iostream>
#include <vector>
#include <cstdlib>  // äëÿ std::rand è std::srand
#include <ctime>    // äëÿ std::time

void shuffArr(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);  // Ãåíåðàöèÿ ñëó÷àéíîãî èíäåêñà j
        std::swap(arr[i], arr[j]);      // Îáìåí ýëåìåíòîâ arr[i] è arr[j]
    }
    // Âûâîä ïåðåìåøàííîãî ìàññèâà
    std::cout << "Ïåðåìåøàííûé ìàññèâ: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Èíèöèàëèçàöèÿ ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë
    std::vector<int> arr = { 1, 100, 10, 2 };
    shuffArr(arr);
    return 0;
}
