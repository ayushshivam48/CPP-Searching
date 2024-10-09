#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &input) {
    int n = input.size();
    if (n == 0) return -1;  // Return -1 for empty vector
    
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // Check if mid is a peak element
        if ((mid == 0 || input[mid] > input[mid - 1]) && (mid == n - 1 || input[mid] > input[mid + 1])) {
            return mid;
        }

        // If the element to the right of mid is greater, move to the right side
        if (mid < n - 1 && input[mid] < input[mid + 1]) {
            lo = mid + 1;
        } else {
            // Move to the left side
            hi = mid - 1;
        }
    }
    // If no peak element is found, which theoretically shouldn't happen, return -1
    return -1;
}

int main() {
    vector<int> input;
    int n;
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    int peakIndex = findPeak(input);
    cout << peakIndex << endl;

    return 0;
}