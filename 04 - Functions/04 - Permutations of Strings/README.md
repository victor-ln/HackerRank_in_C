# 19 - Permutations of Strings

Strings are usually ordered in lexicographical order. That means they are ordered by comparing their leftmost different characters. For example, _`abc < abd`_ because _`c < d`_. Also _`z > yyy`_ because _`z > y`_. If one string is an exact prefix of the other it is lexicographically smaller, e.g., _`gh < ghih`_.

Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order. If two permutations look the same, only print one of them. See the 'note' below for an example.

Complete the function __next_permutation__ which generates the permutations in the described order.

For example, _`s = [ab, bc, cd]`_. The six permutations in correct order are:
````
ab bc cd
ab cd bc
bc ab cd
bc cd ab
cd ab bc
cd bc ab
````
__Note__: There may be two or more of the same string as elements of _`s`_.
For example, _`s = [ab, ab, bc]`_. Only one instance of a permutation where all elements match should be printed. In other words, if `s[0] == s[1]`, then print either `s[0] s[1]` or `s[1] s[0]` but not both.

A three element array having three distinct elements has six permutations as shown above. In this case, there are three matching pairs of permutations where `s[0] = ab` and `s[1] = ab` are switched. We only print the three visibly unique permutations:
````
ab ab bc
ab bc ab
bc ab ab
````
### Input Format

The first line of each test file contains a single integer `n`, the length of the string array `s`.

Each of the next `n` lines contains a string `s[i]`.

### Output Format

Print each permutation as a list of space-separated strings on a single line.

### Sample Input 0
````
2
ab
cd
````
### Sample Output 0
````
ab cd
cd ab
````
### Sample Input 1
````
3
a
bc
bc
````
### Sample Output 1
````
a bc bc
bc a bc
bc bc a
````
### Explanation 1

This is similar to the note above. Only three of the six permutations are printed to avoid redundancy in output.