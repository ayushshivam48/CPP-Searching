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
    vector<int> input {2,4,5,7,15,24,45,50};
    int target=15;
    cout<<binarySearch(input,target)<<endl;
}