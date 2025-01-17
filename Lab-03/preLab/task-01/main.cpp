//main.cpp 
#include <iostream>
#include "UnsortedList.cpp" // Include the implementation 

int main() {
    UnsortedList<int> list(0);

    try {
        list.insert(10);
        list.insert(5);
        list.insert(20);
        list.display();  

        list.remove(1);  // Remove element at index 1 (value 5)
        list.display();  

        list.insert(15);
        list.insert(25);
        list.insert(30);  // This will throw an exception as the list is full
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}