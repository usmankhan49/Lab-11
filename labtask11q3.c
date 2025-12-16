#include <stdio.h>

struct Patient {
    char name[50];
    int age;
    int healthScore;
};

struct DailyReport {
    int day;
    int scoreChange;
};

int find_final_score(struct DailyReport reports[], int index, int total_days, int current_score) {
    if (index == total_days) {
        return current_score;
    }

    int new_score = current_score + reports[index].scoreChange;

    return find_final_score(reports, index + 1, total_days, new_score);
}

int main() {
    struct Patient p1;
    struct Patient *ptr_patient;

    ptr_patient = &p1;

    int total_days;
    int i;
    int final_score;

    printf("enter patient name: ");
    scanf("%s", ptr_patient->name);

    printf("enter age: ");
    scanf("%d", &ptr_patient->age);

    printf("enter starting health score: ");
    scanf("%d", &ptr_patient->healthScore);

    printf("enter number of days: ");
    scanf("%d", &total_days);

    struct DailyReport reports[50];

    for (i = 0; i < total_days; i++) {
        printf("enter day number: ");
        scanf("%d", &reports[i].day);

        printf("enter score change for day %d: ", reports[i].day);
        scanf("%d", &reports[i].scoreChange);
    }

    final_score = find_final_score(reports, 0, total_days, ptr_patient->healthScore);

    printf("\npatient name: %s\n", ptr_patient->name);
    printf("final health score after %d days: %d\n", total_days, final_score);

    return 0;
}

