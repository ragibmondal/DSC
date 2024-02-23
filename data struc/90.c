#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ToDo
{
    char *buffer;
    int count;
    char *date;
    int completed;
    struct ToDo* next;
} todo;

todo* start = NULL;
const char* FILENAME = "todo_data.txt";

void interface();
void seetodo();
void createtodo();
void deletetodo();
void updatetodo();
void adjustcount();
void markCompleted();
void checkUpcomingTasks();
void checkCompletedTasks();
void checkTasksForDate(const char* targetDate);
void loadTasksFromFile();
void saveTasksToFile();
void cleanupMemory();

int main()
{
    loadTasksFromFile();

    int choice;
    interface();

    while (1)
    {
        system("Color 3F");
        system("cls");
        printf("1. To see your ToDo list\n");
        printf("2. To create new ToDo\n");
        printf("3. To update a ToDo\n");
        printf("4. To delete your ToDo\n");
        printf("5. Exit\n");
        printf("6. Mark a task as completed\n");
        printf("7. To see your upcoming ToDo list\n");
        printf("8. To see your completed ToDo list\n");
        printf("9. To see your ToDo list for a specific date\n");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                seetodo();
                break;
            case 2:
                createtodo();
                break;
            case 3:
                updatetodo();
                break;
            case 4:
                deletetodo();
                break;
            case 5:
                saveTasksToFile(); // Save tasks to file before exiting
                cleanupMemory();
                exit(0);
                break;
            case 6:
                markCompleted();
                break;
            case 7:
                checkUpcomingTasks();
                break;
            case 8:
                checkCompletedTasks();
                break;
            case 9:
            {
                char targetDate[11];
                printf("Enter the date (YYYY-MM-DD): ");
                scanf(" %10s", targetDate);
                checkTasksForDate(targetDate);
            }
            break;
            default:
                printf("\nInvalid Choice :-(\n");
                system("pause");
        }
    }

    return 0;
}

// Function to load tasks from a file
void loadTasksFromFile()
{
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        return; // No data to load
    }

    char line[512]; // Assuming tasks won't exceed 512 characters
    while (fgets(line, sizeof(line), file) != NULL)
    {
        todo* add = (todo*)malloc(sizeof(todo));
        add->completed = 0;

        char date[11];
        int count;
        char buffer[201];  // Changed to a fixed buffer size
        sscanf(line, "%d %d %s %[^\n]", &count, &add->completed, date, buffer);
        add->date = strdup(date);
        add->buffer = strdup(buffer);  // Allocate memory and copy the buffer
        add->count = count;

        if (start == NULL)
        {
            start = add;
            add->next = NULL;
        }
        else
        {
            todo* temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = add;
            add->next = NULL;
        }
    }

    fclose(file);
}

// Function to save tasks to a file
void saveTasksToFile()
{
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    todo* temp = start;
    while (temp != NULL)
    {
        // Check if buffer is empty, and save an empty string if it is
        if (temp->buffer == NULL)
        {
            fprintf(file, "%d %d %s %s\n", temp->count, temp->completed, temp->date, "");
        }
        else
        {
            fprintf(file, "%d %d %s %s\n", temp->count, temp->completed, temp->date, temp->buffer);
        }
        temp = temp->next;
    }

    fclose(file);
}

// Function to release allocated memory
void cleanupMemory()
{
    todo* temp = start;
    while (temp != NULL)
    {
        todo* next = temp->next;
        free(temp->buffer);
        free(temp->date);
        free(temp);
        temp = next;
    }
}

// Function to display a home screen
void interface()
{
    system("color 4F");
    printf("\n\n\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           "WELCOME TO the TODO LIST "
           "     : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\n\n\n\t\t\t\t\t\t\t"
           "\t\t\t       "
           "by Team Voltwise Engineers\n\n\n\n"
           "\n\n\n\t");
    system("pause");
}

// Function to display the TODO list
void seetodo()
{
    system("cls");
    todo* temp = start;
    printf("Here tasks list...\n\n");
    if (start == NULL)
    {
        printf("\n\nEmpty ToDo \n\n");
    }

    while (temp != NULL)
    {
        printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");
}

// Function to create a new TODO item
void createtodo()
{
    char c;
    todo* add, * temp;
    system("cls");

    while (1)
    {
        printf("\nWant to add a new ToDo? Press 'y' for Yes and 'n' for No: ");
        fflush(stdin);
        scanf(" %c", &c);

        if (c == 'n')
        {
            break;
        }
        else
        {
            add = (todo*)malloc(sizeof(todo));
            add->completed = 0; // Initialize completion status to 0 (incomplete)

            printf("Enter the task content: ");
            add->buffer = (char*)malloc(201);
            fflush(stdin);
            scanf(" %200[^\n]", add->buffer);

            printf("Enter the task date (YYYY-MM-DD): ");
            add->date = (char*)malloc(11);
            fflush(stdin);
            scanf(" %10s", add->date);

            if (start == NULL)
            {
                start = add;
                add->count = 1;
                start->next = NULL;
            }
            else
            {
                temp = start;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = add;
                add->count = temp->count + 1;
                add->next = NULL;
            }
        }
    }
    adjustcount();
}

// Function to update a TODO item
void updatetodo()
{
    int taskNumber;
    todo* temp = start;

    system("cls");
    if (temp == NULL)
    {
        printf("List is empty.....\n\n\n");
    }
    else
    {
        system("cls");

        seetodo(); // Display the current tasks

        printf("\nEnter the ToDo number you want to update: ");
        scanf("%d", &taskNumber);
        while (temp != NULL)
        {
            if (temp->count == taskNumber)
            {
                printf("Enter the updated task: ");
                temp->buffer = (char*)malloc(201);
                fflush(stdin);
                scanf(" %200[^\n]", temp->buffer); // Update the task content

                printf("Enter the updated date (YYYY-MM-DD): ");
                temp->date = (char*)malloc(11);
                fflush(stdin);
                scanf(" %10s", temp->date); // Update the date
                break;
            }
            temp = temp->next;
        }
    }

    system("pause");
}

// Function to delete a TODO item
void deletetodo()
{
    system("cls");
    int x;
    todo* del, * temp;

    if (start == NULL)
    {
        printf("\n\nThere is no task for today :-)\n\n\n");
    }
    else
    {
        seetodo(); // Display the current tasks

        printf("Enter the ToDo's number that you want to remove: ");
        scanf("%d", &x);
        del = start;
        temp = start->next;

        while (1)
        {
            if (del->count == x)
            {
                start = start->next;
                free(del->buffer);
                free(del->date);
                free(del);
                adjustcount();
                break;
            }
            if (temp->count == x)
            {
                del->next = temp->next;
                free(temp->buffer);
                free(temp->date);
                free(temp);
                adjustcount();
                break;
            }
            else
            {
                del = temp;
                temp = temp->next;
            }
        }
    }
    system("pause");
}

// Function to adjust the count of TODO items
void adjustcount()
{
    todo* temp = start;
    int i = 1;

    while (temp != NULL)
    {
        temp->count = i;
        i++;
        temp = temp->next;
    }
}

void markCompleted()
{
    int taskNumber;
    todo* temp = start;

    system("cls");
    if (temp == NULL)
    {
        printf("List is empty.....\n\n\n");
    }
    else
    {
        system("cls");

        seetodo(); // Display the current tasks

        printf("\nEnter the ToDo number you want to mark as completed: ");
        scanf("%d", &taskNumber);
        while (temp != NULL)
        {
            if (temp->count == taskNumber)
            {
                temp->completed = 1; // Mark the task as completed
                printf("Task marked as completed.\n");
                break;
            }
            temp = temp->next;
        }
    }

    system("pause");
}

void checkUpcomingTasks()
{
    system("cls");
    todo* temp = start;
    printf("Upcoming tasks...\n\n");

    if (start == NULL)
    {
        printf("No tasks in your ToDo list.\n\n");
    }

    while (temp != NULL)
    {
        if (temp->completed == 0)
        {
            printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
        }
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");
}

void checkCompletedTasks()
{
    system("cls");
    todo* temp = start;
    printf("Completed tasks...\n\n");

    if (start == NULL)
    {
        printf("No tasks in your ToDo list.\n\n");
    }

    while (temp != NULL)
    {
        if (temp->completed == 1)
        {
            printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
        }
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");
}

// Function to check tasks for a specific date
void checkTasksForDate(const char* targetDate)
{
    system("cls");
    todo* temp = start;
    printf("Tasks for %s...\n\n", targetDate);

    if (start == NULL)
    {
        printf("No tasks in your ToDo list.\n\n");
    }

    while (temp != NULL)
    {
        if (strcmp(temp->date, targetDate) == 0)
        {
            printf("%d. %s (Date: %s)\n", temp->count, temp->buffer, temp->date);
        }
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");
}