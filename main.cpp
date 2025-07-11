// # Project-C--Problem-11.5---Heily-Cabrera

/** The following program generates all permutations of the numbers 0, 1, 2, ... , n – 1, without using recursion.

The algorithm uses the fact that the set to be permuted consists of distinct numbers. Thus, you cannot use the same algorithm to compute the permutations of the characters in a string. 
You can, however, use this technique to get all permutations of the character positions and then compute a string whose ith character is s[a[i]]. Use this approach to reimplement the generate_permutations function without recursion. **/

//Programmer: Heily Cabrera
//Tester: Audrey Tapia

// Group Project C //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void swap(int& x, int& y) 
{
    int temp = x;
    x = y;
    y = temp;
}

void reverse(vector<int>& a, int i, int j) 
{
    while (i < j) 
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

bool next_permutation(vector<int>& a)
{
    for (int i = a.size() - 1; i > 0; i--) 
    {
        if (a[i - 1] < a[i]) {
            int j = a.size() - 1;
            while (a[i - 1] >= a[j]) 
            {
                j--;
            }
            swap(a[i - 1], a[j]);
            reverse(a, i, a.size() - 1);
            return true;
        }
    }
    return false;
}

void generate_permutations(const string& s) 
{
    int n = s.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) 
    {
        indices[i] = i;
    }

    set<string> other_perms; 

    do {
        string perm = "";
        for (int i = 0; i < n; i++) 
        {
            perm += s[indices[i]];
        }
        other_perms.insert(perm);
    } 
      while (next_permutation(indices));

    for (const string& p : unique_perms)
      {
        cout << p << endl;
      }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "\nAll unique permutations:\n";
    generate_permutations(s);

    return 0;
}
