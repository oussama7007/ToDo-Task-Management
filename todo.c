#include <stdio.h>

#define max 300

struct todo
{
    char taskName[max];
    char deadline[max];
    char status[max];
};

void    add_task()
{
    int choice;
    printf("how many task you wanna add ?\n");
    scanf("%d", &choice );
    for (int i = 0 ; i < choice ; i++)
    {
        printf 
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