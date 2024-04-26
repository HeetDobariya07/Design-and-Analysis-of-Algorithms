# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

struct Data
{
    char city[40];
    int x;
    int y;
};

void Print(struct Data data[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("City = %s, x = %d, y = %d\n", data[i].city, data[i].x, data[i].y);
    }
}

void SearchName(struct Data data[], int num, char name[])
{
    int i=0;
    for(i=0; i<num; i++)
    {
        if(strcmp(data[i].city, name) == 0)
        {
            printf("%s city is present in Database!\n", data[i].city);
            break;
        }
    }
    if (i == num)
    {
        printf("City not found in the Database!\n");
    }
}

void SearchCoordinate(struct Data data[], int num, int x, int y)
{
    int i=0;
    for(i=0; i<num; i++)
    {
        if(data[i].x == x && data[i].y == y)
        {
            printf("%s city is present in Database!\n", data[i].city);
            break;
        }
    }
    if (i == num)
    {
        printf("City not found in the Database!\n");
    }
}

void DeleteName(struct Data data[], int *num, char name[])
{
    for(int i=0; i<*num; i++)
    {
        if(strcmp(data[i].city, name) == 0)
        {
            for(int j=i; j<*num-1 ; j++)
            {
                data[j] = data[j+1];
            }
            (*num)--;
            printf("Entry Deletion Successful!\n");
            return;
        }
    }
    printf("Entry not found");
}

void DeleteCoordinate(struct Data data[], int *num, int x, int y)
{
    for(int i=0; i<*num; i++)
    {
        if(data[i].x == x && data[i].y == y)
        {
            for(int j=i; j<*num ; j++)
            {
                data[j] = data[j+1];
            }
            (*num)--;
            printf("Entry Deletion Successful!\n");
            return;
        }
    }
    printf("Entry not found");

}

void Range(struct Data data[], int num, int x, int y, int distance)
{
    for(int i=0; i<num; i++)
    {
        int dist = sqrt(pow((data[i].x - x), 2) + pow((data[i].y - y), 2));
        if(dist <= distance)
        {
            printf("%s is present in this range.\n", data[i].city);
        }
    }
}

void main()
{
    struct Data data[100];
    int  num;
    char searchcity[100];
    int searchx, searchy;
    printf("Enter the total number of entries you want to enter: ");
    scanf("%d", &num);
    for(int i=0; i<num; i++)
    {
        printf("Enter the name of the city: ");
        scanf("%s", data[i].city);
        printf("Enter the x coordinate of the city: ");
        scanf("%d", &data[i].x);
        printf("Enter the y coordinate of the city: ");
        scanf("%d", &data[i].y);
    }
    Print(data, num);

    int choice;
    printf("Enter: \n1 if you want to search city with name\n2 is  you want to search city with coordinates\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: 
        printf("Enter the name of the city to be searched: ");
        scanf("%s", searchcity);
        SearchName(data, num, searchcity);
        break;

    case 2:
        printf("Enter x coordinate of the city to be searched: ");
        scanf("%d", &searchx);
        printf("Enter y oordinate of the city to be searched: ");
        scanf("%d", &searchy);
        SearchCoordinate(data, num, searchx, searchy);
        break;

    default:
        printf("Not valid!!");
        break;
    }

    char name[100];
    int X, Y;
    int choice2;
    printf("Enter: \n1 if you want to delete city using name\n2 is  you want to delete city using coordinates\n");
    scanf("%d",&choice2);
    switch (choice2)
    {
    case 1: 
        printf("Enter the name of the city to be deleted: ");
        scanf("%s", name);
        DeleteName(data, &num, name);
        Print(data, num);
        break;

    case 2:
        printf("Enter the x coordinate of the city to be deleted: ");
        scanf("%d", &X);
        printf("Enter the y coordinate of the city to be deleted: ");
        scanf("%d", &Y);
        DeleteCoordinate(data, &num, X, Y);
        Print(data, num);        
        break;

    default:
        printf("Not valid!!");
        break;
    }

    int X2, Y2, distance;
    printf("Enter the x coordinate of the point: ");
    scanf("%d", &X2);
    printf("Enter the y coordinate of the point: ");
    scanf("%d", &Y2);
    printf("Enter the distance from the point: ");
    scanf("%d", &distance);
    Range(data, num, X2, Y2, distance);
}