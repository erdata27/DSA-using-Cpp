#include <iostream>
using namespace std;
void swap(int &a,int &b){
       int temp=a;
       a=b;
       b=temp;
}

void printArray(int arr[], int n){

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to perform selection sort on an array
void SelectionSort(int arr[], int n) {
    if(n<1) return ;
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted portion of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        swap(arr[i], arr[minIndex]);
    }
}

void BubbleSort(int array[],int n){
    if(n<1) return ;
    for(int i=0;i<n;i++){ // for passes 
        for(int j=0;j<n;j++){//to float heavy elem to top
            if(array[j+1]<array[j]){ // swap adj
                swap(array[j],array[j+1]);
            }
        }
    }
}

void InsertionSort(int array[],int n){
    if(n<1) return;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && array[j]<array[j-1]){
            swap(array[j],array[j-1]);
            j--;
        }
    }
}
void recursiveInsertionSort(int arr[], int n) {
    // Base case: If array size is 1 or smaller, it's already sorted
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the nth element in the sorted part of the array
    int last = arr[n - 1];
    int j = n - 2;

    // Move elements of arr[0..n-1], that are greater than the last element,
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        --j;
    }
    arr[j + 1] = last;
}
void merge(int array[],int const l,int const m,int const r){
      int n1=m-l+1;
      int n2=r-m;
      int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i=0,j=0,k=l;
    //both not empty
     while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++,k++;
        } else {
            array[k] = R[j];
            j++,k++;
        }
    }
    while(i<n1 && j==n2){
           array[k]=L[i];
           i++,k++;
    }
    while(j<n2 && i==n1){
        array[k]=R[j];
        j++,k++;
    }
}


void mergesort(int array[],int const l,int const r){
    if(r-l<1){
        return;
    }
    int mid=l+(r-l)/2;
    mergesort(array,l,mid);
    mergesort(array,mid+1,r);
    merge(array,l,mid,r);
}

void Quicksort(int array[],int l,int r){
          if(r-l<=1) return;
          int pivot=array[l];
          int upper=l+1,lower=l+1;
          for(int i=l+1;i<r;i++){
            if(array[i]>pivot){
                upper++;
            }else{
                swap(array[i],array[lower]);
                upper++,lower++;
            }
          swap(pivot,array[lower-1]);
          lower--;
          //recursive calls 
          Quicksort(array,l,lower);
          Quicksort(array,lower+1,r);
      }
}



int main(){
    int array[8]={64,34,25,5,22,11,90,12};
    int n=sizeof(array)/sizeof(int);
    Quicksort(array,0,n);
    printArray(array,n);
}