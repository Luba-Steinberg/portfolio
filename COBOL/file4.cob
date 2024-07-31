       IDENTIFICATION DIVISION.
       PROGRAM-ID. FILE4.
       AUTHOR. LIBI.
       DATE-WRITTEN. JUNE 3, 2024.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       
       PROCEDURE DIVISION.
           GO TO SubOne.
       SubOne.
               DISPLAY "In Paragraph 1"
               PERFORM SubTwo
               DISPLAY "Returned to Paragraph 1"
               PERFORM SubFour 2 TIMES.
               DISPLAY "Repeat"
      *         END-PERFORM.
           STOP RUN.

       SubThree.
               DISPLAY "In Paragraph 3".

       SubTwo.
               DISPLAY "In Paragraph 2"
               PERFORM SubThree
               DISPLAY "Returned to Paragraph 2".

       SubFour.
               DISPLAY "repeat again".
               