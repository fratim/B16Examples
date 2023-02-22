// #include <bits/stdc++.h>

#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
void print_array_and_pointers(T arr[], T m, T l, T r){
    int n = 15;
 
    // loop through the array elements
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;   

    for (int i = 0; i < n+1; i++) {
        if (i == m){
            cout <<  'm';
        }
   
        else{
            cout << ' ' << ' ';
        }
    }
    cout << endl;

    for (int i = 0; i < n+1; i++) {
        if (i == l){
            cout << 'l';
        }

        else{
            cout << ' ' << ' ';
        }
    }
    cout << endl;

    for (int i = 0; i < n+1; i++) {
        if (i == r){
            cout << 'r';
        }
        
        else{
            cout << ' ' << ' ';
        }
    }
    cout << endl;
    cout << endl;


}
 
// template <typename T>
// T binarySearch(T arr[], T l, T r, T x)
// {
//     if (r >= l) {
//         T mid = l + (r - l) / 2;
 
//         if (arr[mid] == x){
//             return mid;
//         }
 
//         else if (arr[mid] > x){
//             return binarySearch(arr, l, mid - 1, x);
//         }

//         else { 
//              return binarySearch(arr, mid + 1, r, x);
//         }
//     }
 
//     return -1;
// }


template <typename T>
T binarySearch(T arr[], T l, T r, T x)
{
    T mid;

    while (l <= r) {
        mid = l + (r - l) / 2;
        print_array_and_pointers(arr, mid, l , r);

        if (arr[mid] == x){
            return mid;
        }
 
        else if (arr[mid] > x){
            r = mid - 1;
        }

        else{
            l = mid +1;
        }        
    }

    print_array_and_pointers(arr, mid, l , r);
    return -1;
}

int main(void)
{
    int arr[] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 4, 5, 6, 7, 8, 9};
    int looking_for = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, looking_for);
    
    if (result != -1) {
        cout << "Element is present at index " << result << endl;        
    }

    else {
        cout << "Element is not present in array" << endl;
    }
    return 0;
}