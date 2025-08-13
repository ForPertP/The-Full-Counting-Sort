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


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}
