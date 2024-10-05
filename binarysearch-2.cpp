#include<bits/stdc++.h>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input, int target){
    //define search space 
    int lo=0; //start of the search space 
    int hi=input.size()-1; // end of the search space
    while (lo<=hi){
        //calculate midpoint for the search space 
        int mid=lo+(hi-lo)/2;//modified mid to tackle overflow
        if(input[mid]==target) return mid;
        else if (input[mid]<target){
            //discard the left of mid
            lo=mid+1;
        }else{
            //discard the right of mid
            hi=mid-1;
        }
    }return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> input;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    int target;
    cin>>target;
    cout<<binarySearch(input,target)<<endl;
}