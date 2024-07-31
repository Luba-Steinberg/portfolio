#include <stdlib.h> /*for malloc*/
#include <stdio.h> /*for file*/
#include "serialize.h" /*stud_card_t typedef*/

int main()
{
	char *file_name = "student.txt";
	FILE *stud_file = NULL;
	char first_name[20];
	char lest_name[20];
	float float_sheck;
	float fl_real_check;
	
	stud_card_t *Student1;
	stud_card_t *Student2;
	stud_file = fopen(file_name, "wr");
	if (NULL == stud_file)
	{
		fprintf(stderr,"Error opening the file");
	}
	
	Student1 = CreateStudent();
	CreateStudFile(stud_file, Student1);

	stud_file = fopen(file_name, "r");
	if (NULL == stud_file)
	{
		fprintf(stderr,"Error opening the file");
	}
	
	ReadStudFromFile(stud_file, &Student2);
	
	printf("%s\n", Student2->name);
	printf("%f\n", Student2->StudentGrades.sports);
	printf("%f\n", Student2->StudentGrades.HumanCard.Hebrew);
	printf("%f\n", Student2->StudentGrades.RealCard.math);
	
	fclose(stud_file);
	
	ClearStrings(Student1);
	ClearStrings(Student2);
	return (0);
}
