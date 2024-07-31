#include <stddef.h>/*size_t*/
#include "word_boundary.h"

int main()
{
	char buffer[20] = "Hello, world!";
	int push_char = '?';
	size_t n = 10;
	char dest[30] = "I am here today";
	
	Memset(buffer, push_char, n);
	MemcpyAligned(dest, buffer, 9);
	MemcpyUnaligned(dest, buffer, 9);
	Memmove(dest, buffer, 9);
	
	return (0);
}

