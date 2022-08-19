# 17 - Students Marks Sum

You are given an array of integers, _`marks`_, denoting the marks scored by students in a class.

- The alternating elements _`marks0`_, _`marks2`_, _`marks4`_ and so on denote the marks of boys.
- Similarly, _`marks1`_, _`marks3`_, _`marks5`_ and so on denote the marks of girls.

The array name, _`marks`_, works as a pointer which stores the base address of that array. In other words, _`marks`_ contains the address where _`marks0`_ is stored in the memory.

For example, let _`marks = [3, 2, 5]`_ and _`marks`_ stores 0x7fff9575c05f. Then, 0x7fff9575c05f is the memory address of _`marks0`_.

**image**

### Function Description

Complete the function, marks_summation in the editor below.

marks_summation has the following parameters:

- int marks[number_of_students]: the marks for each student
- int number_of_students: the size of marks[]
- char gender: either 'g' or 'b'

Returns
- int: the sum of marks for boys if _`gender = b`_, or of marks of girls if _`gender = g`_

### Input Format

- The first line contains `_number_of_students_`, denoting the number of students in the class, hence the number of elements in .
- Each of the `_number_of_students_` subsequent lines contains _`marks i`_.
- The next line contains _`gender`_.

### Sample Input 0
````
3
3
2
5
b
````
### Sample Output 0
````
8
````
### Explanation 0

_`marks`_ = [3, 2, 5] and _`gender = b`_.

So, _`marks0`_ + _`marks2`_ = 3 + 5 = 8.
