// Aki Saito
// HackerRank - Easy
// Class
// April 9, 2019
// Language: C++
// 
/* Description:
	
	Classes in C++ are user defined types declared with keyword class that has data 
	and functions . Although classes and structures have the same type of 
	functionality, there are some basic differences. 

	The data members of a class are private by default and the members of a 
	structure are public by default. Along with storing multiple data in a common block, 
	it also assigns some functions (known as methods) to manipulate/access them. 
	It serves as the building block of Object Oriented Programming.
	
	It also has access specifiers, which restrict the access of member elements. 
	The primarily used ones are the following:
	
	public: Public members (variables, methods) can be accessed from anywhere 
	the code is visible.
	
	private: Private members can be accessed only by other member functions, 
	and it can not be accessed outside of class.

	It's a commmon practice to make all variables private, and set/get them using 
	public methods.

	We can store details related to a student in a class consisting of his age (int), 
	first_name (string), last_name (string) and standard (int). 

	You have to create a class, named Student, representing the student's details, 
	as mentioned above, and store the data of a student. Create setter and getter 
	functions for each element; that is, the class should at least have following 
	functions:
	
		get_age, set_age
		get_first_name, set_first_name
		get_last_name, set_last_name
		get_standard, set_standard
	
	Also, you have to create another method to_string() which returns the string 
	consisting of the above elements, separated by a comma(,). 
	You can refer to stringstream for this.

*/

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
        int age;
        int standard;
        string first_name;
        string last_name;
    public:
        void set_age(int a){
            age = a;
        }
        void set_standard(int s){
            standard = s;
        }
        void set_first_name(string fname){
            first_name = fname;
        }
        void set_last_name(string lname){
            last_name = lname;
        }
        int get_age(){
            return age;
        }
        int get_standard(){
            return standard;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        string to_string(){
            string age_string, standard_string;
            stringstream ssAge, ssStand;
            ssAge << age;
            ssStand << standard;
            age_string = ssAge.str();
            standard_string = ssStand.str();
            return (age_string + ',' + first_name + ',' + last_name + ',' + standard_string);
        }
};


int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}



