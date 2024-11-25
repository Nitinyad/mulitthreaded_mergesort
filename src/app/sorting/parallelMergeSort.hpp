// #ifndef PARALLELMERGESORT_H
// #define PARALLELMERGESORT_H

// #include <vector>
// #include<thread>
// #include<bits/stdc++.h>
// #include<mutex>
// #include<iostream>
// using namespace std;

// class ParallelMergeSort{
//     private:
//         vector<int>*nums;

//     public:
//         ParallelMergeSort(vector<int>*nums);
//         ~ParallelMergeSort();
//         void sort();
//         void recursiveSort(int left ,int right);
// };

// #endif

#ifndef PARALLELMERGESORT_HPP
#define PARALLELMERGESORT_HPP

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class ParallelMergeSort {
private:
    std::vector<int> *nums;

public:
    ParallelMergeSort(std::vector<int> *nums);
    ~ParallelMergeSort();
    void sort();
    void recursiveSort(int left, int right);
};

#endif