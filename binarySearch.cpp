#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int start, int end, vector<int> arr, int target) {
    if(start > end)
        return -1;
    
    int mid = start + (end - start)/2;

    if(target == arr[mid])
        return mid;

    else if(target > arr[mid])
        return(mid+1, end, arr, target);
    
    else 
        return(start, mid-1, arr, target); 
}

int BS(vector<int> arr, int target) {
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start <= end) {
        mid = start + (end-start)/2;

        if(target > arr[mid])
            start = mid + 1;
        
        else if(target < arr[mid])
            end = mid - 1;
        
        else
            return mid;
    }
    return -1;
}

int main() {

    return 0;
}