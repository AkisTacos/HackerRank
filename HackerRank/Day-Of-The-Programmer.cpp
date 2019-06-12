// Aki Saito
// HackerRank - Easy
// Day Of The Programmer
// July 18, 2018
// Language: C++
// 
/* Description:
	Marie invented a Time Machine and wants to test it by time-traveling to visit Russia on the 
	Day of the Programmer (the 256th day of the year) during a year in the inclusive 
	range from 1700 to 2700.
	From 1700 to 1917, Russia's official calendar was the Julian calendar; 
	since 1919 they used the Gregorian calendar system. The transition from the 
	Julian to Gregorian calendar system occurred in 1918, when the next day after 
	January 31st was February 14th. This means that in 1918, February 14th was the 32nd day of the year in Russia.
	In both calendar systems, February is the only month with a variable amount of days; it has 29 days during a leap year,
	and 28 days during all other years. In the Julian calendar, leap years are divisible by 4;
	in the Gregorian calendar, leap years are either of the following:
	Divisible by 400.
	Divisible by 4 and not divisible by 100.
	Given a year, y, find the date of the 256th day of that year according to the 
	official Russian calendar during that year. Then print it in the format dd.mm.yyyy, 
	where dd is the two-digit day, mm is the two-digit month, and yyyy is y.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
string solve(int year) {
    // Result variable
    string result = "";
    
    // Check if Julian or Greg
    int julCal = 0;
    if ((1700 <= year) && (year <= 1917)) {
        julCal = 1;
        cout << "Julian \n";
    }
    if (year == 1918){
        return "26.09.1918";
    }

    if (julCal) {
        // Check if year is a leap or not in Greg
        if ((year % 4) == 0) {
            // Leap years are 12.09
            result = "12.09." + to_string(year);
        }
        else{
            // Non leap years are 13.09
            result = "13.09." + to_string(year);
        }
    }
    else {
        // Check if year is a leap or not in Greg
        if (((year % 400) == 0) ||  (((year % 4) == 0) && ((year % 100) != 0))) {
            // Leap years are 12.09
            result = "12.09." + to_string(year);
        }
        else{
            // Non leap years are 13.09
            result = "13.09." + to_string(year);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int year;
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = solve(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

