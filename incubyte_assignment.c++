#include <bits/stdc++.h>
#pragma region 
using namespace std;
#define sync                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }

class StringCalculator
{
public:
    StringCalculator() {}
    int Add(string numbers)
    {
        int n = numbers.size();
        // 1. String is Empty
        if (numbers.size() == 0)
            return 0;
        // 2. If string is like this (1, \n);
        if (numbers.find(", \n") != string::npos || numbers.find("\n, ") != string::npos)
        {
            throw invalid_argument("This input is not good.");
        }
        // 3. If String is like this (1\n,2);
        else if (numbers.find('\n') != string::npos)
        {
            int index = numbers.find('\n');
            numbers.replace(index, 1, ",");
            cout << numbers << endl;
        }

        int sum = 0;

        // Getting number from string and doing addition
        for (int i = 0; i < n; i++)
        {
            if (isdigit(numbers[i]))
            {
                sum += (numbers[i] - '0');
            }
            // If there is negative number
            if (numbers[i] == '-')
                throw invalid_argument("Negative number not allowed");
        }

        return sum;
    }
};
int main()
{
    StringCalculator sc;
    try
    {
        cout << sc.Add("") << endl;
        cout << sc.Add("1") << endl;
        cout << sc.Add("1,2") << endl;
        cout << sc.Add("Testing") << endl;
        cout << sc.Add("-443") << endl;
        cout << sc.Add("1\n,2") << endl;
        cout << sc.Add("1, \n") << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        return -1;
    }
    return 0;
}
