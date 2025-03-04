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
Symbol	Description
+	Increase the value at the current memory cell
-	Decrease the value at the current memory cell
>	Move memory pointer to the right
<	Move memory pointer to the left
[	Start a loop (while current cell != 0)
]	End of the loop
(	Start an if block (if current cell == 0)
)	End of the if block
.	Print ASCII character of current cell
:	Print numeric ASCII value of current cell
,	Get a character from user input (stores its ASCII code)
;	Get a number from user input (0-255)
#	Comment (ignores everything on the line)
=	Set current cell to max value (255)
_	Set current cell to min value (0)
/	Convert a character to ASCII and store it (/a → 97)
@	Store current cell value in a variable
$	Set current cell value to a stored variable

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
