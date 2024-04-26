# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

struct Node
{
    char city[40];
    int x;
    int y;
    struct Node* next;
};

void Insert(struct Node** head, char city[40], int x, int y)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->city, city);
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void SearchCity(struct Node* head, char city[40])
{
    struct Node* current = head;
    while(current != NULL)
    {
        if (strcmp(current->city,city) == 0)
        {
            printf("%s city is present in Database!\n", current->city);
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("City not found in the Database!\n");
    }
}

void SearchCoordinate(struct Node* head, int x, int y)
{
    struct Node* current = head;
    while(current != NULL)
    {
        if (current->x == x && current->y == y)
        {
            printf("%s city is present in Database!\n", current->city);
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("City not found in the Database!\n");
    }
}

void DeleteCity(struct Node* head, char city[40])
{
    struct Node* current = head;
    while (current != NULL)
    {
        if(strcmp((current->next)->city,city) == 0)
        {
            current->next = (current->next)->next;
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("City not found in the Database!\n");
    }
}

void DeleteCoordinate(struct Node* head, int x, int y)
{
    struct Node* current = head;
    while (current != NULL)
    {
        if((current->next)->x == x && (current->next)->y == y)
        {
            current->next = (current->next)->next;
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("City not found in the Database!\n");
    }
}

void Range(struct Node* head, int x, int y, float distance)
{
    struct Node* current = head;
    while (current != NULL)
    {
        float dist = sqrt(pow((current->x - x),2)+pow((current->y - y),2));
        if (dist <= distance)
        {
            printf("%s is present in this range.\n", current->city);
        }
        current = current->next;
    }
    printf("Execution Completed!/n");
}

void Print(struct Node* head)
{
    struct Node* current = head;
    while(current!=NULL)
    {
        printf("[%s|%d|%d] -> ", current->city, current->x, current->y);
        current = current ->next;
    }
    printf("NULL\n");
}

void main()
{
    int n;
    struct Node* head = NULL;
    printf("Enter the number of entries you want to enter: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        char city[40];
        int x,y;
        printf("Enter the city: ");
        scanf("%s",city);
        printf("Enter the x-coordinate: ");
        scanf("%d",&x);
        printf("Enter the y-coordinate: ");
        scanf("%d",&y);
        Insert(&head, city, x, y);
    }
    printf("The Database is: \n");
    Print(head);

    char name1[40];
    int X1,Y1;
    int choice;
    printf("Enter: \n1 if you want to search city with name\n2 is  you want to search city with coordinates\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: 
        printf("Enter the city name you want to search: ");
        scanf("%s", &name1);
        SearchCity(head, name1);
        break;

    case 2:
        printf("Enter x coordinate of the city you want to search: ");
        scanf("%d", &X1);
        printf("Enter y coordinate of the city you want to search: ");
        scanf("%d", &Y1);
        SearchCoordinate(head, X1, Y1);
        break;

    default:
        printf("Not valid!!");
        break;
    }
    
    char name2[40];
    int X2,Y2;
    int choice2;
    printf("Enter: \n1 if you want to delete city using name\n2 is  you want to delete city using coordinates\n");
    scanf("%d",&choice2);
    switch (choice2)
    {
    case 1: 
        printf("Enter the city name you want to delete: ");
        scanf("%s", &name2);
        DeleteCity(head, name2);
        Print(head);
        break;

    case 2:
        printf("Enter x coordinate of the city you want to delete: ");
        scanf("%d", &X2);
        printf("Enter y coordinate of the city you want to delete: ");
        scanf("%d", &Y2);
        DeleteCoordinate(head, X2, Y2);
        Print(head);
        break;

    default:
        printf("Not valid!!");
        break;
    }
    
    float distance;
    int X3,Y3;
    printf("For searching cities in the particular range: \n");
    printf("Enter x coordinate of the point: ");
    scanf("%d", &X3);
    printf("Enter y coordinate of the point: ");
    scanf("%d", &Y3);
    printf("Enter the distance from the point you chosen: ");
    scanf("%f", &distance);
    Range(head, X3, Y3, distance);
}