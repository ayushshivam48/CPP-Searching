#include<iostream>
#include<vector>
using namespace std;

// Function to check if it's possible to distribute chocolates with max 'mid' chocolates per student
bool canDistChoco(vector<int> &arr, int mid, int s) {
    int n = arr.size();
    int studentsReqd = 1;
    int currSum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) {
            return false; // If any chocolate packet is larger than 'mid', it's not possible
        }
        if(currSum + arr[i] > mid) {
            studentsReqd++;
            currSum = arr[i]; // Start new student allocation
            if(studentsReqd > s) return false; // If more students are required than available, return false
        } else {
            currSum += arr[i];
        }
    }
    return true; // If distribution is possible with 'mid' max chocolates
}

// Function to find the minimum maximum chocolates that can be distributed
int distChoco(vector<int> &arr, int s) {
    int n = arr.size();
    int lo = arr[0]; // Minimum chocolates per student can't be less than the largest single packet
    int hi = 0;

    for(int i = 0; i < n; i++) {
        hi += arr[i]; // Maximum chocolates per student could be the sum of all packets
    }

    int ans = -1;

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Correctly compute mid
        if(canDistChoco(arr, mid, s)) {
            ans = mid;
            hi = mid - 1; // Try for a smaller maximum number
        } else {
            lo = mid + 1; // Increase the maximum number
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n); // Initialize vector with size 'n'
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int s;
    cin >> s;
    cout << distChoco(v, s) << endl;
    return 0;
}
