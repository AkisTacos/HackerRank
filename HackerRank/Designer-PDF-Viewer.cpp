// Aki Saito
// HackerRank - Easy
// Designer PDF Viewer
// July 23, 2018
// Language: C++
// 
/* Description:

	When you select a contiguous block of text in a PDF viewer, the selection 
	is highlighted with a blue rectangle. 
	In this PDF viewer, each word is highlighted independently. 
	For example:
		Highlighted Text:
		[abc] [def] [ghi]
	
	In this challenge, you will be given a list of letter heights in the alphabet 
	and a string. Using the letter heights given, determine the area of the rectangle 
	highlight in mm^2 assuming all letters are 1mm wide.

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    // h is the height of each 26 letters
    // word is our given word
    // the char 'a' in ascii is 97
    
    int numOfLetters = word.length();
    int tallestLetter = 0;
    int pos = 0;
    
    // We first figure out the tallest letter in our word
    for(auto c : word){
        pos = int(c) - 97;
        if(h[pos] > tallestLetter)
            tallestLetter = h[pos];
    }
    
    // Return the result
    return (numOfLetters * tallestLetter);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

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

