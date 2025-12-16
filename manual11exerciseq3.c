#include <stdio.h>
#include <string.h>

struct category {
    char category_name[40];
    char department[40];
};

struct product {
    char product_name[50];
    int expiry_days;
    struct category cat;
};

void check_expiry(struct product items[], int total, int index, int limit_days) {
    if (index >= total) {
        return;
    }
    if (items[index].expiry_days <= limit_days) {
        printf("Alert %s expires in %d days in %s department category %s\n",
               items[index].product_name,
               items[index].expiry_days,
               items[index].cat.department,
               items[index].cat.category_name);
    }
    check_expiry(items, total, index + 1, limit_days);
}

int main() {
    int total_items;
    int limit_days;
    int i;

    printf("Enter number of products: ");
    scanf("%d", &total_items);

    struct product items[50];

    for (i = 0; i < total_items; i++) {
        printf("Enter product name: ");
        scanf("%s", items[i].product_name);

        printf("Enter expiry days: ");
        scanf("%d", &items[i].expiry_days);

        printf("Enter category name: ");
        scanf("%s", items[i].cat.category_name);

        printf("Enter department: ");
        scanf("%s", items[i].cat.department);
    }

    printf("Enter day limit: ");
    scanf("%d", &limit_days);

    check_expiry(items, total_items, 0, limit_days);

    return 0;
}
