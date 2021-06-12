#include <iostream>

using namespace std;

template <class T>
void insertionSort(T *arr, int n){
    for(int i=1,j ; i<n; i++){
        T temp = arr[i];
        for( j=i; j>0 && arr[j-1]>temp; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

template <class T>
void selectionSort(T *arr, int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j])
                min = j;
        }
        if (min != i) {
            T temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

template <class T>
void bubbleSort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j<n-i; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template <class T>
void merge(T *A,int l,int m, int r){
    const int n1 = m-l+1;
    const int n2 = r-m;
    T L[n1];
    T R[n2];
    for(int i=0; i<n1; i++)
        L[i] = A[i+l];
    for(int j=0; j<n2; j++)
        R[j] = A[j+m+1];

    int i=0,j=0,k=l;
    while (i<n1 && j<n2){
        A[k++]= (L[i]<R[j]? L[i++]:R[j++]);
    }
    while (i<n1 ){
        A[k++]= L[i++];
    }
    while (j<n2){
        A[k++]= R[j++];
    }

}

template <class T>
void mergeSort(T *A, int l, int r){
    if (l >= r)
        return;
    int m=(r+l)/2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A,l,m,r);
}


template <class T>
void quickSort(T *A, int l, int r){
    if (l >= r)
        return;
    int p = l, i = l;
    for(int j=l; j<=r; j++){
        if(A[j] < A[p]){
            i++;
            swap(A[j],A[i]);
        }
    }
    swap(A[p],A[i]);
    p = i;
    quickSort(A, l, p - 1);
    quickSort(A, p + 1, r);
}

void maxHeapify(int arr[], int i, int n) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int max = i;
    if (l <= n && arr[l] > arr[max])
        max = l;
    if (r <= n && arr[r] > arr[max])
        max = r;
    if (max != i) {
        swap(arr[i], arr[max]);
        maxHeapify(arr, max, n);
    }
}

void buildMaxHeap(int arr[], int n){
    for (int i=n/2; i > 0; i--){
        maxHeapify(arr,i,n);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    for (int i=n; i > 1; i--){
        swap(arr[i],arr[1]);
        maxHeapify(arr, 1, i - 1);
    }
}

template <class T>
void swap(T &x,T &y){
    T temp = x;
    x= y;
    y =temp;
}

