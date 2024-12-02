/******************************
Date: 02.Dec.2024
Author: Harish Natarajan Ravi
Email: harrish.nr@gmail.com
******************************/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* Function to match a pattern against a target string
 * Pattern syntax:
 * '+' : represents a single alphabetic character
 * '*' : represents 3 repeated characters by default
 * '*{N}' : represents N repeated characters
 * Returns "true" if pattern matches, "false" otherwise */

string patternMatching(string str)
{
    // Split input into pattern and string to check
    istringstream iss(str);
    string pattern, checkStr;
    getline(iss, pattern, ' ');
    getline(iss, checkStr);

    // Track current position in pattern and check string
    size_t patternIndex = 0;
    size_t checkIndex = 0;
    
    while (patternIndex < pattern.length() && checkIndex < checkStr.length())
    {

        // Handle '+' : must be a single alphabetic character
        if(pattern[patternIndex] == '+')
        {
            if(!isalpha(checkStr[checkIndex]))
            {
                return "false";
            }
            patternIndex++;
            checkIndex++;
        }
        // Handle '*' : sequence of repeated characters
        else if(pattern[patternIndex] == '*')
        {
            int repeatCount = 3; // Default repeat count is 3

            // Check for custom repeat count with '*{N}'
            if(patternIndex + 1 < pattern.length() && pattern[patternIndex + 1] == '{')
            {
                // Find closing brace and extract repeat count
                size_t closingBrace = pattern.find('}', patternIndex + 1);
                if(closingBrace != string::npos)
                {
                    string numberStr = pattern.substr(patternIndex + 2, closingBrace - (patternIndex + 2));
                    repeatCount = stoi(numberStr);
                    patternIndex = closingBrace + 1;
                }
            }
            else
            {
                patternIndex++;
            }
            
            // Ensure enough characters left in check string
            if(checkIndex + repeatCount > checkStr.length())
            {
                return "false";
            }

            // Get first character to compare against
            char firstChar = checkStr[checkIndex];
            
            // Verify all characters in the sequence are the same
            for(int i = 0; i < repeatCount; i++)
            {
                if(checkStr[checkIndex + i] != firstChar)
                {
                    return "false";
                }
            }

            // Move check index past the repeated sequence
            checkIndex += repeatCount;
        }
        else
        {
            // Invalid pattern character
            return "false"; 
        }
    }
    // Ensure entire pattern and check string are consumed
    return (patternIndex == pattern.length() && checkIndex == checkStr.length()) ? "true" : "false";
}

int main(int argc, char* argv[])
{
    // Validate command line arguments
    if (argc < 2) {
        // Provide usage instructions if insufficient arguments
        cout << "Usage: " << argv[0] << " \"pattern target\"" << endl;
        cout << "Examples:" << endl;
        cout << "  " << argv[0] << " \"++* hello\"" << endl;
        cout << "  " << argv[0] << " \"++*{5} gheeeee\"" << endl;
        return 1;
    }
    
    // Combine all command line arguments into a single input string
    string input;
    for (int i = 1; i < argc; ++i) {
        input += string(argv[i]) + " ";
    }
    input.pop_back(); // Remove trailing space
    
    // Perform pattern matching and output result
    cout << "Pattern Match is: " <<patternMatching(input) << endl;
    
    return 0;
}