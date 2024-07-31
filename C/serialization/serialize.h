enum failures {SUCCESS, OPEN, READ, WRITE, CLOSE, MALLOC};

typedef struct StudentCard stud_card_t;

stud_card_t *CreateStudent();
enum failures CreateStudFile(FILE *file_p, stud_card_t *Student1);
enum failures ReadStudFromFile(FILE *stud_file, stud_card_t **Student2);
