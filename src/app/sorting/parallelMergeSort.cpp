// #include "parallelMergeSort.hpp"

// #include <iostream>
// #include<vector>
// #include <thread>
// #include <bits/stdc++.h>

// using namespace std;


// ParallelMergeSort::ParallelMergeSort(vector<int>*nums ) : nums(nums){

// }


// ParallelMergeSort::~ParallelMergeSort(){}

// void ParallelMergeSort::recursiveSort(int left , int right){



//     if(left >= right){
//         return;
//     }


//     int mid = left + (right - left)/2;

//     thread thread_1([this , left , mid]{this->recursiveSort(left , mid);});
//     thread thread_2([this , mid , right]{this->recursiveSort(mid+1 , right);});
//     thread_1.join();
//     thread_2.join();
    

//     // this->recursiveSort(left , mid );
//     // this-> recursiveSort(mid + 1, right);


//     vector<int> result;

//     int i =  left;
//     int j = mid+1;
//     while(i <= mid && j <= right){
//         if((*nums)[i] <= (*nums)[j]){
//             result.push_back((*nums)[i]);
//             i++;
//         }
//         else{
//             result.push_back((*nums)[j]);
//             j++;
//         }
//     }

//     while(i <= mid){
//         result.push_back((*nums)[i]);
//         i++;
//     }

//     while(j <= right){
//         result.push_back((*nums)[j]);
//         j++;
//     }


//     for(int k = 0; k < (*nums).size(); k++){
//         (*nums)[left+k] = result[k];
//     }


// }


// void ParallelMergeSort::sort(){
//     if((*nums).size() == 0){
//         return;
//     }

//     thread thread_1([this]{this->recursiveSort(0 , (*nums).size() - 1);});
//     thread_1.join();
//     for(int i = 0; i < (*nums).size() ; i++){
//         cout << (*nums)[i] << endl;
//     }

// }


#include "parallelMergeSort.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <pthread.h>

// using namespace std;

// Wrapper for the recursive call to pass to pthread_create
struct ThreadArgs {
    ParallelMergeSort* instance;
    int left;
    int right;
};

void* threadFunction(void* args) {
    ThreadArgs* threadArgs = static_cast<ThreadArgs*>(args);
    threadArgs->instance->recursiveSort(threadArgs->left, threadArgs->right);
    delete threadArgs; // Clean up
    return nullptr;
}

ParallelMergeSort::ParallelMergeSort(std::vector<int>* nums)
    : nums(nums) {}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right) {
    const int THRESHOLD = 8000;

    if (right - left < THRESHOLD) {
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }


    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    pthread_t thread1, thread2;

    // Prepare arguments for threads
    ThreadArgs* args1 = new ThreadArgs{this, left, mid};
    ThreadArgs* args2 = new ThreadArgs{this, mid + 1, right};

    // Create threads
    pthread_create(&thread1, nullptr, threadFunction, args1);
    pthread_create(&thread2, nullptr, threadFunction, args2);

    

    // Join threads
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    // Merge results
    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }
}

void ParallelMergeSort::sort() {
    if ((*nums).size() ==0 ) {
        exit(1);
    }


    pthread_t thread1;
    int n = (*nums).size();
    // Prepare arguments for threads
    ThreadArgs* args1 = new ThreadArgs{this, 0 , n - 1};
    pthread_create(&thread1, nullptr, threadFunction, args1);
    pthread_join(thread1, nullptr);
}
