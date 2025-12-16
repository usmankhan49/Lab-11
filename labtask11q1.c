#include <stdio.h>

struct Building {
    int ID;
    int initialHeight;
    float growthRate;
};

int find_height(int current_height, float growth_rate, int day_number) {
    if (day_number == 0) {
        return current_height;
    }

    int extra_height = current_height * growth_rate;   
    int new_height = current_height + extra_height;

    return find_height(new_height, growth_rate, day_number - 1);
}

int main() {
    struct Building b1;
    struct Building *ptr_building;

    int total_days;
    int final_height;

    ptr_building = &b1;

    printf("enter building id: ");
    scanf("%d", &ptr_building->ID);

    printf("enter initial height: ");
    scanf("%d", &ptr_building->initialHeight);

    printf("enter growth rate (example 0.10 for 10 percent): ");
    scanf("%f", &ptr_building->growthRate);

    printf("enter day number to find height: ");
    scanf("%d", &total_days);

    final_height = find_height(ptr_building->initialHeight,
                               ptr_building->growthRate,
                               total_days);

    printf("\nbuilding id: %d\n", ptr_building->ID);
    printf("height after %d days: %d\n", total_days, final_height);

    return 0;
}

