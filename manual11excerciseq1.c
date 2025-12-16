#include <stdio.h>
struct customer {
    char name[50];
    char meter_id[30];
    int consumed_units;
    float final_bill;
};
float find_tax(int units, int tier) {
    if (units <= 0) {
        return 0;
    }
    if (tier == 0) {
        int used_units = units;
        if (used_units > 100) {
            used_units = 100;
        }
        return used_units * 0.05 + find_tax(units - used_units, 1);
    }
    if (tier == 1) {
        int used_units = units;
        if (used_units > 200) {
            used_units = 200;
        }
        return used_units * 0.12 + find_tax(units - used_units, 2);
    }
    return units * 0.18;
}
int main() {
    struct customer cust;
    float base_amount;
    float tax_amount;

    printf("Enter customer name: ");
    scanf("%s", cust.name);
    printf("Enter meter id: ");
    scanf("%s", cust.meter_id);
    printf("Enter consumed units: ");
    scanf("%d", &cust.consumed_units);
    base_amount = cust.consumed_units * 5;
    tax_amount = find_tax(cust.consumed_units, 0);
    cust.final_bill = base_amount + tax_amount;

    printf("\nCustomer Name: %s\n", cust.name);
    printf("Meter ID: %s\n", cust.meter_id);
    printf("Consumed Units: %d\n", cust.consumed_units);
    printf("Base Amount: %.2f\n", base_amount);
    printf("Tax Amount: %.2f\n", tax_amount);
    printf("Final Bill: %.2f\n", cust.final_bill);
    return 0;
}

