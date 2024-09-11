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

void add_task() {
    int choice;
    printf("How many tasks do you want to add? ");
    scanf("%d", &choice);
    
    for (int i = 0; i < choice; i++) {
        // Ensure the task ID is unique
        int id_unique = 0;
        int task_id;
        while (!id_unique) {
            printf("Enter a unique task ID: ");
            scanf("%d", &task_id);

            // Check if the ID is already taken
            id_unique = 1;  // Assume it's unique
            for (int j = 0; j < task_number; j++) {
                if (tasks[j].id == task_id) {
                    printf("Task ID %d is already taken, please enter a unique ID.\n", task_id);
                    id_unique = 0;  // Set to 0 if ID is not unique
                    break;
                }
            }
        }
        tasks[task_number].id = task_id;

        // Task title
        printf("Enter task title: ");
        scanf(" %[^\n]", tasks[task_number].Name);

        // Task description
        printf("Enter task description: ");
        scanf(" %[^\n]", tasks[task_number].description);

        // Deadline
        printf("Enter deadline (day month year): ");
        scanf("%d %d %d", &tasks[task_number].deadline.jour, &tasks[task_number].deadline.mois, &tasks[task_number].deadline.annee);

        // Status (to be completed, in progress, completed)
        int status_choice;
        printf("Select the status of the task:\n");
        printf("1. To be completed\n");
        printf("2. In progress\n");
        printf("3. Completed\n");
        printf("Enter your choice: ");
        scanf("%d", &status_choice);

        switch (status_choice) {
            case 1:
                strcpy(tasks[task_number].status, "To be completed");
                break;
            case 2:
                strcpy(tasks[task_number].status, "In progress");
                break;
            case 3:
                strcpy(tasks[task_number].status, "Completed");
                break;
            default:
                printf("Invalid choice. Defaulting to 'To be completed'.\n");
                strcpy(tasks[task_number].status, "To be completed");
        }

        task_number++;
        printf("\nTask added successfully!\n");
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
void delete_task() {
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

    // Display task information before deletion
    printf("\nTask %d:\n", tasks[found].id);
    printf("Name: %s\n", tasks[found].Name);
    printf("Deadline: %02d/%02d/%04d\n", tasks[found].deadline.jour, tasks[found].deadline.mois, tasks[found].deadline.annee);
    printf("Status: %s\n", tasks[found].status);
    printf("Description: %s\n", tasks[found].description);

    // Ask for confirmation before deleting
    char confirmation;
    printf("\nAre you sure you want to delete this task? (y/n): ");
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        // Shift remaining tasks up by one position
        for (int i = found; i < task_number - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        // Decrease the task number
        task_number--;
        printf("Task with ID %d deleted successfully.\n", id);
    } else {
        printf("Task deletion canceled.\n");
    }
}
void search_task() {
    int search_choice;
    printf("Search by:\n");
    printf("1. Task ID\n");
    printf("2. Task Title\n");
    printf("Enter your choice: ");
    scanf("%d", &search_choice);

    if (search_choice == 1) {
        int id;
        printf("Enter the task ID to search: ");
        scanf("%d", &id);

        int found = -1;
        for (int i = 0; i < task_number; i++) {
            if (tasks[i].id == id) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("Task with ID %d not found.\n", id);
        } else {
            printf("\nTask %d:\n", tasks[found].id);
            printf("Name: %s\n", tasks[found].Name);
            printf("Deadline: %02d/%02d/%04d\n", tasks[found].deadline.jour, tasks[found].deadline.mois, tasks[found].deadline.annee);
            printf("Status: %s\n", tasks[found].status);
            printf("Description: %s\n", tasks[found].description);
        }
    } else if (search_choice == 2) {
        char title[min];
        printf("Enter the task title to search: ");
        getchar();  // Clear buffer
        scanf(" %[^\n]", title);

        int found = -1;
        for (int i = 0; i < task_number; i++) {
            if (strcmp(tasks[i].Name, title) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("Task with title '%s' not found.\n", title);
        } else {
            printf("\nTask %d:\n", tasks[found].id);
            printf("Name: %s\n", tasks[found].Name);
            printf("Deadline: %02d/%02d/%04d\n", tasks[found].deadline.jour, tasks[found].deadline.mois, tasks[found].deadline.annee);
            printf("Status: %s\n", tasks[found].status);
            printf("Description: %s\n", tasks[found].description);
        }
    } else {
        printf("Invalid choice.\n");
    }
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
