EXPERIMENT 1:

	You are required to create a circuit with an Arduino board, a seven-segment display and a push-button using Arduino Software (IDE).

	When you correctly assembled the circuit, you will need to write a source code to display hexadecimal numbers on seven-segment display. These numbers will start from “0” and increase by “1”, or another integer value we select, when push-button is pressed. Assuming another integer is selected for increment, your program should calculate the next possible integer to show using modulus operation (%), if the next integer value is greater than “f” (15 in decimal).

	To make the increase value dynamic, you are required to define a global variable named “COUNTER_VALUE” at the top of your source code, that will hold the integer value of increment that will be used when when push-button is pressed.

	Example scenarios with different increment values are given below:

For COUNTER_VALUE = 1
seven-segment display:
0→1→2→3→4→5→6→7→8→9→a→b→c→d→e→f→0→…


For COUNTER_VALUE = 2
seven-segment display:
0→2→4→6→8→a→c→e→0→2→4→6→8→a→c→e→0→…


For COUNTER_VALUE = 7
seven-segment display:
0→7→e(14)→
5(21%16)→c(12)→
3(19%16)→a(10)→
1(17%16)→8→f(15)→
6(22%16)→d(13)→… 
EXPERIMENT 2:

	In this experiment, you will use the same circuit as before. Instead of counting numbers, you need to generate random numbers between “0” and “f” and display them on seven-segment display after push-button is pressed. They can be repeating and can include both “0” and “f”.

	An example scenario is given below:

seven-segment display:
0→7→3→a→f→c→2→7→f→a→0→1→3→e→2→5→c→…
