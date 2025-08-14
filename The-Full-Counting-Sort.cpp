#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */

void countSort(vector<vector<string>> arr)
{
    int n = arr.size();
    vector<vector<string>> buckets(100);

    for (int i = 0; i < n; i++) {
        int key = stoi(arr[i][0]);
        string value = (i < n / 2) ? "-" : arr[i][1];
        buckets[key].push_back(value);
    }

    for (const auto& bucket : buckets) {
        for (const auto& str : bucket) {
            cout << str << " ";
        }
    }
}

void countSort2(vector<vector<string>> arr)
{
    std::multimap<int, string> mm;

    for (int i = 0 ; i < arr.size()/2 ; ++i)
    {
        arr[i][1] = "-";
    }

    for (const auto& s : arr)
    {
        mm.insert(make_pair(stoi(s[0]), s[1]));
    }

    for (const auto& m : mm)
    {
        std::cout << m.second + " ";
    }
}

