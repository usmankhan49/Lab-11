#include <stdio.h>

int find_max_tip(int tip_list[], int index, int total_stops) {
    if (index >= total_stops) {
        return 0;
    }

    int take_tip = tip_list[index] + find_max_tip(tip_list, index + 2, total_stops);
    int skip_tip = find_max_tip(tip_list, index + 1, total_stops);

    if (take_tip > skip_tip) {
        return take_tip;
    } else {
        return skip_tip;
    }
}

int main() {
    int total_stops;
    int i;
    int final_tip;

    printf("enter number of delivery stops: ");
    scanf("%d", &total_stops);

    int tip_list[50];

    for (i = 0; i < total_stops; i++) {
        printf("enter tip amount for stop %d: ", i + 1);
        scanf("%d", &tip_list[i]);
    }

    final_tip = find_max_tip(tip_list, 0, total_stops);

    printf("\nmaximum tips rider can collect: %d\n", final_tip);

    return 0;
}

