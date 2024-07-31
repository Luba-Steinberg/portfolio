#include <stddef.h>
#include <stdio.h>

int main()
{
	size_t members_size = 0, x_size = 0, card_size = 0;
	
	union members
	{
		int i;
		float f;
		double d;
	} Members;
	
	struct x
	{
		int i;
		char c;
		double d;
		short s;
	} My_x;
	
	struct card
	{
		unsigned int suit:2;
		unsigned int face_value: 4;
	} Card;
	
	members_size = sizeof(Members);
	x_size = sizeof(My_x);
	card_size = sizeof(Card);
	printf("Size of members is %lu\n", members_size); /*8 bytes*/
	printf("Size of x is %lu\n", x_size); /*24 bytes*/
	printf("Size of card is %lu\n", card_size); /*4 bytes*/
	return (0);
}
