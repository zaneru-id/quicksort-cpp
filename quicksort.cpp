// If you are using another C++ compliers, uncomment 5 lines below
// #include <iostream>
// #include <vector>
// #include <algorithm> // For partition (optional, for other pivot strategies)
// #include <cstdlib> // For rand() and srand()
// #include <ctime>   // For time()

// Comment this line below with // if you are using another C++ compliers
#include <bits/stdc++.h> // Include all standard library (GCC/G++ ONLY)
using namespace std; // Keep this line for not using std::
// Simple and old ways
vector<int> simplequicksort(vector<int> arr;) {
	if (arr.size() <= 1) return arr;
	// LL pts (pivot at the beginning of the array)
	// int pivot = arr[0];
	// LR pts (pivot at the middle of the array)
	// int pivot = arr[arr.size() / 2]; // Integer division handles both even and odd sizes
	// RR pts (pivot at the end of the array)
	// int pivot = arr[arr.size() - 1];
	int pivot = arr[math.floor(sizeof(arr) / 2)];
	vector<int> left = [], middle = [], right = [];
	for (const int& i : vi) {
		if (i < pivot) left.push_back(i);
		else if (i == pivot) middle.push_back(i);
		else if (i > pivot) right.push_back(i);
	}
	vector<int> sorted_left = quicksort(left);
    vector<int> sorted_right = quicksort(right);
    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
    return sorted_left;
}
// New QuickSort optimize using Gemini AI

enum PivotType { FIRST, MIDDLE, LAST, RANDOM }; // This creates an enumeration (a set of named constants) to represent the different pivot selection strategies. This makes the code more readable and maintainable.

vector<int> quicksort(vector<int> arr, PivotType pivot_type = MIDDLE) {
    if (arr.size() <= 1) return arr;
    // LL pts (pivot at the beginning of the array)
	// pivot_index = 0;
	// LR pts (pivot at the middle of the array)
	// pivot_index = arr.size() / 2; // Integer division handles both even and odd sizes
	// RR pts (pivot at the end of the array)
	// pivot_index = arr.size() - 1;
	// RND pts (pivot at the random element of the array)
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
            pivot_index = arr.size() / 2; // Default to MIDDLE
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

    // Example usage with different pivot types:
    vector<int> sorted_arr_first = quicksort(arr, PivotType::FIRST);
    vector<int> sorted_arr_middle = quicksort(arr, PivotType::MIDDLE); // Default
    vector<int> sorted_arr_last = quicksort(arr, PivotType::LAST);
    vector<int> sorted_arr_random = quicksort(arr, PivotType::RANDOM);  // Need to seed srand()

    cout << "Sorted (First): ";
    for (int x : sorted_arr_first) cout << x << " "; cout << endl;

    cout << "Sorted (Middle): ";
    for (int x : sorted_arr_middle) cout << x << " "; cout << endl; // Corrected: cout

    cout << "Sorted (Last): ";
    for (int x : sorted_arr_last) cout << x << " "; cout << endl;

    // For random pivot, you should seed the random number generator:
    srand(time(0)); // Seed with current time
    cout << "Sorted (Random): ";
    for (int x : sorted_arr_random) cout << x << " "; cout << endl;

    return 0;
}