#include <bits/stdc++.h>
#include <mutex>
#include <queue>
using namespace std;
pthread_mutex_t mutex_t;
queue<int> que;
void *queue_thread_fun(void *args)
{
    // int i = *(int *)args;
    pthread_mutex_lock(&mutex_t);
    if (!que.empty())
    {
        printf("获取 queue_thread 队列第一个数据 : %d\t%d\n", que.front(), i);
        que.pop();
    }
    else
    {
        printf("获取 queue_thread 队列为空\n");
    }
    pthread_mutex_unlock(&mutex_t);
    return 0;
}
int main()
{
    pthread_mutex_init(&mutex_t, 0);
    for (size_t i = 0; i < 5; i++)
    {
        que.push(i);
    }
    pthread_t pids[8];
    // pthread_mutex_lock(&mutex_t);
    for (size_t i = 0; i < 5; i++)
    {
        cout << "队列" << i << endl;
        pthread_create(&pids[i], 0, queue_thread_fun, 0);
    }
    // pthread_mutex_lock(&mutex_t);
    int res;
    void *func_res;
    for (size_t i = 0; i < 5; i++)
    {
        res = pthread_join(pids[i], &func_res);
        if (res != 0)
        {
            printf("%d等待线程失败", i);
        }
    }
    pthread_mutex_destroy(&mutex_t);
    return 0;
}
