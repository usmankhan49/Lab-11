#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

struct Student {
    struct Person person;
    int creditHours;
    int perCreditFee;
};

int find_semester_fee(int subject_list[], int index, int total_subjects, int per_credit_fee, int current_fee) {
    if (index == total_subjects) {
        return current_fee;
    }

    int add_amount = per_credit_fee * subject_list[index];
    int new_fee = current_fee + add_amount;

    return find_semester_fee(subject_list, index + 1, total_subjects, per_credit_fee, new_fee);
}

int main() {
    struct Student myStudent;
    struct Student *ptr_student;

    ptr_student = &myStudent;

    int total_subjects;
    int i;
    int final_fee;

    printf("enter student name: ");
    scanf("%s", ptr_student->person.name);

    printf("enter age: ");
    scanf("%d", &ptr_student->person.age);

    printf("enter per credit fee: ");
    scanf("%d", &ptr_student->perCreditFee);

    printf("enter number of subjects: ");
    scanf("%d", &total_subjects);

    int subject_credit[50];

    for (i = 0; i < total_subjects; i++) {
        printf("enter credit hours for subject %d: ", i + 1);
        scanf("%d", &subject_credit[i]);
    }

    final_fee = find_semester_fee(subject_credit, 0,total_subjects, ptr_student->perCreditFee,0);

    printf("\nstudent: %s\n", ptr_student->person.name);
    printf("total semester fee: %d\n", final_fee);

    return 0;
}

