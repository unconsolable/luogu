//BFS
//活用set判断visited
#include <iostream>
#include <cstring>
#include <set>
void replace(char *raw, char *before, char *after, int index)
{
    int switchlen = strlen(after) - strlen(before);
    int orig_len = strlen(raw);
    int i;
    if (switchlen < 0)
    {
        for (i = 0; after[i] != '\0'; ++i)
        {
            raw[index + i] = after[i];
        }
        //向前
        for (int j = index + i; raw[j] != '\0'; ++j)
        {
            raw[j] = raw[j - switchlen];
        }
    }
    else
    {
        //向后
        for (unsigned j = orig_len + switchlen; j >= strlen(before) + index; --j)
        {
            raw[j] = raw[static_cast<int>(j) - switchlen];
        }
        for (i = 0; after[i] != '\0'; ++i)
        {
            raw[index + i] = after[i];
        }
    }
}
int find(char *raw, char *target, bool haschanged[])
{
    int rawlen = strlen(raw);
    int targetlen = strlen(target);
    for (int i = 0; i <= rawlen - targetlen; ++i)
    {
        if (raw[i] == target[0] && haschanged[i] == false)
        {
            bool flag = true;
            for (int j = 1; j < targetlen; ++j)
            {
                if (raw[i + j] != target[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                haschanged[i] = true;
                return i;
            }
        }
    }
    return -1;
}
struct Node
{
    char *data = nullptr;
    int step = 0;
};
struct Queue
{
    Node que[10000] = {};
    int head = 0, tail = 0;
    ~Queue();
};
Queue::~Queue()
{
    while (head != tail)
    {
        delete[] que[head].data;
        head++;
    }
}
void EnQueue(Queue *q, char word[], int step)
{
    q->que[q->tail].data = new char[6000];
    q->que[q->tail].step = step;
    strcpy(q->que[q->tail].data, word);
    ++q->tail;
}
Node DeQueue(Queue *q)
{
    ++q->head;
    return q->que[q->head - 1];
}
bool visited(Queue *q, Node n)
{
    for (int i = 0; i < q->tail; ++i)
    {
        if (!strcmp(q->que[i].data, n.data))
            return true;
    }
    return false;
}
int main()
{
    std::set<std::string> visited;
    char init[50], result[25];
    int RuleCnt = 0;
    char Before[8][30], After[8][30];
    std::cin >> init >> result;
    Queue q1;
    while (std::cin >> Before[RuleCnt] >> After[RuleCnt])
    {
        ++RuleCnt;
    }
    EnQueue(&q1, init, 0);
    while (q1.head != q1.tail)
    {
        Node cur = DeQueue(&q1);
        if (!strcmp(cur.data, result))
        {
            std::cout << cur.step;
            return 0;
        }
        else
        {
            if (cur.step > 10)
            {
                std::cout << "NO ANSWER!";
                return 0;
            }
            for (int i = 0; i < RuleCnt; ++i)
            {
                bool haschanged[6000];
                memset(haschanged, false, sizeof(haschanged));
                Node possible;
                int start = find(cur.data, Before[i], haschanged);
                do
                {
                    if (start != -1)
                    {
                        possible.data = new char[6000];
                        strcpy(possible.data, cur.data);
                        possible.step = cur.step + 1;
                        replace(possible.data, Before[i], After[i], start);
                        if (visited.find(std::string(possible.data))==visited.end())
                        {
                            EnQueue(&q1, possible.data, possible.step);
                            visited.insert(std::string(possible.data));
                        }
                        delete[] possible.data;
                    }
                    start = find(cur.data, Before[i], haschanged);
                } while (start != -1);
            }
        }
    }
    std::cout << "NO ANSWER!";
}