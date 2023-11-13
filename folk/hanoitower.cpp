#include <bits/stdc++.h>

using namespace std;

/*
    Let f(n) be a recursive function
        1) Show f(1) works (base case)
        2) Assume f(n - 1) works
        3) Show f(n) works using f(n - 1)
*/

/*
    Given 04 disks and 03 rods, we can break the problem down to:
    - Move first 03 disks on the first rod to the second rod
    - Move the largest disks on the first rod to the third rod
    - Move 03 disks currently locate on the second rod to the third rod

    Given 03 disks and 03 rods, we can break the problem down to:
    - Move first 02 disks on the first rod to the second rod
    - Move the largest disks on the first rod to the third rod
    - Move the 02 disks currently locate on the second rod to the third rod

    Given 02 disks and 03 rods, we can break the problem down to:
    - Move the smaller disk on the first rod to the second rod
    - Move the larger disk on the first rod to the third rod
    - Move the smaller disk on the second rod to third rod

    ...

    Given n disks and 03 rods, we can break it down to:
    - Move first n - 1 disks on the first rod to the second rod (n - 1 disks from I to II)
    - Move the largest disks on the first rod to the third rod (1 disk from I to III)
    - Move the n - 1 disks locate on the second rod to the third to (n - 1 disks from II to III)

    As in more detail and general description:
    - Move first n - 1 disks on the start rod to the auxiliary rod
    - Move the largest disks on the start rod to the end rod
    - Move the n - 1 disks on the auxiliary rod to the end rod
*/

void print(int start, int end) {
    cout << "Moving disk from rod " << start << " to rod " << end << '\n'; 
}

// 1 <= start, end <= 3, start != end, n >= 1
// auxiliary rod will be 6 - (start + end)

void hanoi(int n, int start, int end) {
    int aux = 6 - (start + end);
    
    if (n == 1) { // base case
        print(start, end); 
        return;
    }
    
    hanoi(n - 1, start, aux);
    hanoi(1, start, end);
    hanoi(n - 1, aux, end);
}

int main() {
    hanoi(5, 1, 3);
}