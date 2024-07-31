#include <stdio.h> /*FILE definition*/
#include <stddef.h> /*NULL definition*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*strlen*/
#include "serialize.h" /*enum definition*/

typedef struct Arts
{
	float drawing;
	float comp_design;
	float photo;
} arts_t;

typedef struct Techs
{
	float program;
	float account;
	float eco;
} tech_t;

typedef struct Human
{
	float Hebrew;
	float literature;
	float English;
	arts_t ArtCard;
} human_t;

typedef struct Real
{
	float math;
	float chemistry;
	float physics;
	tech_t TechCard;
} real_t;

typedef struct GradesCard
{
	float sports;
	human_t HumanCard;
	real_t RealCard;
} grades_t;

struct StudentCard
{
	char *name;
	char *lastName;
	grades_t StudentGrades;
};

static enum failures SerialArtGrades(FILE *stud_file, arts_t *ArtCard);
static enum failures SerialTechGrades(FILE *stud_file, tech_t *TechCard);
static enum failures SerialHumGrades(FILE *stud_file, human_t *HumanCard);
static enum failures SerializeGrades(FILE *stud_file, stud_card_t *Student1);
static enum failures SerialSportGrade(FILE *stud_file, grades_t *StudentGrades);
static enum failures SerialRealGrades(FILE *stud_file, real_t *RealCard);
static enum failures DeserializeGrades(FILE *stud_file, stud_card_t *Student2);
static enum failures DeserialSportGrade(FILE *stud_file, stud_card_t *Student2);
static enum failures DeserialRealGrades(FILE *stud_file, real_t *RealCard);
static enum failures DeserialTechGrades(FILE *stud_file, tech_t *TechCard);
static enum failures DeserialHumGrades(FILE *stud_file, human_t *HumanCard);
static enum failures DeserialArtGrades(FILE *stud_file, arts_t *ArtCard);


stud_card_t *CreateStudent()
{
	stud_card_t *Student1 = (stud_card_t*)malloc(sizeof(stud_card_t));
	char *name = malloc(16);
	char *last_name = malloc(16);
	if (NULL == Student1)
	{
		return (MALLOC);
	}
	if (NULL == name)
	{
		free(Student1);
		return(MALLOC);
	}
	if (NULL == last_name)
	{
		free(Student1);
		free(name);
		return(MALLOC);
	}
	strcpy(name, "Luba");
	strcpy(last_name, "Steinberg");
	
	Student1->name = name ;
	Student1->lastName = last_name;
	Student1->StudentGrades.sports = 96.5;
	Student1->StudentGrades.HumanCard.Hebrew = 85.6;
	Student1->StudentGrades.HumanCard.literature = 85.3;
	Student1->StudentGrades.HumanCard.English = 95.2;
	Student1->StudentGrades.HumanCard.ArtCard.drawing = 74.3;
	Student1->StudentGrades.HumanCard.ArtCard.comp_design = 81.6;
	Student1->StudentGrades.HumanCard.ArtCard.photo = 89.4;
	Student1->StudentGrades.RealCard.math = 81.8;
	Student1->StudentGrades.RealCard.chemistry = 75.5;
	Student1->StudentGrades.RealCard.physics = 67.1;
	Student1->StudentGrades.RealCard.TechCard.program = 81.8;
	Student1->StudentGrades.RealCard.TechCard.account = 61.8;
	Student1->StudentGrades.RealCard.TechCard.eco = 83.8;
	return (Student1);
}

enum failures CreateStudFile(FILE *file_p, stud_card_t *Student1)
{
	int write_result = 0;
	int fclose_result = 0;
	
	write_result = fwrite(Student1->name, 16, 1, file_p);
	if (!write_result)
	{
		fprintf(stderr,"Error writing into the file");
		return (WRITE);
	}
	write_result = fwrite(Student1->lastName, 16, 1, file_p);
	if (!write_result)
	{
		fprintf(stderr,"Error writing into the file");
		return (WRITE);
	}
	
	SerializeGrades(file_p, Student1);
	
	fclose_result = fclose(file_p);
	if (EOF == fclose_result)
	{
		return (WRITE);
	}
	return(SUCCESS);
}

static enum failures SerializeGrades(FILE *stud_file, stud_card_t *Student1)
{
	SerialSportGrade(stud_file, &(Student1->StudentGrades));
	SerialHumGrades(stud_file, &(Student1->StudentGrades.HumanCard));
	SerialRealGrades(stud_file, &(Student1-> StudentGrades.RealCard));
	
	return (SUCCESS);
}

static enum failures SerialSportGrade(FILE *stud_file, grades_t *StudentGrades)
{
	int write_result = 0;
	
	write_result = fwrite(&(StudentGrades->sports), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	return (SUCCESS);
}

static enum failures SerialHumGrades(FILE *stud_file, human_t *HumanCard)
{
	int write_result = 0;
	
	write_result = fwrite(&(HumanCard->Hebrew), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(HumanCard->literature), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(HumanCard->English), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	SerialArtGrades(stud_file, &(HumanCard->ArtCard));
	return (SUCCESS);
}

static enum failures SerialArtGrades(FILE *stud_file, arts_t *ArtCard)
{
	int write_result = 0;
	
	write_result = fwrite(&(ArtCard->drawing), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(ArtCard->comp_design), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(ArtCard->photo), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	return (SUCCESS);
}

static enum failures SerialRealGrades(FILE *stud_file, real_t *RealCard)
{
	int write_result = 0;
	
	write_result = fwrite(&(RealCard->math), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(RealCard->chemistry), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(RealCard->physics), sizeof(float), 1, stud_file);
	SerialTechGrades(stud_file, &(RealCard->TechCard));
	return (SUCCESS);
}

static enum failures SerialTechGrades(FILE *stud_file, tech_t *TechCard)
{
	int write_result = 0;
	
	write_result = fwrite(&(TechCard->program), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(TechCard->account), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	write_result = fwrite(&(TechCard->eco), sizeof(float), 1, stud_file);
	if (!write_result)
	{
		return (WRITE);
	}
	return (SUCCESS);
}

static enum failures DeserialArtGrades(FILE *stud_file, arts_t *ArtCard)
{
	int fread_result = 0;
	
	fread_result = fread(&(ArtCard->drawing), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	fread_result = fread(&(ArtCard->comp_design), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	fread_result = fread(&(ArtCard->photo), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	return (SUCCESS);
}

static enum failures DeserialHumGrades(FILE *stud_file, human_t *HumanCard)
{
	int fread_result = 0;
	
	fread_result = fread(&(HumanCard->Hebrew), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	
	fread_result = fread(&(HumanCard->literature), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	
	fread_result = fread(&(HumanCard->English), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	
	DeserialArtGrades(stud_file, &(HumanCard->ArtCard));
	return (SUCCESS);
}

static enum failures DeserialTechGrades(FILE *stud_file, tech_t *TechCard)
{
	int fread_result = 0;
	
	fread_result = fread(&(TechCard->program), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (WRITE);
	}
	
	fread_result = fread(&(TechCard->account), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (WRITE);
	}
	
	fread_result = fread(&(TechCard->eco), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (WRITE);
	}
	
	return (SUCCESS);
}

static enum failures DeserialRealGrades(FILE *stud_file, real_t *RealCard)
{
	int fread_result = 0;
	
	fread_result = fread(&(RealCard->math), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	fread_result = fread(&(RealCard->chemistry), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	fread_result = fread(&(RealCard->physics), sizeof(float), 1, stud_file);
	DeserialTechGrades(stud_file, &(RealCard->TechCard));
	return (SUCCESS);
}

static enum failures DeserialSportGrade(FILE *stud_file, stud_card_t *Student2)
{
	int fread_result = 0;
	
	fread_result = fread(&(Student2->StudentGrades.sports), sizeof(float), 1, stud_file);
	if (!fread_result)
	{
		return (READ);
	}
	return (SUCCESS);
}

static enum failures DeserializeGrades(FILE *stud_file, stud_card_t *Student2)
{
	DeserialSportGrade(stud_file, Student2);
	DeserialHumGrades(stud_file, &(Student2->StudentGrades.HumanCard));
	DeserialRealGrades(stud_file, &(Student2->StudentGrades.RealCard));
	printf("%s\n", Student2->name);
	printf("%f\n", Student2->StudentGrades.sports);
	printf("%f\n", Student2->StudentGrades.HumanCard.Hebrew);
	printf("%f\n", Student2->StudentGrades.RealCard.math);
	
	return (SUCCESS);
}

enum failures ReadStudFromFile(FILE *stud_file, stud_card_t **Student2)
{
	stud_card_t *NewStudent = NULL;
	int fread_result;
	char *name = malloc(16);
	char *last_name = malloc(16);
	
	if (NULL == NewStudent)
	{
		return (MALLOC);
	}
	if (NULL == name)
	{
		free(NewStudent);
		return(MALLOC);
	}
	if (NULL == last_name)
	{
		free(NewStudent);
		free(name);
		return(MALLOC);
	}
	
	NewStudent = (stud_card_t *)malloc(sizeof(stud_card_t));
	*Student2 = NewStudent;
	fread_result = fread(name, 16, 1, stud_file);
	if (0 == fread_result)
	{
		printf("Didn't succeed to read the file");
	}
	NewStudent->name = name;
	printf("Name: %s\n", NewStudent->name);
	
	fread_result = fread(last_name, 16, 1, stud_file);
	if (0 == fread_result)
	{
		printf("Didn't succeed to read the file");
	}
	NewStudent->lastName = last_name;
	printf("Name: %s", NewStudent->lastName);
	
	DeserializeGrades(stud_file, NewStudent);
	
	return (SUCCESS);
}



