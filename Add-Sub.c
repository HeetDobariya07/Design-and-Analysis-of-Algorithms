#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* Create(int number)
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int quotient=1, remainder;
    while(quotient != 0)
    {
        remainder = number % 10;
        quotient = number / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = remainder;
        newNode->next = NULL;
        number = quotient;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void PrintReverse(struct Node* head)
{
    if (head == NULL)
        return;
    PrintReverse(head->next);
    printf("%d", head->data);
}

void Print(struct Node* head)
{
    struct Node* current = head;
    while(current!=NULL)
    {
        printf("%d -> ", current->data);
        current = current ->next;
    }
    printf("NULL\n");
}

void Subtract(struct Node* head1, struct Node* head2)
{
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int borrow = 0;

    while (current1 != NULL || current2 != NULL)
    {
        int value1 = (current1 != NULL) ? current1->data : 0;
        int value2 = (current2 != NULL) ? current2->data : 0;

        value1 = value1 - borrow;    // Subtract the borrow from the first number
        borrow = 0;                  // Reset borrow

        if (value1 < value2)
        {
            value1 = value1 + 10;    // Borrow from the next higher digit
            borrow = 1;              // Set borrow flag
        }

        int digit = value1 - value2;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        if (current1 != NULL) current1 = current1->next;
        if (current2 != NULL) current2 = current2->next;
    }

    Print(head);
    PrintReverse(head);
    printf("\n");
}

void Sum(struct Node* head1, struct Node* head2)
{
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int carry = 0;
    
    while (current1 != NULL || current2 != NULL || carry != 0)
    {
        int value1 = (current1 != NULL) ? current1->data : 0;
        int value2 = (current2 != NULL) ? current2->data : 0;
        
        int total = value1 + value2 + carry;
        carry = total / 10;
        int digit = total % 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = NULL;
        
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }

        if (current1 != NULL) 
            current1 = current1->next;
        if (current2 != NULL) 
            current2 = current2->next;
    }
    
    Print(head);
    PrintReverse(head);
    printf("\n");
}

void main()
{
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    struct Node* head1 = Create(num1);
    Print(head1);

    printf("Enter the second number: ");
    scanf("%d", &num2);
    struct Node* head2 = Create(num2);
    Print(head2);
    
    printf("Sum of above two linked list is: \n");
    Sum(head1, head2);

    if(num1 > num2)
    {
        printf("Substraction of above two linked list is: \n");
        Subtract(head1, head2);
    }
    else
    {
        printf("Substraction of greater number from smaller one is not possible! \n");
    }
    
}