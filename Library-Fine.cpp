// Aki Saito
// HackerRank - Easy
// Library Fine
// August 7, 2018
// Language: C++
// 
/* Description:

    Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

    1. If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine = 0).
    
    2. If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, fine = 15 Hackos x (# days late).
    
    3. If the book is returned after the expected return month but still within the same calendar year as the expected return date, the fine = 500 Hackos x (# months late).
    
    4. If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10,000 Hackos.
    
    Charges are based only on the least precise measure of lateness. For example, whether a book is due January 1, 2017 or December 31, 2017, if it is returned January 1, 2018, that is a year late and the fine would be 10,000 Hackos.

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the libraryFine function below.
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    // d1 = return day, m1 = return month, y1 = return year
    // d2 = due day, m2 = return month, y2 = due year
    
    const int day_fine = 15;
    const int month_fine = 500;
    const int year_fine = 10000;
    
    // Returned before due year
    if(y1 < y2)
        return 0;
    // Returned after due year
    if(y1 > y2)
        return year_fine;
    
    // Returned before due month of same year
    if(m1 < m2)
        return 0;
    // Returned after due month of same year
    if(m1 > m2)
        return (month_fine * (m1-m2));
    
    // Returned before due day of same month and year
    if(d1 < d2)
        return 0;
    // Returned after due day of same month and year
    if(d1 > d2)
        return (day_fine * (d1-d2));
    
    // If everything is same
    return 0;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string d1M1Y1_temp;
    getline(cin, d1M1Y1_temp);

    vector<string> d1M1Y1 = split_string(d1M1Y1_temp);

    int d1 = stoi(d1M1Y1[0]);

    int m1 = stoi(d1M1Y1[1]);

    int y1 = stoi(d1M1Y1[2]);

    string d2M2Y2_temp;
    getline(cin, d2M2Y2_temp);

    vector<string> d2M2Y2 = split_string(d2M2Y2_temp);

    int d2 = stoi(d2M2Y2[0]);

    int m2 = stoi(d2M2Y2[1]);

    int y2 = stoi(d2M2Y2[2]);

    int result = libraryFine(d1, m1, y1, d2, m2, y2);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

