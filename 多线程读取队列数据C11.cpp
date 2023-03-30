// #include <bits/stdc++.h>
#include <iostream>
#include <pthread.h>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;
mutex my_mutex;
queue<int> que;
void *queue_thread_fun(int tmp)
{
    my_mutex.lock();
    if (!que.empty())
    {
        printf("获取 queue_thread 队列第一个数据 : %d&%d\n", que.front(), tmp);
        que.pop();
    }
    else
    {
        printf("获取 queue_thread 队列为空\n");
    }
    my_mutex.unlock();
    return 0;
}
int main()
{
    for (size_t i = 0; i < 10; i++)
    {
        que.push(i);
    }
    // vector<thread> threads;
    for (size_t i = 0; i < 4; i++)
    {
        thread t(queue_thread_fun, i);
        t.join();
    }
    return 0;
}
