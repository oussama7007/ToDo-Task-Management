#include <stdio.h>
#define min 100
#define max 300 

struct date
{
    int jour;
    int mois;
    int annee;
};


struct todo
{
    char Name[min];
    struct date deadline ;
    int id;
    char status[min];
    char description [min];

};

int task_number = 0;
struct todo tasks[max];

void    add_task()
{
    int choice;
    printf("how many task you wanna add ?\n");
    scanf("%d", &choice );
    for (int i = 0 ; i < choice ; i++)
    {
        char task[max]; 
        printf("please enter your task's name number %d :", task_number + 1);
        scanf(" %[^\n]", task );
        strcpy(tasks[task_number].Name, task);

        printf("Enter deadline (day):");
        scanf("%d",&tasks[task_number].deadline.jour);
        printf("enter deadline (mounth):");
        scanf(" %d",&tasks[task_number].deadline.mois);
        printf("Enter deadline (year):");
        scanf("%d",&tasks[task_number].deadline.annee);

        printf("enter the task ID {} :");
        scanf("%d",&tasks[task_number].id);
        

        printf("Enter task status :");
        scanf(" %[^\n]", tasks[task_number].status);

        printf("Enter task description :");
        scanf(" %[^\n]",tasks[task_number].description);
        
        printf("\nyour task has added successfully ...");   
        task_number ++;
    }
}
void    display_tasks()
{
    for(int i = 0; i < task_number; i++)
    {
        printf("\nTask %d:\n", tasks[i].id);
        printf("Name: %s\n", tasks[i].Name);
        printf("Deadline: %02d/%02d/%04d\n", tasks[i].deadline.jour, tasks[i].deadline.mois, tasks[i].deadline.annee);
        printf("Status: %s\n", tasks[i].status);
        printf("Description: %s\n", tasks[i].description);
    }
}
void edit_task() {
    int id;
    printf("Enter the task ID to edit: ");
    scanf("%d", &id);

    // Search for the task by ID
    int found = -1;
    for (int i = 0; i < task_number; i++) {
        if (tasks[i].id == id) {
            found = i;
            break;
        }
    }

    // If task is not found
    if (found == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    // Edit menu
    int choice;
    printf("What would you like to edit for Task %d?\n", id);
    printf("1. Edit task description\n");
    printf("2. Change task status\n");
    printf("3. Modify task deadline\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
        // Edit task description
        printf("Enter the new description: ");
        scanf(" %[^\n]", tasks[found].description);  // scanf with format to read the full line
        printf("Task description updated successfully.\n");
        break;
    }
    case 2: {
        // Change task status
        printf("Enter the new status: ");
        scanf(" %[^\n]", tasks[found].status);  // scanf with format to read the full line
        printf("Task status updated successfully.\n");
        break;
    }
    case 3: {
        // Modify task deadline
        printf("Enter new deadline (day): ");
        scanf("%d", &tasks[found].deadline.jour);
        printf("Enter new deadline (month): ");
        scanf("%d", &tasks[found].deadline.mois);
        printf("Enter new deadline (year): ");
        scanf("%d", &tasks[found].deadline.annee);
        printf("Task deadline updated successfully.\n");
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }
}
void delete_task()
{
    int id;
    printf("Enter the task ID to delete: ");
    scanf("%d", &id);

    // Search for the task by ID
    int found = -1;
    for (int i = 0; i < task_number; i++) {
        if (tasks[i].id == id) {
            found = i;
            break;
        }
    }

    // If task is not found
    if (found == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    // Shift remaining tasks up by one position
    for (int i = found; i < task_number - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    // Decrease the task number
    task_number--;
    printf("Task with ID %d deleted successfully.\n", id);
}




int main()
{
    int choice;
    while(1)
    {
        printf("welcome to your \"TODO LIST\" \n");
        printf("1.Add a new task\n");
        printf("2.Display the list of all tasks:\n");
        printf("3.Edit a task\n");
        printf("4.Delete a task by identifier\n");
        printf("5.Search for Tasks\n");
        printf("6.Statistics\n");
        printf("7.Quit ..\n");
        printf("please enter your choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_task();
            break;
        case 2:
            display_tasks();
            break;
        case 3:
            edit_task();
            break;
        case 4:
            delete_task();
            break;
        case 5:
            Search_task();
            break;
        case 6:
            Statistics();
            break;
        case 7:
            return;
            break;
        default:
            printf("invalid choice ..");
            break;
        }

    }
}