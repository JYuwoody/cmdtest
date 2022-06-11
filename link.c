#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);
typedef struct _node
{
        void *data;
        struct _node *next;
}Node;

typedef struct _linkedList
{
        Node *head;
        Node *tail;
        Node *current;
}LinkedList;

typedef struct _employee
{
        char name[32];
        unsigned char age;
}Employee;

int compareEmployee(Employee *e1, Employee *e2);
void displayEmployee(Employee *employee);

void initList(LinkedList* list);
void addHead(LinkedList* list, void* data);
void addTail(LinkedList* list, void* data);
void delete(LinkedList* list, Node* node);
Node *getNode(LinkedList* list, COMPARE compare, void* data);
void displaylist(LinkedList* list, DISPLAY display);


void main()
{
        LinkedList linkedList;

        Employee *samuel = (Employee*) malloc(sizeof(Employee));
        strcpy(samuel->name,"Samuel");
        samuel->age = 32;

        Employee *sally = (Employee*) malloc(sizeof(Employee));
        strcpy(samuel->name,"Sally");
        samuel->age = 28;

        Employee *susan = (Employee*) malloc(sizeof(Employee));
        strcpy(samuel->name,"Susan");
        samuel->age = 45;

        initList(&linkedList);

        addHead(&linkedList, samuel);
        addHead(&linkedList, sally);
        addHead(&linkedList, susan);
        
        displaylist(&linkedList, (DISPLAY)displayEmployee);
        


	return;
}



int compareEmployee(Employee *e1, Employee *e2)
{
        return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *employee)
{
        printf("%s : %d \n",employee->name, employee->age);
}

void initList(LinkedList* list)
{
        list->head = NULL;
        list->tail = NULL;
        list->current = NULL;
}


void addHead(LinkedList* list, void* data)
{
        Node *node = (Node*) malloc(sizeof(Node));
        node->data = data;
        if(list->head == NULL)
        {
                list->tail = node;
                node->next = NULL;
        }
        else
        {
                node->next = list->head;
        }
        list->head = node;
}

void addTail(LinkedList* list, void* data)
{
        Node *node = (Node*) malloc(sizeof(Node));
        node->data = data;
        if(list->head == NULL)
        {
                list->head = node;
        }
        else
        {
                list->tail->next = node;        //older tail next pointer to point new tail
        }
        list->tail = node;
}

Node *getNode(LinkedList* list, COMPARE compare, void* data)
{
        Node *node = list->head;
        while(node != NULL)
        {
                if(compare(node->data, data) == 0)
                {
                        return 0;
                }
                node = node->next;
        }
        return NULL;
}

void delete(LinkedList* list, Node* node)
{
        if(node == list->head)
        {
                if(list->head->next == NULL)
                {
                        list->head = NULL;
                        list->tail = NULL;
                }
                else
                {
                        list->head = list->head->next;
                }
        }
        else
        {
                Node *tmp = list->head;
                while(tmp != NULL && tmp->next != node)
                {
                        tmp = tmp->next;
                }
                if(tmp != NULL)
                {
                        tmp->next = node->next;
                }
        }
        free(node);
}


void displaylist(LinkedList* list, DISPLAY display)
{
        printf("\nLinked\tList\n");
        Node *current = list->head;
        int i = 0;
        while(current != NULL && i < 4)
        {
                display(current->data);
                i++;
        }
        current = current->next;
}

















