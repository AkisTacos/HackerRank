// Aki Saito
// HackerRank - Easy
// Box It!
// April 9, 2019
// Language: C++
// 
/* Description:
    
    Design a class named Box whose dimensions are integers and 
    private to the class. 

    The dimensions are labelled: length l, breadth b, and height h.
    
    The default constructor of the class should initialize l, b, 
    and h to 0.

    The parameterized constructor Box(int length, int breadth, 
    int height) should initialize Box's l, b and h to length, 
    breadth and height.

    The copy constructor BoxBox (Box B) should set l and b
    to B's l, b and h, respectively.

    Apart from the above, the class should have 4 functions:

        - int getLength() - Return box's length

        - int getBreadth() - Return box's breadth

        - int getHeight() - Return box's height

        - long long CalculateVolume() - Return the volume of the box
    
    Overload the operator < for the class Box. Box A < Box B if:

    1. A.l < B.l

    2. A.b < B.b and A.l == B.l

    3. A.h < B.h and A.b == B.b and A.l == B.l

    Overload operator << for the class Box().
    If B is an object of class Box:

    cout << B should print B.l, B.b, and B.h on a single line separated
    by spaces.

*/

#include<bits/stdc++.h>

using namespace std;

class Box{
    private:
        int l, b, h;
    public:
        Box(){
            l = 0;
            b = 0;
            h = 0;
        } // Constructor

        Box(int length, int breadth, int height){
            l = length;
            b = breadth;
            h = height;
        } // Assignment

        Box(const Box& B){
            l = B.l;
            h = B.h;
            b = B.b;
        } // Copy Constructor

        int getLength(){
            return l;
        } // Return box's length

        int getBreadth(){
            return b;
        } // Return box's breadth

        int getHeight(){
            return h;
        } // Return box's height

        long long CalculateVolume(){
            long long volume = l;
            volume *= b;
            volume *= h;
            return volume;
        } // Return the volume of the box

        friend bool operator< (Box& a, Box& B){
            if( (a.l < B.l) || ((a.l == B.l) && (a.b < B.b)) || ((a.h < B.h) && (a.l == B.l) && (a.b == B.b)) )
                return true;
            else
                return false;
        } // Compare both box

        friend ostream& operator<< (ostream& out, Box& B){
            out << B.l << ' ' << B.b << ' ' << B.h;
            return out;
        } // Overload function
};


void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}

