#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//Recursive Implementation of Hailstone sequence
void hailstoneRecursive(int n, int &counter){
    counter++;
    if(n == 1){
        return;
    } else if(n % 2 == 0){
        hailstoneRecursive(n/2, counter);
    } else{
        hailstoneRecursive(3 * n + 1, counter);
    }
}

//Iterative implementation of Hailstone sequence
void hailstoneIterative(int n, int &counter){
    counter = 0;
    while(n !=1){
        counter++;
        if (n % 2 == 0){
            n /= 2;
        } else{
            n = 3 * n + 1;
        }
    }
}

int main(void){
    int n = 27; //Example starting number
    int counterRecursive = 0;
    int counterIterative = 0;

    //Measure time for recursive implementation
    auto start = chrono::high_resolution_clock::now();
    hailstoneRecursive(n, counterRecursive);
    auto end = chrono::high_resolution_clock::now();
    auto recursiveTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

    
    //Measure time for iterative implementation
    start = chrono::high_resolution_clock::now();
    hailstoneIterative(n, counterIterative);
    end = chrono::high_resolution_clock::now();
    auto iterativeTime = chrono::duration_cast<chrono::nanoseconds>(end - start);

    //output the results
    cout << "Recursive Hailstone Sequence: " << endl;
    cout << " Steps: " << counterRecursive << endl;
    cout << " Time: " << recursiveTime.count() << " nanoseconds \n\n";

    cout << "Iterative Hailstone Sequence: \n";
    cout << " Steps: " << counterIterative << endl;
    cout << " Time: " << iterativeTime.count() << " nanoseconds \n\n";
}