// Write a c program to stimulate segmentation. Takes as input:
// 1. Segment number
// 2. Base address
// 3. Segment limit

#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
typedef struct list
{
    int seg;
    int base;
    int limit;
    struct list *next;
} list_t;
void insert(list_t *p, list_t *q, int base, int limit, int seg)
{
    list_t *Q = NULL;
    if (p == NULL)
    {
        p = malloc(sizeof(list_t));
        p->limit = limit;
        p->base = base;
        p->seg = seg;
        p->next = NULL;
    }
    else
    {
        while (q->next != NULL)
        {
            Q = q->next;
            printf("yes");
        }
        q->next = malloc(sizeof(list_t));
        q->next->limit = limit;
        q->next->base = base;
        q->next->seg = seg;
        q->next->next = NULL;
    }
}
int find(struct list *q, int seg)
{
    while (q->seg != seg)
    {
        q = q->next;
    }
    return q->limit;
}
int search(struct list *q, int seg)
{
    while (q->seg != seg)
    {
        q = q->next;
    }
    return q->base;
}
int main()
{
    list_t *q = NULL;
    list_t *p = NULL;
    int seg, offset, limit, base, c, s, physical;
    printf("Enter segment table\n");
    printf("Enter -1 as segment value for termination\n");
    do
    {
        printf("Enter segment number");
        scanf("%d", &seg);
        if (seg != -1)
        {
            printf("Enter base value:");
            scanf("%d", &base);
            printf("Enter value for limit:");
            scanf("%d", &limit);
            insert(p, q, base, limit, seg);
        }
    } while (seg != -1);
    printf("Enter offset:");
    scanf("%d", &offset);
    printf("Enter bsegmentation number: ");
    scanf("%d", &seg);
    c = find(p, seg);
    s = search(p, seg);
    if (offset < c)
    {
        physical = s + offset;
        printf("Address in physical memory %d\n", physical);
    }
    else
    {
        printf("error ");
    }
}