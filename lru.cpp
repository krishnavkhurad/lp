#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    vector<int> pages{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    unordered_map<int, int> mp;
    unordered_set<int> s;
    int page_fault = 0;
    int page_hit = 0;

    for (int i = 0; i < 4; i++)
    {
        s.insert(pages[i]);
        mp[pages[i]]++;
        page_fault++;
    }

    for (int i = 4; i < pages.size(); i++)
    {
        if (mp[pages[i]] == 0)
        {
            int val;
            for (auto it = s.begin(); it != s.end(); it++)
            {
                val = *it;
            }
            s.erase(val);
            s.insert(pages[i]);
            mp[val] = 0;
            mp[pages[i]]++;
            page_fault++;
        }
        else
        {
            s.erase(pages[i]);
            s.insert(pages[i]);
            page_hit++;
        }
    }

    cout << "Total Pages: ";
    for (int i = 0; i < pages.size(); i++)
    {
        cout << pages[i] << " ";
    }
    cout << endl;

    cout << "Frame: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    cout << "Page Fault: " << page_fault << endl;
    cout << "Page Hit: " << page_hit << endl;
}