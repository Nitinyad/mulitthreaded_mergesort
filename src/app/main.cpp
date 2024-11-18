#include <iostream>
#include <chrono>
using namespace std;

#include "sorting/mergesort.hpp"
#include "sorting/parallelMergeSort.hpp"


int main(int argc , char *argv[]){
    const int SIZE = 10000000;


    vector<int>nums(SIZE);
    vector<int>nums1(SIZE);

    for(int i = 0 ; i < SIZE ; i++){
        nums[i] = rand()%10000000;
        nums1[i] = nums[i];
    }
    cout << endl;
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = chrono::high_resolution_clock::now();
    mergesort->sort();
    
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> mergeSortDuration = end - start;
    
    cout << "Merge sort algorithm time taken :" << mergeSortDuration.count() << " seconds" << endl;

    delete mergesort;



    ParallelMergeSort *mergesort1 = new ParallelMergeSort(&nums1);
    start = chrono::high_resolution_clock::now();

    mergesort1->sort();
    end = chrono::high_resolution_clock::now();
    mergeSortDuration = end - start;
    cout << "Paralle merge sort algorithm time taken : " << mergeSortDuration.count() << " seconds" << endl;

    delete mergesort1;

}