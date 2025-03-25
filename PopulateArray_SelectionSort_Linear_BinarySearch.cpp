#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

const int ARRAY_SIZE = 1000;

//Function to populate the array with random numbers
void populateArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 1000; //Random numbers between 0 and 9999
    }
}

//Linear Search Function
int linearSearch(int arr[], int size, int key, int &iterations){
    iterations = 0;
    for (int i = 0; i < size; i++){
        iterations++;
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

//Selection sort function
int selectionSort(int arr[], int size){
    int iterations = 0;
    for (int i = 0; i < size -1; i++){
        int minIdx = 1;
        for (int j = i + 1; j < size; j++){
            iterations++;
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    return iterations;
}

//Binary Search Functions
int binarySearch(int arr[], int size, int key, int &iterations){
    int left = 0;
    int right = size -1;
    iterations = 0;

    while(left <= right){
        iterations++;
        int mid = left + (right - left) /2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}


int main(void){
    int array[ARRAY_SIZE];
    srand(time(0));

    //Populate the array with random data
    populateArray(array, ARRAY_SIZE);

    //Select a random search key
    int searchKey = array[rand() % ARRAY_SIZE];

    //Measure and perform linear search
    int linIterations;
    auto start = chrono::high_resolution_clock::now();
    int linResult = linearSearch(array, ARRAY_SIZE, searchKey, linIterations);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> linTime = end - start;

    //Copy the Array for sorting
    int sortedArray[ARRAY_SIZE];
    copy(array, array + ARRAY_SIZE, sortedArray);

    //Measure and perform selection sort
    start = chrono::high_resolution_clock::now();
    int sortIterations = selectionSort(sortedArray, ARRAY_SIZE);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> binTime = end - start;

    //Measure and perform binary search
    int binIterations;
    start = chrono::high_resolution_clock::now();
    int binResult = binarySearch(sortedArray, ARRAY_SIZE, searchKey, binIterations);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> sortTime = end - start;

    //output the results
    cout << "Linear Search: " <<endl;
    cout << " Result: " << linResult <<endl;
    cout <<" Time: " << linTime.count() <<" seconds " <<endl;
    cout <<" Iterations: " << linIterations <<endl <<endl;


    cout << "Selection Sort: " <<endl;
    cout << " Time: " << sortTime.count() << " seconds " <<endl;
    cout << " Iterations: " << sortIterations <<endl <<endl;

    cout << "Binary Search: " <<endl;
    cout << " Result: " << binResult <<endl;
    cout << " Time: " << binTime.count() << " seconds " <<endl;
    cout << " Iterations: " << binIterations <<endl <<endl;

    // lin O (n) 
    // selection 0 (n2)
    // binarysearch (n2)

    return 0;
}