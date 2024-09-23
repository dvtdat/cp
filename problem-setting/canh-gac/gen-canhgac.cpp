#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int test_count = opt<int>("test-count");
    int sum_n = opt<int>("sum-n");
    int sum_m = opt<int>("sum-m");

    int min_n = opt<int>("min-n", 1);
    int min_m = opt<int>("min-m", 1);

    int min_value = opt<int>("min-value", 1);
    int max_value = opt<int>("max-value", (int)1e9);

    vector<int> n_list = rnd.partition(test_count, sum_n, min_n);
    vector<int> m_list = rnd.partition(test_count, sum_m, min_m);

    println(test_count);
    for (int test_case = 0; test_case < test_count; ++test_case) {
        int n = n_list[test_case];
        int m = m_list[test_case];

        vector<int> arr_n(n);
        for (int i = 0; i < n; ++i) {
            arr_n[i] = rnd.next(min_value, max_value);
        }

        vector<int> arr_m(m);
        for (int i = 0; i < m; ++i) {
            arr_m[i] = rnd.next(min_value, max_value);
        }

        println(n);
        println(m);
        println(arr_n);
        println(arr_m);
    }
}