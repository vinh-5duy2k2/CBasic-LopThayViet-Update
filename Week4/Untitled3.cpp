#include <stdlib.h>
#include <stdio.h>
 
typedef int item; //kieu du lieu
struct Node
{
    item Data;
    Node * Next;
};
struct Queue
{
    Node * Front, *Rear; //Node dau va Node cuoi
    int count; //dem so phan tu
};
 
void Init (Queue &Q); //khoi tao Queue rong
int Isempty(Queue Q); //kiem tra Queue rong
void Push(Queue &Q, item x); //them phan tu vao cuoi hang doi
int Pop(Queue &Q); //Loai bo phan tu khoi dau hang doi
int Qfront (Queue Q); //xem thong tin phan tu dau hang doi 
Node *MakeNode(item x); //tao 1 Node
void Input (Queue &Q); //Nhap 
void Output(Queue Q); //Xuat 
 
void Init(Queue &Q)
{
    Q.Front = Q.Rear = NULL;
    Q.count = 0;
}
int Isempty (Queue Q) //kiem tra Queue rong
{
    if (Q.count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}
 
Node *MakeNode(item x) //tao 1 Node
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
 
void Push(Queue &Q, item x) //them phan tu vao cuoi Queue
{
    Node *P = MakeNode(x); //Neu Q rong
    if (Isempty(Q))
    {
        Q.Front = Q.Rear = P; //dau va cuoi deu tro den P
    }
    else //Khong rong
    { 
        Q.Rear->Next = P;
        Q.Rear = P;
    }
    Q.count ++ ; //tang so phan tu len
}
 
int Pop(Queue &Q) //Loai bo phan tu khoi dau hang doi
{
    if (Isempty(Q)) 
    {
        printf("Hang doi rong !");
        return 0;
    }
    else
    {
        item x = Q.Front->Data;
        if (Q.count == 1) //neu co 1 phan tu
            Init(Q);
        else
            Q.Front = Q.Front->Next;
        Q.count --;
        return x; //tra ve phan tu lay ra
    }
}
 
void Input (Queue &Q) //nhap hang doi
{
    int i=0; 
    item x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Push(Q,x);
    } while(x != 0); //nhap 0 de ket thuc
}
 
void Output(Queue Q)
{
    Node *P = Q.Front;
    while (P != NULL)
    {
        printf("%d   ",P->Data);
        P = P->Next;
    }
    printf("\n");
}
 
int main()
{
    Queue Q;
    Init(Q);
    Input(Q);
    Output(Q);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Queue rong");
    printf("\n2: Them phan tu vao Queue");
    printf("\n3: Xoa phan tu trong Queue");
    printf("\n4: Xuat Queue");
    printf("\n5: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Isempty(Q)) printf("Queue rong !");
                else printf ("Queue khong rong !");
                break;
            }
            case 2:
            {
                item x;
                printf ("Nhap phan tu can chen vao Queue: ");
                scanf("%d",&x);
                Push(Q,x);
                break;
            }
            case 3:
            {
                Pop(Q);
                break;
            }
            case 4: 
            {
                Output(Q);
                break;
            }
            case 5: break;
        }
    }while (lua_chon !=5);
    return 0;
}
