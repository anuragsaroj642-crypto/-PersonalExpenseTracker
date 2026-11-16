


#include <stdio.h>
#include <string.h>

int id[100];
char category[100][30];
char date[100][15];
float amount[100];

int count = 0;
int nextId = 1;

// Function to add expense
void addExpense()
{
    if (count >= 100)
    {
        printf("\nExpense storage is full!\n");
        return;
    }

    id[count] = nextId++;

    printf("\nEnter Expense Category: ");
    scanf(" %29[^\n]", category[count]);

    printf("Enter Amount: ");
    scanf("%f", &amount[count]);

    if (amount[count] <= 0)
    {
        printf("\nEnter a valid positive amount!\n");
        nextId--;
        return;
    }

    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %14s", date[count]);

    count++;

    printf("\nExpense Added Successfully!\n");
}

// Function to view all expenses
void viewExpenses()
{
    int i;

    if (count == 0)
    {
        printf("\nNo Expenses Found!\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nExpense ID: %d", id[i]);
        printf("\nCategory: %s", category[i]);
        printf("\nAmount: Rs. %.2f", amount[i]);
        printf("\nDate: %s\n", date[i]);
    }
}

// Function to calculate total expenses
void totalExpenses()
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total = total + amount[i];
    }

    printf("\nTotal Expenses = Rs. %.2f\n", total);
}

// Function to search expense by category
void searchCategory()
{
    char search[30];
    int i, found = 0;

    printf("\nEnter Category to Search: ");
    scanf(" %29[^\n]", search);

    for (i = 0; i < count; i++)
    {
        if (strcmp(category[i], search) == 0)
        {
            printf("\nExpense ID: %d", id[i]);
            printf("\nCategory: %s", category[i]);
            printf("\nAmount: Rs. %.2f", amount[i]);
            printf("\nDate: %s\n", date[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nCategory Not Found!\n");
    }
}

// Function to delete expense
void deleteExpense()
{
    int searchId;
    int i, j, found = 0;

    printf("\nEnter Expense ID to Delete: ");
    scanf("%d", &searchId);

    for (i = 0; i < count; i++)
    {
        if (id[i] == searchId)
        {
            for (j = i; j < count - 1; j++)
            {
                id[j] = id[j + 1];
                amount[j] = amount[j + 1];

                strcpy(category[j], category[j + 1]);
                strcpy(date[j], date[j + 1]);
            }

            count--;
            found = 1;

            printf("\nExpense Deleted Successfully!\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nExpense ID Not Found!\n");
    }
}

// Function to display expense summary
void expenseSummary()
{
    int i;
    float total = 0;
    float average;

    if (count == 0)
    {
        printf("\nNo Expenses Available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total = total + amount[i];
    }

    average = total / count;

    printf("\n======= EXPENSE SUMMARY =======\n");
    printf("\nNumber of Expenses: %d", count);
    printf("\nTotal Spending: Rs. %.2f", total);
    printf("\nAverage Expense: Rs. %.2f\n", average);
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n\n================================\n");
        printf("     PERSONAL EXPENSE TRACKER\n");
        printf("================================\n");

        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Search by Category\n");
        printf("5. Delete Expense\n");
        printf("6. Expense Summary\n");
        printf("7. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpenses();
                break;

            case 4:
                searchCategory();
                break;

            case 5:
                deleteExpense();
                break;

            case 6:
                expenseSummary();
                break;

            case 7:
                printf("\nThank You for Using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 7);

    return 0;
}