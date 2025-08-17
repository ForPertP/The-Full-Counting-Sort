using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'countSort' function below.
     *
     * The function accepts 2D_STRING_ARRAY arr as parameter.
     */

    public static void countSort(List<List<string>> arr)
    {
        int n = arr.Count;
        var buckets = new List<string>[100];
        
        for (int i = 0; i < n; i++)
        {
            int key = int.Parse(arr[i][0]);
            string value = (i < n / 2) ? "-" : arr[i][1];
            
            if (buckets[key] == null)
                buckets[key] = new List<string>();
            
            buckets[key].Add(value);
        }
        
        var result = new StringBuilder();
        for (int i = 0; i < 100; i++)
        {
            if (buckets[i] != null)
            {
                foreach (var str in buckets[i])
                {
                    result.Append(str).Append(" ");
                }
            }
        }
        
        Console.Write(result.ToString().TrimEnd());        
    }


    public static void countSort2(List<List<string>> arr)
    {
        int n = arr.Count;
        var buckets = new Dictionary<int, List<string>>();
        
        for (int i = 0; i < n; i++)
        {
            int key = int.Parse(arr[i][0]);
            string value = (i < n / 2) ? "-" : arr[i][1];
            
            if (!buckets.ContainsKey(key))
                buckets[key] = new List<string>();
            
            buckets[key].Add(value);
        }
        
        var result = new StringBuilder();
        for (int i = 0; i < 100; i++)
        {
            if (buckets.ContainsKey(i))
            {
                foreach (var str in buckets[i])
                {
                    result.Append(str).Append(" ");
                }
            }
        }
        
        Console.Write(result.ToString().TrimEnd());
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<List<string>> arr = new List<List<string>>();

        for (int i = 0; i < n; i++)
        {
            arr.Add(Console.ReadLine().TrimEnd().Split(' ').ToList());
        }

        Result.countSort(arr);
    }
}
