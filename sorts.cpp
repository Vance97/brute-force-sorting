#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>
#include <chrono>
using namespace std;

/* 5.1
@ Function that accepts an integer N, the size of the input, and returns a vector of size N.
@ Where each element is a random integer uniformly drawn from the range 1 to 1000000.
*/

vector<int>InputGenerator(int N){

    //vector to be returned
    vector<int> GeneratedElements;

    for(int i = 1;i<=N;i++){
        int RandomNumber = 1 + (rand() % 1000);
        GeneratedElements.push_back(RandomNumber);
    }

    return GeneratedElements;

}

// 5.2 (a). Selection Sort
void selectionSort(std::vector<int> &arr) {
    // step 1: loop from the beginning of the array to the second to last item
    for (int currentIndex = 0; currentIndex < arr.size() - 1; currentIndex++) {
        // step 2: save a copy of the currentIndex
        int minIndex = currentIndex;
        // step 3: loop through all indexes that proceed the currentIndex
        for (int i = currentIndex + 1; i < arr.size(); i++) {
          /* step 4:  if the value of the index of the current loop is less
                      than the value of the item at minIndex, update minIndex
                      with the new lowest value index */
            if (arr[i] < arr[minIndex]) {
                // update minIndex with the new lowest value index
                minIndex = i;
            }
        }
        // step 5: if minIndex has been updated, swap the values at minIndex and currentIndex
        if (minIndex != currentIndex) {
            int temp = arr[currentIndex];
            arr[currentIndex] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 5.2 (b). Bubble Sort
template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << "; ";
    }
    cout << endl;
}

template<typename T>
void bubbleSort(vector<T> &vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec.at(j) > vec.at(j + 1))
                std::swap(vec.at(j), vec.at(j + 1));
        }
    }
}

// 5.2 (b). Bubble Sort Escape Clause
vector<int> bubbleSortEscapeClause(vector<int> numbers)
{

    int temp;

    int i = numbers.size() - 1;
    bool sorting = true;
    bool swopped;
    while (i >= 1 && sorting == true)
    {
        swopped = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                //swap
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swopped = true;
            }
        }
        if (swopped == false)
        {
            sorting = false;
        }
        else
        {
            i = i - 1;
        }
    }
    return numbers;
}


int main()
{
    vector<int> numbers;

    //clear text file to re-write it each time attempt is re-run
    std::ofstream outfile;
    fstream ofs;
    ofs.open("data.txt", ios::out | ios::trunc);
    ofs.close();
    outfile.open("data.txt", std::ios_base::app);

    //lists to store time data
    list<int> bSort;
    list<int> bSortEsc;
    list<int> sSort;

    //set average runs to 5
    int n_runs = 5;
    vector<int> numbers2;
    int average_time1, average_time2, average_time3;

    //get average of times
    for (int N = 1000; N <= 20000; N += 1000)
    {
        //output what N is so that it is known where algo currently is in running state
        cout << N << endl;
        int total_time1 = 0;
        int total_time2 = 0;
        int total_time3 = 0;
        for (int i = 0; i < n_runs; i++)
        {
            //generate the random number filled vector of size N
            InputGenerator(N);

            //time selection sort
            auto start = chrono::high_resolution_clock::now();
            numbers2 = selectionSort(numbers);
            auto finish = chrono::high_resolution_clock::now();
            int nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            total_time1 = total_time1 + nanoseconds;

            //time bubble sort
            start = chrono::high_resolution_clock::now();
            numbers2 = bubbleSort(numbers);
            finish = chrono::high_resolution_clock::now();
            nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            total_time2 = total_time2 + nanoseconds;

            //time bubble sort with escape clause
            start = chrono::high_resolution_clock::now();
            numbers2 = bubbleSortEscapeClause(numbers);
            finish = chrono::high_resolution_clock::now();
            nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            total_time3 = total_time3 + nanoseconds;
        }
        average_time1 = total_time1 / n_runs;
        sSort.push_back(average_time1);
        average_time2 = total_time2 / n_runs;
        bSort.push_back(average_time2);
        average_time3 = total_time3 / n_runs;
        bSortEsc.push_back(average_time3);
    }

    //display that algo is done
    cout << "done" << endl;

    std::list<int>::iterator it;
    //append to text file
    for (it = sSort.begin(); it != sSort.end(); ++it)
    {
        if (std::prev(sSort.end())==it){
        outfile << *it;
        }else{
         outfile << *it << ",";   
        }
        
    }
    outfile << "\n";
    for (it = bSort.begin(); it != bSort.end(); ++it)
    {
        if (std::prev(bSort.end())==it){
        outfile << *it;
        }else{
         outfile << *it << ",";   
        }
        
    }
    outfile << "\n";
    for (it = bSortEsc.begin(); it != bSortEsc.end(); ++it)
    {
        if (std::prev(bSortEsc.end())==it){
        outfile << *it;
        }else{
         outfile << *it << ",";   
        }
        
    }

    return 0;
}


//Function Bubble Sort Main
// int main()
// {
//     vector<int> vec1 = { 43, 5, 123, 94, 359, -23, 2, -1 };
//     vector<int> vec2;

//     printVector(vec1);
//     vec2 = bubbleSortEscapeClause(vec1);
//     printVector(vec2);

//     return EXIT_SUCCESS;
// }

//Function Bubble Sort Main
// int main()
// {
//     for(int i=1000;i<=20000;i+=1000){
//         vector<int>inputs = InputGenerator(i);
//         selectionSort(inputs);
//         bubbleSort(inputs);
//         BubbleSortEscape(inputs);
//     }

//     return EXIT_SUCCESS;
// }


//Function Selection Sort Main
// int main() {
//     std::vector<int> arr = {12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
//     selectionSort(arr);
//     for (int i; i < arr.size(); i++) {
//         std::cout << arr[i];
//         if (i < arr.size() - 1) std::cout << ", ";
//     }
//     cout<<endl;
// }

//Function Input Generator Main
// int main(){
//     cout<<"Enter the array size"<<endl;
//     int N;
//     cin>>N;
//     vector<int> Result =  InputGenerator(N);
//     for(int Number: Result){
//         cout << Number <<", ";
//     }
//     return 0;
// }