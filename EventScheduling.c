# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Event
{
    char name[40];
    int stime;
    int ftime;
}; 

void Print(struct Event event[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Process = %s | Start Time = %d | End Time = %d\n", event[i].name, event[i].stime, event[i].ftime);
    }
}

void Sort(struct Event event[], int len)
{
    struct Event temp;
    for (int i=0; i<len; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (event[i].ftime > event[j].ftime)
            {
                temp = event[i];
                event[i] = event[j];
                event[j] = temp;
            } 
        }
    }
    Print(event, len);
}

void Selection(struct Event event[], int len)
{
    int lastSelectedFinishTime = -1;
    for (int i = 0; i < len; i++)
    {
        if (event[i].stime >= lastSelectedFinishTime)
        {
            printf("Process = %s | Start Time = %d | End Time = %d\n", event[i].name, event[i].stime, event[i].ftime);
            lastSelectedFinishTime = event[i].ftime;
        }
    }
}

void main()
{
    struct Event event[100];
    struct Event sortedEvent[100];
    int num;
    printf("Enter the total number of process you want to enter: ");
    scanf("%d", &num);
    for(int i=0; i<num; i++)
    {
        printf("Enter the name of the process: ");
        scanf("%s", event[i].name);
        printf("Enter the start time of process: ");
        scanf("%d", &event[i].stime);
        printf("Enter the end time of process: ");
        scanf("%d", &event[i].ftime);
    }
    printf("List of all events: \n");
    Print(event, num);

    printf("Sorted events according to end time: \n");
    Sort(event, num);

    printf("Selected events are: \n");
    Selection(event, num);
}   
