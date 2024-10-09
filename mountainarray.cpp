#include <iostream>
#include <vector>
using namespace std;

int peakInMountainarray(const vector<int>& input) {
    int lo = 1, hi = input.size() - 2;  // Adjusted bounds to ensure mid has valid neighbors
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (input[mid] > input[mid - 1] && input[mid] > input[mid + 1]) {
            // Found the peak
            return mid;
        } else if (input[mid] > input[mid - 1] && input[mid] < input[mid + 1]) {
            // Ascending part, peak must be on the right
            lo = mid + 1;
        } else {
            // Descending part, peak must be on the left
            hi = mid - 1;
        }
    }
    return -1;  // If no peak found, though the problem guarantees there will be one
}

int main() {
    vector<int> input;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        input.push_back(x);
    }
    cout << peakInMountainarray(input) << endl;
}