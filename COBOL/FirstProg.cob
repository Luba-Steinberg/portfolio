      * A B
       IDENTIFICATION DIVISION.
       PROGRAM-ID. PAYROL00.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *  Variables for the report
       77  WHO         PIC X(15).
       77  WHERE       PIC X(20).
       77  WHY         PIC X(30).
       77  RATE        PIC 9(3).
       77  HOURS       PIC 9(3).
       77  GROSS-RAY   PIC 9(5).

       PROCEDURE DIVISION.
      *COBOL MOVE statements - Literal text to variables
           MOVE "LIBI" TO WHO.
           MOVE "Jerusalem, Israel" TO WHERE.
           MOVE "Works on her COBOL project" TO WHY.
           MOVE 19 TO HOURS.
           MOVE 23 TO RATE.
      * Calculate using COMPUTE reserved word
           COMPUTE GROSS-RAY = HOURS * RATE.
      * DISPPLAY statements
           DISPLAY "Name: " WHO.
           DISPLAY "Location:" WHERE.
           DISPLAY "Reason:" WHY.
           DISPLAY "Hours worked:" HOURS.
           DISPLAY "Hourly rate:" RATE.
           DISPLAY "Gross rate:" GROSS-RAY.
           DISPLAY WHY "from" WHO.
           