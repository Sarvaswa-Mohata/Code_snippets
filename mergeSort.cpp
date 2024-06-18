#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int low, int mid, int high){
    int left = low, right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++; 
        }
    }
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }
    return;
}

void mergeSort(vector<int>& v, int low, int high){
    if(low>=high){
        cout<<v[low]<<endl;
        return;
    }
    int mid = (low+high)/2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1,high);
    merge(v,low,mid,high);
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
        mergeSort(v,0,n-1);
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}