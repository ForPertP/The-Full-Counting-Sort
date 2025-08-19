import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'countSort' function below.
     *
     * The function accepts 2D_STRING_ARRAY arr as parameter.
     */

    public static void countSort(List<List<String>> arr) {
        int n = arr.size();
        List<List<String>> buckets = new ArrayList<>(100);
        for (int i = 0; i < 100; i++) {
            buckets.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            int key = Integer.parseInt(arr.get(i).get(0));
            String value = (i < n / 2) ? "-" : arr.get(i).get(1);
            buckets.get(key).add(value);
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 100; i++) {
            if (buckets.get(i) != null) {
                for (String str : buckets.get(i)) {
                    result.append(str).append(" ");
                }
            }
        }
        
        System.out.print(result.toString().trim());
    }


    public static void countSort2(List<List<String>> arr) {
        int n = arr.size();
        Map<Integer, List<String>> buckets = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            int key = Integer.parseInt(arr.get(i).get(0));
            String value = (i < n / 2) ? "-" : arr.get(i).get(1);
            
            if (!buckets.containsKey(key)) {
                buckets.put(key, new ArrayList<>());
            }
            
            buckets.get(key).add(value);
        }
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 100; i++) {
            if (buckets.containsKey(i)) {
                for (String str : buckets.get(i)) {
                    result.append(str).append(" ");
                }
            }
        }
        
        System.out.print(result.toString().trim());
    }
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<String>> arr = new ArrayList<>();

        IntStream.range(0, n).forEach(i -> {
            try {
                arr.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        Result.countSort(arr);

        bufferedReader.close();
    }
}
