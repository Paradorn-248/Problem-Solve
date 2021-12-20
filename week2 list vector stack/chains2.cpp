#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int number;
    struct node *before;
    struct node *next;
} node_t;

node_t *arr_list[100002];
int ans[100002];

node_t *append(node_t *last, int num)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->number = num;
    new_node->before = NULL;
    new_node->next = NULL;
    if (last == NULL)
    {
        last = new_node;
        return last;
    }
    new_node->before = last;
    last->next = new_node;
    last = last->next;
    return last;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L, N, i, j, length, count = 1;
    cin >> L >> N;
    for (i = 0; i < L; i++)
    {
        node_t *run = NULL;
        cin >> length;
        for (j = 0; j < length; j++)
        {
            run = append(run, count);
            if (j == 0 || j == length - 1)
                arr_list[count] = run;
            else
                arr_list[count] = NULL;
            count++;
        }
    }

    int dir = 0;
    char menu;
    node_t *run = arr_list[1];
    for (int a = 0; a < N; a++)
    {
        cin >> menu;
    }
}