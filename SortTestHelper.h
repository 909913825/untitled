//
// Created by 阎懿 on 2019/11/2.
//

#ifndef UNTITLED_SORTTESTHELPER_H
#define UNTITLED_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    //使用int* 是因为返回一个新创建的数组，返回指向这个数组第一个元素的指针
    // 表示有n个元素 范围为[rangL, rangR]
    int* generateRandomArray (int n,int rangL, int rangR){
        assert(rangL <= rangR);
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n ; ++i) {
            //rand()%100 乱数会介於 0~99之间
            arr[i] = rand() % (rangR - rangL + 1) + rangL;
        }
        return arr;
    }
    //生成一个近乎有序的随机数组
    int* generateNearlyOrderArray(int n, int swapTimes){
        int * arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap( arr[posx], arr[posy]);
        }
        return arr;
    }
    template <typename T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //判断排序是否正确
    template <typename T>
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
            return true;
        }
    }

    int* copyIntArray(int a[], int n){
        int* arr = new int[n];
        //原数组的头指针 原数组的尾指针 目的地址
        copy(a, a + n, arr);
        return arr;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr,n));
        cout << sortName <<" : " <<double(endTime - startTime) / CLOCKS_PER_SEC <<" s"<<endl;
        return;
    }
}
#endif //UNTITLED_SORTTESTHELPER_H
