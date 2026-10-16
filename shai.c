#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int artwork_id;
char artwork_name[100];
char artist_name[100];
int price;
struct node* next;
struct node* prev;
};

struct linkedlist{
struct node* head;
struct node* tail;
};

struct node* createnode(int artwork_id, char artwork_name[100], char artist_name[100], int price)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->artwork_id = artwork_id;
    strcpy(newnode->artwork_name,artwork_name);
    strcpy(newnode->artist_name,artist_name);
    newnode->price = price;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
};

void insert(struct linkedlist* list1, int artwork_id, char artwork_name[100], char artist_name[100], int price)
{
    if(artwork_id % 2 == 0)
    {
        struct node* node1 = createnode(201,"black pearl","shaafifm",20300000);
        if(list1->head == NULL)
        {
            list1->head = node1;
            list1->tail = node1;
        }
        else
        {
            node1->next =list1->head;
            list1->head->prev = node1;
            list1->head = node1;
        }
    }

    else
    {
       struct node* node2 = createnode(202,"money heist","proff",4000000);
        if(list1->tail == NULL)
        {
            list1->head = node2;
            list1->tail = node2;
        }
        else
        {
            node2->prev =list1->tail;
            list1->tail->next = node2;
            list1->tail = node2;
        }
    }
};

void copy(int arr[],struct linkedlist* list1)
{   int i;
    struct node* temp = list1 -> head;
    for(i = 0; temp!= NULL; i++)
    {
        arr[i] = temp -> artwork_id;
        temp = temp->next;
    }
    for(int j = 0; j<i; j++)
    {
        printf("%d\n",arr[j]);
    }

}


/*void insertrear(struct linkedlist* list1, int artwork_id, char artwork_name[100], char artist_name[100], int price)
{
    struct node* node2 = createnode(202,"money heist","proff",4000000);
    if(list1->tail == NULL)
    {
        list1->head = node2;
        list1->tail = node2;
    }
    else
    {
        node2->prev =list1->tail;
        list1->tail->next = node2;
        list1->tail = node2;
    }
};*/


struct linkedlist* createlist()
{
    struct linkedlist* newlist = malloc(sizeof(struct linkedlist));
    newlist->head = NULL;
    newlist->tail = NULL;

    return newlist;
};

/*void array(struct linkedlist *list) {

    int array[] = {1,2,3,4,5};
    int *p = malloc(sizeof(int));
    p = &array;
    for(int i =0;i<5;i++){
        printf("%d",*p);

    }
}*/

int main()
{
    struct node* node_a = createnode(101,"Starry Night" ,  "Vincent Van Gogh" ,2500000);
    struct node* node_b = createnode(102 ,"Mona Lisa", "Leonardo da Vinci", 5000000);
    struct node* node_c = createnode(103, "The Scream", "Edvard Munch", 1200000);
    struct node* node_d = createnode(104, "The Persistence of Memory" ,"Salvador Dali", 1800000);
    struct node* node_e = createnode(105,"The Last Supper", "Leonardo da Vinci", 3000000);
    struct node* node_f = createnode(106 ,"Girl with a Pearl Earring", "Johannes Vermeer", 2200000);

    node_a -> next = node_b;
    node_b -> next = node_c;
    node_c -> next = node_d;
    node_d -> next = node_e;
    node_e -> next = node_f;

    node_b -> prev = node_a;
    node_c -> prev = node_b;
    node_d -> prev = node_c;
    node_e -> prev = node_d;
    node_f -> prev = node_e;

    struct linkedlist* list1 = createlist();
    list1->head = node_a;
    list1->tail = node_f;


    insert(list1,201,"black pearl","shaafifm",20300000);
    //insertrear(list1,202,"money heist","proff",4000000);



    struct node* temp = list1 -> head;
    while(temp != NULL)
    {
    printf("Artwork ID:%d\nArtwork Name:%s\nArtist Name:%s\nPrice:%d\n\n\n",temp->artwork_id, temp->artwork_name, temp->artist_name, temp->price);
    temp = temp -> next;
    }

     int arr[100];
     copy(arr,list1);


}
