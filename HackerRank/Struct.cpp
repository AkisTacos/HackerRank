// Aki Saito
// HackerRank - Easy
// Structs
// April 10, 2019
// Language: C++
// 
/* Description:
    
    struct is a way to combine multiple fields to represent a composite data structure, 
    which further lays the foundation for Object Oriented Programming. For example, 
    we can store details related to a student in a struct consisting of his age (int), 
    first_name (string), last_name (string) and standard (int). 

    You have to create a struct, named Student, representing the student's details,
    as mentioned above, and store the data of a student.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/
struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
