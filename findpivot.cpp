#include <iostream>
#include <vector>
using namespace std ;
int findPivot(vector <int> a)
{
    int n = a.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        if(start == end) return start;
        //yaha galti hoti hai
        else if((mid-1) >=0 && a[mid] < a[mid - 1]) return mid - 1;
        //yaha galti hoti hai
        else if((mid+1) < n && a[mid] > a[mid + 1]) return mid;
        else if(a[mid] >= a[start])
            start = mid + 1;
        else 
            end = mid - 1;
        mid = start + (end - start)/2;
    }
    return -1;
}
int binarySearch(vector<int> arr, int start, int end, int target)
{
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        if(arr[mid] == target) return mid;
        if(arr[mid] > target) end = mid - 1;
        else start = mid + 1;
        mid = start + (end - start)/2;
    }
    return -1;
}
int main() {    
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector <int> arr(n);
    cout << "Enter elements : " << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int target;
    cout << "Enter target : ";
    cin >> target;
    int pivotIndex = findPivot(arr);
        int ans = -1;
        if(target <= arr[pivotIndex] && target >= arr[0])
            ans = binarySearch(arr, 0, pivotIndex, target);
        else
            ans = binarySearch(arr, pivotIndex+1, n-1, target);
        cout << ans << endl;
    return 0;
}

