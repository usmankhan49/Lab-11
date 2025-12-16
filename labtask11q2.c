#include <stdio.h>

struct Loan {
    char customerName[50];
    float loanAmount;
    float interestRate;
    int months;
};

float repay_loan(float current_amount, float interest_rate, float monthly_installment, int month_count) {
    if (current_amount <= 0) {
        return 0;
    }

    float interest_value = current_amount * interest_rate;
    float new_amount = current_amount - monthly_installment + interest_value;

    return repay_loan(new_amount, interest_rate, monthly_installment, month_count + 1);
}

int main() {
    struct Loan myLoan;
    struct Loan *ptr_loan;

    ptr_loan = &myLoan;

    float monthly_installment;
    float final_amount;

    printf("enter customer name: ");
    scanf("%s", ptr_loan->customerName);

    printf("enter loan amount: ");
    scanf("%f", &ptr_loan->loanAmount);

    printf("enter interest rate (example 0.02 for 2 percent): ");
    scanf("%f", &ptr_loan->interestRate);

    printf("enter monthly installment: ");
    scanf("%f", &monthly_installment);

    printf("enter months: ");
    scanf("%d", &ptr_loan->months);

    final_amount = repay_loan(ptr_loan->loanAmount, ptr_loan->interestRate, monthly_installment,0);

    printf("\ncustomer: %s\n", ptr_loan->customerName);
    printf("loan finished. remaining amount: %.2f\n", final_amount);

    return 0;
}

