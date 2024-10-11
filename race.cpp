#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to place 's' students with at least 'mid' distance apart
bool canPlaceStudents(vector<int> &pos, int s, int mid) {
    int studentsReqd = 1;
    int lastPlaced = pos[0];
    
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] - lastPlaced >= mid) {
            studentsReqd++;
            lastPlaced = pos[i];
            if (studentsReqd == s) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the maximum minimum distance
int race(vector<int> &pos, int s) {
    sort(pos.begin(), pos.end()); // Sort positions
    int lo = 1; // Minimum distance cannot be less than 1
    int hi = pos.back() - pos.front(); // Maximum distance between the first and last position
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canPlaceStudents(pos, s, mid)) {
            ans = mid; // Update answer with the current valid distance
            lo = mid + 1; // Try for a larger minimum distance
        } else {
            hi = mid - 1; // Reduce the distance
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> pos(n); // Initialize vector with size 'n'

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    int s;
    cin >> s;

    cout << race(pos, s) << endl;
    return 0;
}
