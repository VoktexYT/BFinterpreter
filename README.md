# Brainfuck Interpreter with Extended Features

This is an advanced Brainfuck interpreter with additional functionalities to enhance the original language. It introduces new operators such as conditional statements, variables, direct ASCII manipulation, and input handling, making Brainfuck more flexible and powerful while maintaining its minimalist nature.

---

## 🧠 bfc++ - Advanced Brainfuck Interpreter
bfc++ is an enhanced Brainfuck interpreter that extends the original language with new features such as conditionals, variables, ASCII manipulation, and improved input handling. It provides a more flexible and structured approach while staying true to Brainfuck's minimalist nature.

## 🚀 Installation
Simply compile the source code using a C++ compiler:

```
g++ -o bfc++ src/*.cpp
```
Or use the precompiled binary if available.

## 📌 Usage
Run a Brainfuck script with:

```
bfc++ <script.bf>
```
Optional Flags:
* --debug → Show each execution step
* --sizem <size> → Set the memory size (default: 10)
* --help Get the mini doc in terminal

## 🔤 Extended Brainfuck Syntax
Symbol	Description<br>
"+"	Increase the value at the current memory cell<br>
"-"	Decrease the value at the current memory cell<br>
">"	Move memory pointer to the right<br>
"<"	Move memory pointer to the left<br>
"["	Start a loop (while current cell != 0)<br>
"]"	End of the loop<br>
"("	Start an if block (if current cell == 0)<br>
")"	End of the if block<br>
"."	Print ASCII character of current cell<br>
":"	Print numeric ASCII value of current cell<br>
","	Get a character from user input (stores its ASCII code)<br>
";"	Get a number from user input (0-255)<br>
"#"	Comment (ignores everything on the line)<br>
"="	Set current cell to max value (255)<br>
"_"	Set current cell to min value (0)<br>
"/"	Convert a character to ASCII and store it (/a → 97)<br>
"@"	Store current cell value in a variable<br>
"$"	Set current cell value to a stored variable<br><br>

## 📝 Example
### All examples are in example/ directory

## Debug mode
```
	+--------------------+
	| Brainfuck Compiler |
	+--------------------+
	H	48 00 00 00 00 00 00 00 00 00 
H	.	48 00 00 00 00 00 00 00 00 00 
	e	65 00 00 00 00 00 00 00 00 00 
e	.	65 00 00 00 00 00 00 00 00 00 
	l	6c 00 00 00 00 00 00 00 00 00 
l	.	6c 00 00 00 00 00 00 00 00 00 
	l	6c 00 00 00 00 00 00 00 00 00 
l	.	6c 00 00 00 00 00 00 00 00 00 
	o	6f 00 00 00 00 00 00 00 00 00 
o	.	6f 00 00 00 00 00 00 00 00 00 
	_	20 00 00 00 00 00 00 00 00 00 
 	.	20 00 00 00 00 00 00 00 00 00 
	W	57 00 00 00 00 00 00 00 00 00 
W	.	57 00 00 00 00 00 00 00 00 00 
	o	6f 00 00 00 00 00 00 00 00 00 
o	.	6f 00 00 00 00 00 00 00 00 00 
	r	72 00 00 00 00 00 00 00 00 00 
r	.	72 00 00 00 00 00 00 00 00 00 
	d	64 00 00 00 00 00 00 00 00 00 
d	.	64 00 00 00 00 00 00 00 00 00 
	!	21 00 00 00 00 00 00 00 00 00 
!	.	21 00 00 00 00 00 00 00 00 00 

	21 00 00 00 00 00 00 00 00 00 
```


## 📜 License
This project is open-source and available under the MIT License.
