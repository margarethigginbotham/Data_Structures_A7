//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 7                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   April 4, 2018                                      //
//                                                                  //
//   FUNCTION:   Sort numbers using the heapsort technique.         //
//               First builds a heap structure for the number.      //
//               Then retrieves these numbers from the heap in a    //
//               certain order.				            //
//******************************************************************//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////
//                         FUNCTIONS                          //
////////////////////////////////////////////////////////////////

/***************************************************************
void heapify(vector <int>& v, int heap_size, int r, bool(*compar)(int, int))
Use: “heapifies” a tree at the root position
Parameters: 1. vector <int>& v- heap vector
            2. int heap_size- size if the heap in the vector
            3. int r- root of the heap
            4. bool(*compar)(int, int)- compar function
Returns: Nothing
***************************************************************/
void heapify(vector <int>& v, int heap_size, int r, bool(*compar)(int, int)){
  int current;
  int left = (2 * r);
  int right = (2 * r + 1);

  if((left <= heap_size) && (compar(v[left], v[r])))
    current = left;

  else
    current = r;

  if((right <= heap_size - 1) && (compar(v[right], v[current])))
    current = right;

  if(current != r){
    int temp = v[current];
    v[current] = v[r];
    v[r] = temp;

    heapify(v, heap_size, current, compar);
  }

}

/***************************************************************
void build_heap(vector <int>& v, int heap_size, bool(*compar)(int, int))
Use: Constructs a heap with heap_size elements in the vector v
Parameters: 1. vector <int>& v- heap vector
            2. int heap_size- size if the heap in the vector
            3. bool(*compar)(int, int)- compar function
Returns: Nothing
***************************************************************/
void build_heap(vector <int>& v, int heap_size, bool(*compar)(int, int)){
  for(int i = heap_size / 2; i > 0; i--){
    heapify(v, heap_size, i, compar);
  }

}

/***************************************************************
bool less_than(int e1, int e2)
Use: Compares two integers
Parameters: 1. int e1- int
            2. int e2- int
Returns: True if e1 < e2
***************************************************************/
bool less_than(int e1, int e2){
  if(e1 < e2)
    return true;

  else
    return false;
}

/***************************************************************
bool greater_than(int e1, int e2)
Use: Compares two integers
Parameters: 1. int e1- int
            2. int e2- int
Returns: True if e1 > e2
***************************************************************/
bool greater_than(int e1, int e2){
  if(e1 > e2)
    return true;

  else
    return false;
}

/***************************************************************
int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int))
Use: Extracts the root of the heap recorded in v
     Fills the root with the last element of the current heap
Parameters: 1. vector <int>& v- heap vector
            2. int heap_size- size if the heap in the vector
            3. bool(*compar)(int, int)- compar function
Returns: The old root value
***************************************************************/
int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int)){
  int root = v[1];

  v[1] = v[heap_size];
  heap_size--;

  heapify(v, heap_size, 1, compar);

  return root;
}

/***************************************************************
void heap_sort(vector <int>& v, int heap_size, bool(*compar)(int, int))
Use: Implements the heap sort algorithm
Parameters: 1. vector <int>& v- heap vector
            2. int heap_size- size if the heap in the vector
            3. bool(*compar)(int, int)- compar function
Returns: Nothing
***************************************************************/
void heap_sort(vector <int>& v, int heap_size, bool(*compar)(int, int)){
  for(int i = heap_size; i > 1; i--){
    v[i] = extract_heap(v, heap_size, compar);
  }

  reverse(v.begin() + 1, v.end());

}

/***************************************************************
void print_vector(vector <int>& v, int pos, int size)
Use: Displays size number of elements contained in vector v starting at position pos
     It shows 8 elements per line
     Each item occupies 5 spaces
Parameters: 1. vector <int>& v- heap vector
            2. int pos- Starting position
            3. int size- Size of heap
Returns: Nothing
***************************************************************/
void print_vector(vector <int>& v, int pos, int size){
  for(int i = pos; i <= size; i++){
    cout << setw(5) << right << v[i];

    if(i % 8 == 0)
      cout << endl;
  }

  cout << endl;
}

////////////////////////////////////////////////////////////////
//                            MAIN                            //
////////////////////////////////////////////////////////////////

const int HEAP_SIZE = 50;

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
