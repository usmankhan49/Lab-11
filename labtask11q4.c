#include <stdio.h>
#include <stdlib.h>

struct WeatherData {
    char cityName[50];
    int baseTemp;
    int coolingFactor;
};

int find_temperature(int current_temp, int cooling_factor, int day_number) {
    if (day_number == 0) {
        return current_temp;
    }

    int random_variation = (rand() % 7) - 3;  

    int new_temp = current_temp + random_variation - cooling_factor;

    return find_temperature(new_temp, cooling_factor, day_number - 1);
}

int main() {
    struct WeatherData w1;
    struct WeatherData *ptr_weather;

    ptr_weather = &w1;

    int total_days;
    int final_temp;

    srand(5);  
    printf("enter city name: ");
    scanf("%s", ptr_weather->cityName);

    printf("enter base temperature: ");
    scanf("%d", &ptr_weather->baseTemp);

    printf("enter cooling factor: ");
    scanf("%d", &ptr_weather->coolingFactor);

    printf("enter number of days: ");
    scanf("%d", &total_days);

    final_temp = find_temperature(ptr_weather->baseTemp, ptr_weather->coolingFactor, total_days);

    printf("\ncity: %s\n", ptr_weather->cityName);
    printf("predicted temperature after %d days: %d\n", total_days, final_temp);

    return 0;
}

