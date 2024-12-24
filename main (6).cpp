/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm> // для std::reverse
#include <cmath>     // для std::abs
#include <climits>   // для INT_MAX

using namespace std;
//Array46
// Функція для знаходження двох елементів, сума яких найбільш близька до R
void findClosestPair(const vector<int>& arr, int R) {
    int N = arr.size();
    int closestSum = INT_MAX;
    int idx1 = -1, idx2 = -1;

    // Перебір усіх пар
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int sum = arr[i] + arr[j];
            int diff = std::abs(sum - R);

            if (diff < closestSum) {
                closestSum = diff;
                idx1 = i;
                idx2 = j;
            }
        }
    }

    // Виведення пари елементів
    if (idx1 != -1 && idx2 != -1) {
        if (idx1 < idx2) {
            cout << "Closest pair: " << arr[idx1] << ", " << arr[idx2] << endl;
        } else {
            cout << "Closest pair: " << arr[idx2] << ", " << arr[idx1] << endl;
        }
    } else {
        cout << "No valid pair found." << endl;
    }
}

// Функція для реверсу елементів між індексами K і L
void reverseSubarray(vector<int>& arr, int K, int L) {
    // Підмасив починається після K і закінчується перед L
    int start = K;     // Елемент AK не включається
    int end = L - 2;   // Елемент AL не включається

    if (start >= end) {
        cout << "Nothing to reverse, invalid range!" << endl;
        return;
    }
//Array73
    // Реверс елементів між індексами start і end
    reverse(arr.begin() + start + 1, arr.begin() + L - 1);
}

int main() {
    // Вхідні дані
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Масив розміру N
    int R = 10;  // Число для задачі з найближчою сумою
    int K = 3;   // Індекс K (1 ≤ K)
    int L = 7;   // Індекс L (L ≤ N)

    // Виводимо початковий масив
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // 1. Знаходимо пару з найближчою до R сумою
    findClosestPair(arr, R);

    // 2. Реверсуємо елементи між K і L
    reverseSubarray(arr, K - 1, L); // K-1 і L для перетворення до індексації з 0

    // Виводимо модифікований масив
    cout << "Modified array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
