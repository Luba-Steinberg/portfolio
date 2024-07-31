       IDENTIFICATION DIVISION.
       PROGRAM-ID. COBOL-MAIN.
       AUTHOR. LIBI.
       DATE-WRITTEN. JUNE 2, 2024.
       ENVIRONMENT DIVISION.

       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       01  UserName  PIC X(30) VALUE "You".
       01  NUM1      PIC 9 VALUE ZEROS.
       01  NUM2      PIC 9 VALUE ZEROS.
       01  Total     PIC 99 VALUE 0.
       01  SSNum.
       02  SSArea    PIC 999.
       02  SSGroup   PIC 99.
       02  SSSerial  PIC 9999.
       01  PIValue PIC 9(2).9(2) VALUE 3.14.
      
       PROCEDURE DIVISION.
           DISPLAY "What is your name " WITH NO ADVANCING
           ACCEPT UserName
           DISPLAY "Hello " UserName

           MOVE ZERO TO UserName
           DISPLAY UserName
           Display "enter 2 values to sum "
           ACCEPT NUM1
           ACCEPT NUM2
           COMPUTE Total = NUM1 + NUM2
           DISPLAY NUM1 " + " NUM2 " = " Total
           DISPLAY "Enter you social security number: "
           ACCEPT SSNum
           DISPLAY "Area " SSArea
           STOP RUN.

