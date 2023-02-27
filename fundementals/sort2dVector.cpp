/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
  
// An interval has a start
// time and end time
struct Interval {
    int start, end;
};
  
// Compares two intervals
// according to starting times.
bool compareIntervalBegin(vector<int>& i1, vector<int>& i2)
{
    return (i1[0] < i2[0]);
}
bool compareIntervalEnd(vector<int>& i1, vector<int>&  i2)
{
    return (i1[1] > i2[1]);
}
  
int main()
{
    vector<vector<int>> container {{ 2, 1 }, { 3, 2 }, { 1, 2 }, { 4, 1 } };
    int n = container.size();
    // sort the intervals in increasing order of
    // end time
    sort(container.begin(), container.begin() + n, compareIntervalBegin);
    
    cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << "[" << container[i][0] << "," << container[i][1]
             << "] ";
 
    
    cout << endl;
    sort(container.begin(), container.begin() + n, compareIntervalEnd);
    
    
  
    cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << "[" << container[i][0] << "," << container[i][1]
             << "] ";
  
    return 0;
}