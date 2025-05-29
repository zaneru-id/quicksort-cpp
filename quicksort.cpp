#include <bits/stdc++.h> 
using namespace std;

vector<int> simplequicksort(vector<int> arr) {
    if (arr.size() <= 1) return arr;
    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;
    for (const int& i : arr) {
        if (i < pivot) left.push_back(i);
        else if (i == pivot) middle.push_back(i);
        else right.push_back(i);
    }
    vector<int> sorted_left = simplequicksort(left);
    vector<int> sorted_right = simplequicksort(right);
    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
    return sorted_left;
}

enum PivotType { FIRST, MIDDLE, LAST, RANDOM };

vector<int> quicksort(vector<int> arr, PivotType pivot_type = MIDDLE) {
    if (arr.size() <= 1) return arr;

    int pivot_index;
    switch (pivot_type) {
        case FIRST:
            pivot_index = 0;
            break;
        case MIDDLE:
            pivot_index = arr.size() / 2;
            break;
        case LAST:
            pivot_index = arr.size() - 1;
            break;
        case RANDOM:
            pivot_index = rand() % arr.size();
            break;
        default:
            pivot_index = arr.size() / 2;
    }

    int pivot = arr[pivot_index];

    vector<int> left, middle, right;

    for (const int& i : arr) {
        if (i < pivot) left.push_back(i);
        else if (i == pivot) middle.push_back(i);
        else right.push_back(i);
    }

    vector<int> sorted_left = quicksort(left, pivot_type);
    vector<int> sorted_right = quicksort(right, pivot_type);

    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());

    return sorted_left;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 4, 7, 3, 6};

    srand(time(0));

    vector<int> sorted_arr_first = quicksort(arr, FIRST);
    vector<int> sorted_arr_middle = quicksort(arr, MIDDLE);
    vector<int> sorted_arr_last = quicksort(arr, LAST);
    vector<int> sorted_arr_random = quicksort(arr, RANDOM);

    cout << "Sorted (First): ";
    for (int x : sorted_arr_first) cout << x << " ";
    cout << endl;

    cout << "Sorted (Middle): ";
    for (int x : sorted_arr_middle) cout << x << " ";
    cout << endl;

    cout << "Sorted (Last): ";
    for (int x : sorted_arr_last) cout << x << " ";
    cout << endl;

    cout << "Sorted (Random): ";
    for (int x : sorted_arr_random) cout << x << " ";
    cout << endl;

    return 0;
}
