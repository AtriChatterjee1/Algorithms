/*Name :  Atul Kumar
Github username : atul1510
Repositary name : Algorithms
*/
/* Problem Statement: Atul has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Atul can convert ‘0’ into ‘1’ or vice versa.
Your task is to determine the minimum number of operations Atul should perform to make ‘STR’ beautiful.

Time Complexity:- O(n) 
*/
#include<bits/stdc++.h>
using namespace std;
// Method to count minimum number of operations that should perform to make ‘STR’ beautiful.
int Beautiful(string str) 
{
    int m = str.length();        //    iterating over array of all substrings
    int x1 = 0, x2 = 0;
    char s1 = '0', s2 = '1';
    for (int i = 0; i < m; i++) 
    {
        if (str[i] == '1')      // if number of ones,two and zero are equal in a substring
        {
            if (s1 == '0') 
            {
                x1++;
            }
            else {
                x2++;
            }
        }
        else 
        {
            if (s1 == '1') 
            {
                x1++;
            }
            else 
            {
                x2++;
            }
        }
        if (s1 == '1') 
        {
            s1 = '0';
            s2 = '1';
        }
        else 
        {
            s1 = '1';
            s2 = '0';
        }
    }
    return min(x1, x2);
}
int main()           //Main Function
{
    int test;                                    // For Test Cases
    cout<<"Enter total testcases: "<<endl;
    cin>>test;
    while(test--)
    {
        string str;                             // Initalise a string
        cin>>str;
        cout<<Beautiful(str)<<endl;             // Function call
    }
    return 0;
}