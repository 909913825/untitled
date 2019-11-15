#include <iostream>
#include <string>
#include "SortTestHelper.h"
#include "Student.h"
using namespace std;
//将函数声明为模版函数 函数类型名叫T
template <typename T>
void selectionSort(T arr[],int n){
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j ++ ){
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
template <typename T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++ ){
        //寻找当前arr[i]合适的插入位置
        for (int j = i; j > 0; j --) {
            if (arr[j] < arr[j - 1])
                swap(arr[j],arr[j - 1]);
            else
                break;
        }
    }
}
template <typename T>
void insertionSortPlus(T arr[], int n){
    for (int i = 1; i < n; i++ ){
        //寻找当前arr[i]合适的插入位置
        T e = arr[i];
        int j; //保存元素e应该插入的位置
        for ( j = i; j > 0 && arr[j - 1] > e; j-- ){
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}
int main(){
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr4 = SortTestHelper::generateNearlyOrderArray(n,100);
    //int n = 4;
    //Student arr[4] = {{"D",4},{"C",100},{"B",95},{"A",95}};

//    selectionSort(arr, n);
//    SortTestHelper::printArray(arr , n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("SelectionSort",selectionSort,arr,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr2,n);
    SortTestHelper::testSort("insertionSortPlus",insertionSortPlus,arr3,n);
    // 由于generateRandomArray方法中使用new开辟来数组空间 所以要使用delete[]释放

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    return 0;
}