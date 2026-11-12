# include <stdio.h>

int findMax(int *p, int n){
    int i;
    int max = *p;
    for (i = 1; i < n; i++){
        if (*(p + i) > max){
            max = *(p + i);
        }
    }
    return max;
}

int findMin(int *p, int n){
    int i;
    int min = *p;
    for (i = 1; i < n; i++){
        if (*(p + i) < min){
            min = *(p + i);
        }
    }
    return min;
}

double findAverage(int *p, int n){
    int i;
    int sum = 0;
    for (i = 0; i < n; i++){
        sum += *(p + i);
    }
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg){
    int i;
    int count = 0;
    for (i = 0; i < n; i++){
        if (*(p + i) > avg){
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n){
    int *start = p;
    int *end = p + n - 1;
    int temp;
    while (start < end){
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key){
    int i;
    for (i = 0; i < n; i++){
        if (*(p + i) == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int marks[10];
    int i, max, min, above_avg_count, pass_count = 0, search_key, search_result;
    double avg;

    printf("\nEnter marks for 10 students (0 to 100):\n");
    for (i = 0; i < 10; i++){
        printf("Enter mark for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        if (marks[i] < 0 || marks[i] > 100){
            printf("Invalid mark! Please enter between 0 and 100.\n");
            i--;
            continue;
        }
    }

    printf("\nMarks before reversing:\n");
    for (i = 0; i < 10; i++){
        printf("Student %d : %d\n", i + 1, marks[i]);
    }

    max = findMax(marks, 10);
    min = findMin(marks, 10);
    avg = findAverage(marks, 10);
    above_avg_count = countAbove(marks, 10, avg);

    for (i = 0; i < 10; i++){
        if (marks[i] >= 40){
            pass_count++;
        }
    }

    printf("\nHighest mark : %d\n", max);
    printf("Lowest mark  : %d\n", min);
    printf("Average mark : %.2f\n", avg);
    printf("Students above average : %d\n", above_avg_count);
    printf("Pass count (>= 40)     : %d\n", pass_count);

    printf("\nEnter a mark to search: ");
    scanf("%d", &search_key);
    search_result = searchMark(marks, 10, search_key);
    if (search_result != -1){
        printf("Mark %d found at position %d (Index %d)\n", search_key, search_result + 1, search_result);
    }
    else {
        printf("Mark %d not found in the class results.\n", search_key);
    }

    reverseArray(marks, 10);

    printf("\nMarks after reversing:\n");
    for (i = 0; i < 10; i++){
        printf("Student %d : %d\n", i + 1, marks[i]);
    }

}