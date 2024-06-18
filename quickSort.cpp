#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& v, int low, int high){
    int pivot = v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot && i<high){
            i++;
        }
        while(v[j]>pivot && j>low){
            j--;
        }
        if(i<j)
        swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}

void quickSort(vector<int>& v, int low, int high){
    if(low>=high){
        return;
    }
    int partitionIndex = helper(v,low,high);
    quickSort(v,low,partitionIndex);
    quickSort(v,partitionIndex+1,high);
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        int low=0, high=n-1;
        quickSort(v,low,high);
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}