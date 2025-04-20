#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

//Define Node Structure
struct Node{
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr){}
};

//Define LinkedList class
class LinkedList{
    public:
        Node* head;
        LinkedList() : head(nullptr){}

        void append(int data){
            if(!head){
                head = new Node(data);
            } else{
                Node* temp = head;
                while(temp -> next){
                    temp = temp->next;
                }
                temp->next = new Node(data);
            }
        }

        void selectionSort(){
            Node* temp = head;
            while(temp){
                Node* min = temp;
                Node* r = temp->next;
                while(r){
                    if(r->data < min->data){
                        min = r;
                    }
                    r = r->next;
                }
                swap(temp->data, min->data);
                temp = temp->next;
            }
        }

        void bubleSort(){
            if(!head) return;
            bool swapped;
            Node* ptrl;
            Node* lptr = nullptr;
            do{
                swapped = false;
                ptrl = head;
                while(ptrl->next != lptr){
                    if(ptrl->data > ptrl->next->data){
                        swap(ptrl->data, ptrl->next->data);
                        swapped = true;
                    }
                    ptrl = ptrl->next;
                }
            }while(swapped);
        }

        Node* linearSearch(int key){
            Node* temp = head;
            while(temp){
                if(temp->data == key){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        Node* binarySearch(int key){
            vector<Node*>nodes;
            Node* temp = head;
            while(temp){
                nodes.push_back(temp);
                temp = temp->next;
            }
            int left = 0, right = nodes.size() -1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(nodes[mid]->data == key){
                    return nodes[mid];
                }else if(nodes[mid]->data < key){
                    left = mid + 1;
                }else{
                    right = mid -1;
                }
            }
            return nullptr;
        }

        void printList(){
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void clear(){
            Node* temp;
            while(head){
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        vector<int> toVector(){
            vector<int> vec;
            Node* temp = head;
            while(temp){
                vec.push_back(temp->data);
                temp = temp->next;
            }
            return vec;
        }
};

int main(void){
    const int SIZE = 1000;
    LinkedList list;
    srand(time(nullptr));

    //Populate the list with random values
    for(int i = 0; i < SIZE; ++i){
        list.append(rand() % 10000);//Random values between 0 and 999
    }

    //Display the list after populating it
    cout << "List after populating with random values: \n";
    list.printList();

    //Ask user for a key to search, or randomly selecxt one
    int searchKey;
    cout << "Enter a key to search for (or -1 to randomly select one): ";
    cin >> searchKey;
    if(searchKey == -1){
        searchKey = rand() % 10000;
        cout << "Randomly selected key: " << searchKey <<endl;
    }

    //Perform linear search
    auto start = chrono::high_resolution_clock::now();
    Node* result = list.linearSearch(searchKey);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double>linearSearchTime = end - start;
    cout << "Linear Search Time: " << linearSearchTime.count() <<" seconds\n";

    if(result){
        cout << "Key found using Linear Search. \n";
    }else{
        cout << "Key not found using Linear Search.\n";
    }

    //Perform selection sort and binary search
    list.clear();
    for(int i = 0; i < SIZE; ++i){
        list.append(rand() % 10000);
    }

    start = chrono::high_resolution_clock::now();
    list.selectionSort();
    end = chrono::high_resolution_clock::now();
    chrono::duration<double>binarySearchTimeSelection = end - start;
    cout << "Binary Search Time after Selection Sort: " << binarySearchTimeSelection.count() <<" seconds\n";
    if(result){
        cout << "Key found using Binary Search after Selection Sort.\n";
    }else{
        cout << "Key not found using Binary Search after Selection Sort.\n";
    }

    //Perform bubble sort and binary search
    list.clear();
    for(int i = 0; i < SIZE; ++i){
        list.append(rand() % 10000);
    }

    start = chrono::high_resolution_clock::now();
    list.bubleSort();
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> binarySearchTimeBuble = end - start;
    cout << "Binary Search Time after Buble Sort: " << binarySearchTimeBuble.count() <<" seconds\n";
    if(result){
        cout << "Key found using Binary Search after Buble Sort.\n";
    }else{
        cout << "Key not found using Binary Search after Buble Sort.\n";
    }


    return 0;
}


//Linked list works like array, like a replacement of array, why use Linkedlist rather than array??