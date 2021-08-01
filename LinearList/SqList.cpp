#include <stdio.h>
#define maxSize 100
typedef int ElemType;
typedef struct
{
    /* data */
    ElemType data[maxSize];

    ElemType length;

} Sqlist;

void init(Sqlist &L)
{

    L.length = 0;
}

int isEmpty(Sqlist &L)
{
    if (L.length == 0)
        return 1;
    return 0;
}

int isFull(Sqlist &L)
{
    if (L.length == maxSize - 1)
        return 1;
    return 0;
}

//增
int addElem(Sqlist &L, ElemType e)
{
    if (isFull(L) == 1)
        return 0;
    L.data[L.length++] = e;
    return 1;
}
//删
int deleteElem(Sqlist &L, int p, ElemType &e)
{
    if (isEmpty(L) || p < 0 || p > maxSize - 1)
        return 0;
    e = L.data[p];
    --L.length;
    for (int i = p; i < L.length; i++)
    {
        L.data[i] = L.data[i + 1];
    }
    return 1;
}
//查
int findElem(Sqlist &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i;
    }
    return -1;
}
//插
int insertElem(Sqlist &L, int p, ElemType e)
{
    if (isFull(L) || p < 0 || p > maxSize - 1)
        return 0;
    L.length++;
    for (int i = L.length - 1; i >= p; i--)
    {
        L.data[i] = L.data[i - 1];
    }
    L.data[p] = e;
    return 1;
}

//改
int changeElem(Sqlist &L, int p, ElemType &e)
{
    if (p < 0 || p > maxSize - 1)
        return 0;
    ElemType temp = e;
    e = L.data[p];
    L.data[p] = temp;
    return 1;
}

void showList(Sqlist L)
{
    for (int i = 0; i < L.length; i++)
        printf("i=%d,data=%d\n", i, L.data[i]);
}
int main()
{
    Sqlist L;
    ElemType e;
    init(L);
    int result;
    result = addElem(L, 1);
    printf("Add Element 1,Result is %d\n", result);
    result = addElem(L, 2);
    printf("Add Element 2,Result is %d\n", result);
    result = addElem(L, 3);
    printf("Add Element 3,Result is %d\n", result);
    result = insertElem(L, 1, 5);
    printf("Insert Element 5 at Position 1 ,Result is %d\n", result);
    printf("Show List:\n");
    showList(L);
    e = 9;
    result = changeElem(L, 2, e);
    printf("Replace Element at Position 2 with 9,Result is %d,Element which is replaced is %d\n", result, e);
    printf("Show List:\n");
    showList(L);
    result = deleteElem(L, 1, e);
    printf("Delete Element at Position 1,Result is %d,Element which is delete is%d\n", result, e);
    printf("Show List:\n");
    showList(L);
}