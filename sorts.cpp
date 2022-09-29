#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*
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

int main(){
    cout<<"Enter the array size"<<endl;
    int N;
    cin>>N;
    vector<int> Result =  InputGenerator(N);
    for(int Number: Result){
        cout << Number <<", ";
    }
    return 0;
}