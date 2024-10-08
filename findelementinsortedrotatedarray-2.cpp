#include <iostream>
#include <vector>
using namespace std;

int binarySearchSortedRotated(vector<int> &input, int target) {
    int lo = 0;
    int hi = input.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (input[mid] == target) return mid;

        // Handle the case where elements are the same
        if (input[lo] == input[mid] && input[mid] == input[hi]) {
            lo++;
            hi--;
        } else if (input[lo] <= input[mid]) { // Left half is sorted
            if (target >= input[lo] && target <= input[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else { // Right half is sorted
            if (target >= input[mid] && target <= input[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    int n;
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int target;
    cin >> target;

    cout << binarySearchSortedRotated(input, target) << endl;

    return 0;
}
