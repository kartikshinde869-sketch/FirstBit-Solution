#include <stdio.h>
#include <string.h>

struct Task {
    int id;
    char desc[100];
    char status[20];
};

struct Task tasks[100];
int count = 0;

void addTask() {
    tasks[count].id = count + 1;
    printf("Enter task description: ");
    getchar(); 
    fgets(tasks[count].desc, sizeof(tasks[count].desc), stdin);
    tasks[count].desc[strcspn(tasks[count].desc, "\n")] = '\0'; 
    strcpy(tasks[count].status, "Pending");
    count++;
    printf("Task added!\n");
}

void updateTask() {
    int id;
    printf("Enter task ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid ID!\n");
        return;
    }
    printf("Enter new status (Pending/Done): ");
    scanf("%s", tasks[id-1].status);
    printf("Task updated!\n");
}

void displayTasks() {
    if (count == 0) {
        printf("No tasks!\n");
        return;
    }
    printf("ID  Description                 Status\n");
    for (int i = 0; i < count; i++) {
        printf("%d   %-25s %s\n", tasks[i].id, tasks[i].desc, tasks[i].status);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Task\n2. Update Task\n3. Display Tasks\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addTask();
        else if (choice == 2) updateTask();
        else if (choice == 3) displayTasks();
        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}