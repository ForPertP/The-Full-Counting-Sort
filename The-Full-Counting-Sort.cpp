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
