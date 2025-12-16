#include <stdio.h>
#include <string.h>

struct route {
    int route_id;
    int distance_km;
    float base_price;
    char road_type[30];
    float final_cost;
};
float get_extra_cost(char road_type[]) {
    if (strcmp(road_type, "smooth") == 0) {
        return 2.0;
    }
    if (strcmp(road_type, "rough") == 0) {
        return 5.0;
    }
    if (strcmp(road_type, "hilly") == 0) {
        return 8.0;
    }
    return 3.0;
}
void calc_route_cost(int left_km, float base_price, char road_type[], float *total_cost) {
    if (left_km <= 0) {
        return;
    }
    int take_km = left_km;
    if (take_km > 10) {
        take_km = 10;
    }
    float seg_cost = base_price + get_extra_cost(road_type);
    *total_cost = *total_cost + seg_cost;
    calc_route_cost(left_km - take_km, base_price, road_type, total_cost);
}
int main() {
    struct route rt;

    printf("Enter route id: ");
    scanf("%d", &rt.route_id);

    printf("Enter distance in km: ");
    scanf("%d", &rt.distance_km);

    printf("Enter base price: ");
    scanf("%f", &rt.base_price);

    printf("Enter road type: ");
    scanf("%s", rt.road_type);
    rt.final_cost = 0;
    calc_route_cost(rt.distance_km, rt.base_price, rt.road_type, &rt.final_cost);
    printf("\nRoute ID: %d\n", rt.route_id);
    printf("Distance: %d km\n", rt.distance_km);
    printf("Road Type: %s\n", rt.road_type);
    printf("Total Cost: %.2f\n", rt.final_cost);

    return 0;
}
