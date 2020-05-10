#include <iostream>
#include <string>
#include <sstream>  
#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.hpp"

using namespace std;

int main() {

    // TEST CASE A
    // input array = {1, 2, 3};
    // n = 2
    cout << "\n\nTEST CASE A:\ninput array = {1, 2, 3}\nn=2" << endl; 
    int original_size0 = 3;
    int original_vc0[] = {1, 2, 3};
    LinkedList L0;
    L0.loadList(original_vc0, original_size0);
    
    L0.removeNthFromEnd(2);

    cout << "Result: " << endl;
    L0.printList();

    cout << "Expected result:\n1 -> 3 -> NULL" << endl;
    L0.~LinkedList();

    // TEST CASE B
    // input array = {1, 2, 3};
    // n = 1
    cout << "\n\nTEST CASE B:\ninput array = {1, 2, 3}\nn=1" << endl; 
    int original_size1 = 3;
    int original_vc1[] = {1, 2, 3};
    L0.loadList(original_vc1, original_size1);
    
    L0.removeNthFromEnd(1);

    cout << "Result: " << endl;
    L0.printList();

    cout << "Expected result:\n1 -> 2 -> NULL" << endl;
    L0.~LinkedList();

    L0.~LinkedList();

    // TEST CASE C
    // input array = {0, 1, 2, 3};
    // n = 4
    cout << "\n\nTEST CASE C:\ninput array = {0, 1, 2, 3}\nn=4" << endl; 
    int original_size2 = 4;
    int original_vc2[] = {0, 1, 2, 3};
    L0.loadList(original_vc2, original_size2);
    
    L0.removeNthFromEnd(4);

    cout << "Result: " << endl;
    L0.printList();

    cout << "Expected result:\n1 -> 2 -> 3 -> NULL" << endl;
    L0.~LinkedList();

    L0.~LinkedList();

    // TEST CASE D
    // input array = {1};
    // n = 4
    cout << "\n\nTEST CASE D:\ninput array = {1}\nn=1" << endl; 
    int original_size3 = 1;
    int original_vc3[] = {1};
    L0.loadList(original_vc3, original_size3);
    
    L0.removeNthFromEnd(1);

    cout << "Result: " << endl;
    L0.printList();

    cout << "Expected result:\nNULL" << endl;
    L0.~LinkedList();

    L0.~LinkedList();

    // TEST CASE E
    // input array = {1};
    // n = 4
    cout << "\n\nTEST CASE E:\ninput array = {0, 1, 2, 3, 4, 5}\nn=3" << endl; 
    int original_size4 = 6;
    int original_vc4[] = {0, 1, 2, 3, 4, 5};
    L0.loadList(original_vc4, original_size4);
    
    L0.removeNthFromEnd(3);

    cout << "Result: " << endl;
    L0.printList();

    cout << "Expected result:\n0 -> 1 -> 2 -> 4 -> 5 -> NULL" << endl;
    L0.~LinkedList();

    L0.~LinkedList();
  
    return 0;
}