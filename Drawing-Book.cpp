// Aki Saito
// HackerRank - Easy
// Drawing Book
// July 18, 2018
// Language: C++
// 
/* Description:
	Brie’s Drawing teacher asks her class to open their books to a page number. 
	Brie can either start turning pages from the front of the book or from the back of the book. 
	She always turns pages one at a time. When she opens the book, page 1 is always on the right side:

	When she flips page 1, she sees pages 2 and 3. 
	Each page except the last page will always be printed on both sides. 
	The last page may only be printed on the front, given the length of the book. 
	If the book is pages long, and she wants to turn to page p, 
	what is the minimum number of pages she will turn? She can start at the beginning or the end of the book.
	Given n and p, find and print the minimum number of pages Brie must turn in order to arrive at page .

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    // n is the number of pages in the book
    // p is the page we want to reach
    
    int pageTurned = 0;
    // Check if p is 1 or n
        if ((p == 1) || (p == n)) 
            return 0;
      
    // Is n even or odd
    if ((n % 2) == 0){
        // Even number of pages so page n on left side
        
        // Turn page since p is not on beginning or end
        pageTurned += 1;
        
        // Then p is between the first and last page
        // Check if our p is near end or beginning
        double middle = n/2;
        int currentPage;
        int back = 0;
        if (middle >= p) {
            currentPage = 1 + 2;
        } else {
            currentPage = n - 2;
            back = 1;
        }
      
        // Keep turning page until we reach our p
        int pageNotReached = 1;
        
        while(pageNotReached) {
            // Starting from back
            if (back == 1) {
                // Check if we reached page
                if ( (currentPage == p) || (currentPage < p))
                    pageNotReached = false;
                else {
                    currentPage -= 2;
                    pageTurned += 1;                    
                }        
            } else {
            // Starting from front
                // Check if we reached page
                if ( (currentPage == p) || (currentPage > p) ) 
                    pageNotReached = false;
                else {
                    currentPage += 2;
                    pageTurned += 1;
                }
            }
        } // End while    
    } else {
        // Odd number of pages so page n on right side
        
        
        // Check if p is 1 or n
        if ((p == 1) || (p == n) || (p == n-1)) 
            return 0;
        // Turn page since p is not on beginning or end
        pageTurned += 1;
        
        // Then p is between the first and last page
        // Check if our p is near end or beginning
        double middle = (double)n/2.0;
        int currentPage;
        int back = 0;
        cout << "middle: " << middle << endl;
        if (middle > p) {
            currentPage = 1 + 2;
        } else {
            currentPage = n - 3;
            back = 1;
        }
        cout << "currentPage before loop: " << currentPage << endl;
        // Keep turning page until we reach our p
        int pageNotReached = 1;
        
        while(pageNotReached) {
            // Starting from back
            if (back == 1) {
                // Check if we reached page
                if ( (currentPage == p) || (currentPage <= p))
                    pageNotReached = false;
                else {
                    currentPage -= 2;
                    pageTurned += 1;                    
                }        
            } else {
            // Starting from front
                // Check if we reached page
                if ( (currentPage == p) || (currentPage >= p) ) 
                    pageNotReached = false;
                else {
                    currentPage += 2;
                    pageTurned += 1;
                }
            }
        } // End while
    }
    
    return pageTurned;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}




