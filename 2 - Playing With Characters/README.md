Objective

This challenge will help you to learn how to take a character, a string and a sentence as input in C.

To take a single character __ch__ as input, you can use scanf("%c", &ch ); and printf("%c", ch) writes a character specified by the argument char to stdout

char ch;
scanf("%c", &ch);
printf("%c", ch);
This piece of code prints the character __ch__.

You can take a string as input in C using scanf(“%s”, s). But, it accepts string only until it finds the first space.

In order to take a line as input, you can use scanf("%[^\n]%*c", s); where __s__ is defined as char s[MAX_LEN] where __MAX_LEN__ is the maximum size of __s__. Here, [] is the scanset character. ^\n stands for taking input until a newline isn't encountered. Then, with this %*c, it reads the newline character and here, the used * indicates that this newline character is discarded.

Note: The statement: scanf("%[^\n]%*c", s); will not work because the last statement will read a newline character, \n, from the previous line. This can be handled in a variety of ways. One way is to use scanf("\n"); before the last statement.

Task

You have to print the character, __ch__, in the first line. Then print __s__ in next line. In the last line print the sentence, __sen__.

Input Format

First, take a character, __ch__ as input.
Then take the string, __s__ as input.
Lastly, take the sentence __sen__ as input.

Output Format

Print three lines of output. The first line prints the character, __ch__.
The second line prints the string, __s__.
The third line prints the sentence, __sen__.

Sample Input 0

C
Language
Welcome To C!!
Sample Output 0

C
Language
Welcome To C!!