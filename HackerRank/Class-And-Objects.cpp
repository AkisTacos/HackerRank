// Aki Saito
// HackerRank - Easy
// Class and Objects
// April 9, 2019
// Language: C++
// 
/* Description:
    
    A classs defines a blueprint for an object. We use the same syntax
    to declare objects of a class as we use to declare variables of 
    other basic types. 

    Kristen is a contender for valedictorian of her high school. 
    She wants to know how many students (if any) have scored higher 
    than her in the 5 exams given during this semester.

    Create a class named Student with the following specifications:

        An instance variable named scores to hold a student's 5 exam scores.
        
        A void input() function that reads 5 integers and saves them to scores.
        
        An int calculateTotalScore() function that returns the sum of the student's scores. 

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student{
    private:
        vector<int> scores;
        int total = 0;
    public:
        void input(){
            int input;
            for(int i = 0; i < 5; i++){
                cin >> input;
                scores.push_back(input);
            }
        }
        int calculateTotalScore(){
            int result = 0;
            for (auto it = scores.begin(); it != scores.end(); it++) 
                result = result + *it;
            return result;
        }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
