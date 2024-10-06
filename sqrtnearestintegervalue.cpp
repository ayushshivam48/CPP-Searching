#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
     int lo=0;
    int hi=x;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid<=x){
        ans=mid;
        lo=mid+1;
        }else{
            hi=mid-1;
        }
    }return ans;
}
int main(){
    int x;
    cin>>x;
    cout<<sqrt(x)<<endl;

}