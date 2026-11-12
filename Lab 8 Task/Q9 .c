# include <stdio.h>

void readMarks(int *m1, int *m2, int *m3){
    printf("Enter mark for subject 1 (0 to 100): ");
    scanf("%d", m1);
    printf("Enter mark for subject 2 (0 to 100): ");
    scanf("%d", m2);
    printf("Enter mark for subject 3 (0 to 100): ");
    scanf("%d", m3);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest){
    *total = m1 + m2 + m3;
    *average = (double)*total / 3.0;

    *highest = m1;
    if (m2 > *highest){
        *highest = m2;
    }
    if (m3 > *highest){
        *highest = m3;
    }

    *lowest = m1;
    if (m2 < *lowest){
        *lowest = m2;
    }
    if (m3 < *lowest){
        *lowest = m3;
    }
}

void swapMarks(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace){
    if (*mark >= 35 && *mark <= 39){
        *mark += grace;
        if (*mark > 40){
            *mark = 40;
        }
    }
}

void findGrade(double avg, char *grade, char *remarks){
    if (avg >= 80){
        *grade = 'A';
        remarks[0] = 'E'; remarks[1] = 'x'; remarks[2] = 'c'; remarks[3] = 'e'; remarks[4] = 'l'; remarks[5] = 'l'; remarks[6] = 'e'; remarks[7] = 'n'; remarks[8] = 't'; remarks[9] = '\0';
    }
    else if (avg >= 60){
        *grade = 'B';
        remarks[0] = 'G'; remarks[1] = 'o'; remarks[2] = 'o'; remarks[3] = 'd'; remarks[4] = '\0';
    }
    else {
        *grade = 'C';
        remarks[0] = 'N'; remarks[1] = 'e'; remarks[2] = 'e'; remarks[3] = 'd'; remarks[4] = 's'; remarks[5] = ' '; remarks[6] = 'I'; remarks[7] = 'm'; remarks[8] = 'p'; remarks[9] = 'r'; remarks[10] = 'o'; remarks[11] = 'v'; remarks[12] = 'e'; remarks[13] = 'm'; remarks[14] = 'e'; remarks[15] = 'n'; remarks[16] = 't'; remarks[17] = '\0';
    }
}

void incrementByValue(int x){
    x = x + 1;
}

void incrementByReference(int *x){
    *x = *x + 1;
}

int main(){
    int i, m1, m2, m3, total, highest, lowest;
    double average;
    char grade, remarks[30];
    int demo_val = 10;

    printf("\nStudent Result Management System\n");

    printf("\n%-10s | %-8s | %-8s | %-8s | %-18s\n", "Student", "Total", "Average", "Grade", "Remarks");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < 5; i++){
        printf("\nStudent %d of 5\n", i + 1);
        readMarks(&m1, &m2, &m3);

        if (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100){
            printf("Invalid marks entered! Please try again.\n");
            i--;
            continue;
        }

        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);

        if (m1 < m2){
            swapMarks(&m1, &m2);
        }
        if (m1 < m3){
            swapMarks(&m1, &m3);
        }
        if (m2 < m3){
            swapMarks(&m2, &m3);
        }

        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);
        findGrade(average, &grade, remarks);

        printf("Student %-2d | %-8d | %-8.2f | %-8c | %-18s\n", i + 1, total, average, grade, remarks);
    }

    printf("\n--- Comparison Demo ---\n");
    printf("Initial value : %d\n", demo_val);
    incrementByValue(demo_val);
    printf("After Value   : %d (unchanged because value is copied locally)\n", demo_val);
    incrementByReference(&demo_val);
    printf("After Pointer : %d (changed because address memory is modified)\n", demo_val);

    /*
     * Pass by value operates on a local copy of the variable in the function stack.
     * Pass by reference (using pointers in C) modifies the actual memory address of the variable in main.
     */
}