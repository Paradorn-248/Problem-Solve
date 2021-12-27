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

node_t *append(node_t *last, int number)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->number = number;
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
    // แสดงทิศทางในการเดิน
    // 0 ไปข้างหน้าใช้ next
    // 1 ไปข้างหลังใช้ before
    char menu;
    node_t *run = arr_list[1];
    for (int a = 0; a < N; a++)
    {
        cin >> menu;
        if (menu == 'B')
        {
            if (dir == 1 && run->next != NULL)
            {
                if (run->next->next != NULL && run->next->next == run)
                    dir = 0;
                run = run->next;
            }
            else if (dir == 0 && run->before != NULL)
            {
                if (run->before->before != NULL && run->before->before == run)
                    dir = 1;
                run = run->before;
            }
        }
        else if (menu == 'F')
        {
            if (dir == 1 && run->before != NULL)
            {
                if (run->before->before != NULL && run->before->before == run)
                    dir = 0;
                run = run->before;
            }
            else if (dir == 0 && run->next != NULL)
            {
                if (run->next->next != NULL && run->next->next == run)
                    dir = 1;
                run = run->next;
            }
        }
        else if (menu == 'C')
        {
            int pos;
            cin >> pos;
            if (dir == 0)
            {
                if (arr_list[pos]->before != NULL)
                {
                    dir = 1;
                    arr_list[pos]->next = run;
                }
                else
                {
                    arr_list[pos]->before = run;
                }
                if (run->next != NULL)
                {
                    arr_list[run->next->number] = run->next;
                    if (arr_list[run->next->number]->next == run)
                    {
                        arr_list[run->next->number]->next = NULL;
                    }
                    else
                    {
                        arr_list[run->next->number]->before = NULL;
                    }
                }
                run->next = arr_list[pos];
                run = run->next;
            }
            else if (dir == 1)
            {
                if (arr_list[pos]->next != NULL)
                {
                    arr_list[pos]->before = run;
                    dir = 0;
                }
                else
                {
                    arr_list[pos]->next = run;
                }
                if (run->before != NULL)
                {
                    arr_list[run->before->number] = run->before;
                    if (arr_list[run->before->number]->before == run)
                    {
                        arr_list[run->before->number]->before = NULL;
                    }
                    else
                    {
                        arr_list[run->before->number]->next = NULL;
                    }
                }
                run->before = arr_list[pos];
                run = run->before;
            }
        }
        ans[a] = run->number;
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << '\n';
    }
}