#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

// Function to print permutations of string str, 
// out is used to store permutations one by one 

int permute(string str, string out) { 
	static int count = 0;
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 
	    count++;
        cout << count << ":  " << out << endl; 
        return 0; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++) 
    { 
        // Remove first character from str and 
        // add it to out 
        permute(str.substr(1), out + str[0]); 
  
        // Rotate string in a way second character 
        // moves to the beginning. 
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
} 




// Driver code 
int main(int argc, char **argv) 
{ 
	if (argc == 1) {
		cout << "Enter a string to be permuted!" << endl;
		return 1;
	}

    string str = argv[1]; 
    // string str = "ABC"; 
    permute(str, ""); 
    return 0; 
} 

