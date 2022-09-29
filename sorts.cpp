#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
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

int main()
{
    vector<int> vec1 = { 43, 5, 123, 94, 359, -23, 2, -1 };

    printVector(vec1);
    bubbleSort(vec1);
    printVector(vec1);

    return EXIT_SUCCESS;
}


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