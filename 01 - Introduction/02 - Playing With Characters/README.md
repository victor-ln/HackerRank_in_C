# 02 - Playing With Characters

### Objective

This challenge will help you to learn how to take a character, a string and a sentence as input in C. <br>
To take a single character _ch_ as input, you can use __scanf("%c", &ch );__ and __printf("%c", ch)__ writes a character specified by the argument char to stdout
```
char ch;
scanf("%c", &ch);
printf("%c", ch);
```
This piece of code prints the character _ch_.

You can take a string as input in C using __scanf(“%s”, s)__. But, it accepts string only until it finds the first space.

In order to take a line as input, you can use __scanf("%[^\n]%\*c", s);__ where _s_ is defined as __char s[MAX_LEN]__ where _MAX_LEN_ is the maximum size of _s_. Here, __[]__ is the scanset character. __^\n__ stands for taking input until a newline isn't encountered. Then, with this __%*c__, it reads the newline character and here, the used * indicates that this newline character is discarded.

__Note__: The statement: __scanf("%[^\n]%*c", s);__ will not work because the last statement will read a newline character, \n, from the previous line. This can be handled in a variety of ways. One way is to use __scanf("\n");__ before the last statement.

### Task

You have to print the character, __ch__, in the first line. Then print __s__ in next line. In the last line print the sentence, __sen__.

### Input Format

First, take a character, _ch_ as input.<br>
Then take the string, _s_ as input.<br>
Lastly, take the sentence _sen_ as input.<br>

### Output Format

Print three lines of output. The first line prints the character, _ch_.<br>
The second line prints the string, _s_.<br>
The third line prints the sentence, _sen_.<br>

### Sample Input 0
```
C
Language
Welcome To C!!
Sample Output 0
```
### Sample Output 0
```
C
Language
Welcome To C!!
```
