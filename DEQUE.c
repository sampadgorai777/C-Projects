#include <stdio.h>
#include <stdlib.h>
#define NULL 0

// Declare a struct to represent a node in the double ended queue.
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Declare a struct to represent the double ended queue.
struct deque {
    struct node *front;
    struct node *rear;
};

// Create a new double ended queue.
struct deque *create_deque() {
    struct deque *dq = (struct deque *)malloc(sizeof(struct deque));
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

// Add an element to the front of the double ended queue.
void enqueue_front(struct deque *dq, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = dq->front;
    if (dq->front == NULL) {
        dq->rear = new_node;
    } else {
        dq->front->prev = new_node;
    }
    dq->front = new_node;
}

// Add an element to the back of the double ended queue.
void enqueue_rear(struct deque *dq, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = dq->rear;
    if (dq->rear == NULL) {
        dq->front = new_node;
    } else {
        dq->rear->next = new_node;
    }
    dq->rear = new_node;
}

// Remove an element from the front of the double ended queue.
int dequeue_front(struct deque *dq) {
    if (dq->front == NULL) {
        return -1;
    }

    int data = dq->front->data;
    struct node *old_front = dq->front;
    dq->front = old_front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(old_front);
    return data;
}

// Remove an element from the back of the double ended queue.
int dequeue_rear(struct deque *dq) {
    if (dq->rear == NULL) {
        return -1;
    }

    int data = dq->rear->data;
    struct node *old_rear = dq->rear;
    dq->rear = old_rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(old_rear);
    return data;
}


// Print the front element of the double ended queue.
int print_front(struct deque *dq) {
    if (dq->front == NULL) {
        printf("The DeQue is empty.\n");
        return -1;
    }
    return dq->front->data;
}

// Print the rear element of the double ended queue.
int print_rear(struct deque *dq) {
    if (dq->rear == NULL) {
        printf("The DeQue is empty.\n");
        return -1;
    }
    return dq->rear->data;
}
// Print the elements of the double ended queue.
void print_deque(struct deque *dq) {
    if (dq->front == NULL) {
        printf("The DeQue is empty.\n");
        return;
    }
    struct node *node = dq->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

// Free the double ended queue.
void free_deque(struct deque *dq) {
    while (dq->front != NULL) {
        struct node *node = dq->front;
        dq->front = node->next;
        free(node);
    }
    free(dq);
}

void main()
{
    struct node *dq;
    int ch, data;
    dq = create_deque();

    do {
        clrscr();
        printf("\n**DEQue Operations**\n\n");
        printf("1. Insert at front. \n");
        printf("2. Insert at rear. \n");
        printf("3. Delete at front. \n");
        printf("4. Delete at rear. \n");
        printf("5. Display front. \n");
        printf("6. Display rear. \n");
        printf("7. Display DeQuE. \n");
        printf("8. Delete DeQue. \n");
        printf("0. Exit. \n");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            enqueue_front(dq,data);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d",&data);
            enqueue_rear(dq,data);
            break;
        case 3:
            printf("\nDeleted element is %d \n",dequeue_front(dq));
            break;
        case 4:
            printf("\nDeleted element is %d \n",dequeue_rear(dq));
            break;
        case 5:
            printf("\nFront element is %d \n",print_front(dq));
            break;
        case 6:
            printf("\nRear element is %d \n",print_rear(dq));
            break;
        case 7:
            printf("\nThe DEQue is : ");
            print_deque(dq);
            break;
        case 8:
            printf("\nDeQue deleted successfully...\n");
            free_deque(dq);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Wrong Choice entered....\n");
        }
    } while(ch!=0);
    getch();
}
