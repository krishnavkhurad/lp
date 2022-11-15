#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> pages{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    vector<int> frame;
    unordered_set<int> check;
    unordered_set<int> s;
    unordered_map<int, int> mp;

    int page_fault = 0;
    int page_hit = 0;

    for (int i = 0; i < 3; i++)
    {
        s.insert(pages[i]);
        mp[pages[i]]++;
        page_fault++;
    }

    for (int i = 3; i < pages.size(); i++)
    {
        if (s.find(pages[i]) != s.end())
        {
            check.insert(pages[i]);
        }
    }

    for (int i = 3; i < pages.size(); i++)
    {
        if (mp[pages[i]] == 0)
        {
            mp[*check.begin()]--;
            s.erase(*check.begin());
            s.insert(pages[i]);
            page_fault++;
            mp[pages[i]]++;
            check.erase(*check.begin());
            for (int j = i; j < pages.size(); j++)
            {
                if (s.find(pages[j]) != s.end())
                {
                    check.insert(pages[j]);
                }
            }
        }
        else
        {
            page_hit++;
        }
    }

    cout << "set: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Check vector: ";
    for (auto it = check.begin(); it != check.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Page Fault: " << page_fault << endl;
    cout << "Page Hit: " << page_hit << endl;
}