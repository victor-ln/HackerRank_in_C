You are given an array of integers, __marks__, denoting the marks scored by students in a class.

- The alternating elements __marks0__, __marks2__, __marks4__ and so on denote the marks of boys.
- Similarly, __marks1__, __marks3__, __marks5__ and so on denote the marks of girls.

The array name, __marks__, works as a pointer which stores the base address of that array. In other words, __marks__ contains the address where __marks0__ is stored in the memory.

For example, let __marks = [3, 2, 5]__ and __marks__ stores 0x7fff9575c05f. Then, 0x7fff9575c05f is the memory address of __marks0__.

**image**

Function Description

Complete the function, marks_summation in the editor below.

marks_summation has the following parameters:

- int marks[number_of_students]: the marks for each student
- int number_of_students: the size of marks[]
- char gender: either 'g' or 'b'

Returns
- int: the sum of marks for boys if __gender = b__, or of marks of girls if __gender = g__

Input Format

The first line contains __number_of_students__, denoting the number of students in the class, hence the number of elements in .
Each of the __number_of_students__ subsequent lines contains __marks*i*__.
The next line contains __gender__.

Sample Input 0
``
3
3
2
5
b
``
Sample Output 0
``
8
``
Explanation 0

marks = [3, 2, 5] and gender = b.

So, marks0 + marks2 = 3 + 5 = 8.
