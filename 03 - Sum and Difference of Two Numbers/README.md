# 03 - Sum and Difference of Two Numbers

### Objective

The fundamental data types in c are int, float and char. Today, we're discussing int and float data types.

The __printf()__ function prints the given statement to the console. The syntax is __printf("format string",argument_list);__. In the function, if we are using an integer, character, string or float as argument, then in the format string we have to write __%d__ (integer), __%c__ (character), __%s__ (string), __%f__ (float) respectively.

The __scanf()__ function reads the input data from the console. The syntax is __scanf("format string",argument_list);__. For ex: The __scanf("%d",&number)__ statement reads integer number from the console and stores the given value in variable _number_.

To input two integers separated by a space on a single line, the command is __scanf("%d %d", &n, &m)__, where _n_ and _m_ are the two integers.

### Task

Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum:

- Declare 4 variables: two of type int and two of type float.
- Read 2 lines of input from stdin (according to the sequence given in the 'Input Format' section below) and initialize your 4 variables.
- Use the + and - operator to perform the following operations:
  - Print the sum and difference of two int variable on a new line.
  - Print the sum and difference of two float variable rounded to one decimal place on a new line.

### Input Format

The first line contains two integers.
The second line contains two floating point numbers.

### Output Format

Print the sum and difference of both integers separated by a space on the first line, and the sum and difference of both float (scaled to 1 decimal place) separated by a space on the second line.

Sample Input
```
10 4
4.0 2.0
```
Sample Output
```
14 6
6.0 2.0
```
Explanation

When we sum the integers __10__ and __4__, we get the integer __14__. When we subtract the second number __4__ from the first number __10__, we get __6__ as their difference.
When we sum the floating-point numbers __4.0__ and __2.0__, we get __6.0__. When we subtract the second number __2.0__ from the first number __4.0__, we get __2.0__ as their difference.
