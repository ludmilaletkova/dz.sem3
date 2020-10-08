//реализация структуры данных очередь 

#include <stdio.h>
#include <stdlib.h>

// описание и создание небходимые типы переменных в структурах для дальнейшего пользования структурами
typedef struct n{
    int val;
    struct n* next;
} node;

typedef struct{  
    node* start;
    node* end;
    int size;
} queue;


node* createNode (int val){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

queue* createQueue(void){
    queue* new_queue = (queue*) malloc(sizeof(queue));
    new_queue->start = new_queue->end = NULL;
    new_queue->size = 0;
    return new_queue;
}

// первое(неполное) объявление функций(операций) для очереди

void push(int val,queue* queue); // добавление в очередь
int pop(queue* queue); // удаление из очереди
int sizeQueue(queue* queue){ // функция, возвращающая количество значений в очереди
    return queue->size;
}

void operations(void){ // функция вывода на экран операций с очередью
    printf("Operations for work with queue:\n");
    printf("1) push\n");
    printf("2) pop\n");
    printf("3) size\n");
    printf("0) exit\n");
}

///////////////////////////////////

int main(void) {
    queue* mainQueue = createQueue();// создание очереди самой программы  
    operations();
    int oper = 1, val;
    while(oper){
        printf("Operation: ");
        scanf("%d",&oper);
        switch(oper){
            case 0: break;
            case 1:
                printf("Input value: ");
                scanf("%d", &val);
                push(val, mainQueue);
                break;
            case 2:
                printf("Value : %d\n", pop(mainQueue));
                break;
            case 3:
                printf("Size of queue: %d\n",sizeQueue(mainQueue));
                break;
            default:
                operations();
        }
    }
    return 0;
}

////////////////////////////////////

// полное объявление функции добавления и удаления 
void push(int val,queue* queue){
    node* tmp = createNode(val);
    if(!queue->size){
        queue->start = queue->end = tmp;
    } else {
        queue->end->next = tmp;
        queue->end = tmp;
    }
    ++queue->size;
}

int pop(queue* queue){
    if (!queue->size){
        printf("Queue is empty\n");
        return 0;
    }
    int result = queue->start->val;
    node* tmp = queue->start;
    queue->start = queue->start->next;
    free(tmp);
    --queue->size;
    return result;
}
