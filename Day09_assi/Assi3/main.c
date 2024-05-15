//main
//3. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). Compile the program using "gcc" and execute it. No fork(), exec() expected
#include<stdio.h>
#include "circle.h"
#include"square.h"
#include"rectangle.h"

int main()
{
    circle();
	square();
	rectangle();
	return 0;
}
