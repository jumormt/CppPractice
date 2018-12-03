//
// Created by 76947 on 2018/3/20.
//

#include <iostream>
#include "variable.h"
#include <fstream>
#include "classfile.h"
#include "ManManager.h"
#include<cstring>

#include "Sort.h"
#include "search.h"
#include <memory>
#include <unordered_map>

using namespace std;


#include <stdio.h>
#include <queue>          // std::queue

#include <stack>


template <typename T>
void inQueue(vector<T> &vec){
    for (auto it = vec.begin();  it != vec.end() ; ++it) {
        cout<<*it<<" ";
    }
}

template <typename T>
void initQueue2(vector<T> &vec, queue<T> &que){
    for (auto it = vec.begin();  it != vec.end() ; ++it) {
        que.push(*it);
    }
}



int test2 ()
{
    std::queue<int> myqueue;
    queue<int> newqueue;
    int myint;

    std::cout << "Please enter some integers (enter 0 to end):\n";

//    do {
//        std::cin >> myint;
//        myqueue.push (myint);
//    } while (myint);
//    myqueue.push(6);
//    myqueue.push(3);
//    myqueue.push(1);
//    myqueue.push(7);
//    myqueue.push(5);
//    myqueue.push(8);
//    myqueue.push(9);
//    myqueue.push(2);
//    myqueue.push(4);
    vector<int> vec{6,3,1,7,5,8,9,2,4};
//    inQueue(vec);
    initQueue2(vec, myqueue);
    std::cout << "myqueue contains: ";
    while (!myqueue.empty())
    {
        int temp = myqueue.front();
        myqueue.pop();
        newqueue.push(temp);
        temp = myqueue.front();
        myqueue.push(temp);
        myqueue.pop();
//        std::cout << ' ' << myqueue.front();
    }
    cout<<"done!"<<endl;

    while (!newqueue.empty()){
        cout<<newqueue.front()<<" ";
        newqueue.pop();
    }


    return 0;
}

int test1()
{
    int arr[] = { 9, 2, 5, 8, 3, 4, 7, 1, 6, 10};
    ShellSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}


int test3()
{
//    stack<char> st;
    char st[100];
    int top = 0;
    vector<char> vec{'a', 'b', 'a'};
    int len = vec.size();
    int mid = len/2 - 1;


    for (int i = 0; i <= mid ; ++i) {
        st[top] = vec[i];
        ++top;
    }

    int next = (len & 1) == 0?mid+1:mid+2;
    for (int j = next; j < len; ++j) {
        if (st[top - 1]!=vec[j]){
            break;
        }
        --top;
    }

    if (top == 0){
        cout<<"YES!"<<endl;
    } else{
        cout<<"NO!"<<endl;
    }

    return 0;
}

int test4(){

    queue<int> q1;
    queue<int> q2;
    vector<int> vec1{2, 4, 1, 2, 5, 6};
    vector<int> vec2{3, 1, 3, 5, 6, 4};
//    vector<int> vec1{6,5,2,1,4,2};
//    vector<int> vec2{4,6,5,3,1,3};

    initQueue2(vec1, q1);

    initQueue2(vec2, q2);

    stack<int> st;

//    auto it = &st.top();

    int stdp = 0;



    while((!q1.empty())&&(!q2.empty())) {
        int tmp = q1.front();
//        int flag = 0;


        tmp = q1.front();
        st.push(q1.front());
        cout<<q1.front()<<endl;
        q1.pop();
        ++stdp;
        for (int i = 1; i < stdp; ++i) {
            int cmp = *(&st.top() - i);
            if (cmp == tmp) {
                cout<<endl;


                for (int j = 0; j <= i; ++j) {
                    q1.push(st.top());
                    st.pop();
                    --stdp;
                }
                break;
            }

        }


        tmp = q2.front();
        st.push(q2.front());
        cout<<q2.front()<<endl;
        q2.pop();
        ++stdp;
        for (int i = 1; i < stdp; ++i) {
            int cmp = *(&st.top() - i);
            if (cmp == tmp) {
                cout<<endl;

                for (int j = 0; j <= i; ++j) {
                    q2.push(st.top());
                    st.pop();
                    --stdp;
                }
                break;
            }
        }
    }

    if (q1.empty()){
        cout<<endl;
        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q2.pop();
        }
    }else
    {
        cout<<endl;
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
    }

    return 0;

//    cout<<st.top();


//    cout<<q1.front();
}


int test5(){
    int a[9],book[10],sum = 0;

    for (a[0] = 1; a[0] < 10; ++a[0])
        for (a[1] = 1; a[1] < 10; ++a[1])
            for (a[2] = 1;a[2] < 10; ++a[2])
                for (a[3] = 1;a[3] < 10; ++a[3])
                    for (a[4] = 1;a[4] < 10; ++a[4])
                        for (a[5] = 1;a[5] < 10; ++a[5])
                            for (a[6] = 1;a[6] < 10; ++a[6])
                                for (a[7] = 1;a[7] < 10; ++a[7])
                                    for (a[8] = 1;a[8] < 10; ++a[8])
                                    {
                                        for (int i = 0; i < 10; ++i) {
                                            book[i] = 0;
                                        }

                                        for (int i = 0; i < 9; ++i) {
                                            book[a[i]] = 1;
                                        }
                                        sum = 0;
                                        for (int j = 0; j < 10; ++j) {
                                            sum += book[j];
                                        }

                                        if ((sum == 9) && ((a[0]+a[3])*100 + (a[1]+a[4])*10 + a[2] + a[5] == a[6]*100 + a[7]*10 + a[8]))
                                        {
                                            cout << a[0] << a[1] << a[2] << "+" << a[3] << a[4] << a[5] << "="<< a[6]<<a[7]<<a[8]<<endl;
                                        }
                                    }


}




int test6(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b = DevideSearch(3, a, 0, 9);
    cout<<a[b];
    return 0;
}

void test7(){

    string s1 = "abcd";
    auto it = s1.begin();
    s1.insert(it, 'g');
    string s2 = "cdef";
    s1.insert(it, s2.begin(), s2.end());


}

//int main(){
//    test7();
//    cout<<"你好";
//
//    return 0;
//
//}

string str = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";

void getNum(char s[100], int c[26]){
    int i = 0;
    for (int j = 0; j < strlen(s); ++j) {
        for(i = 0;str[i]&&s[j]!=str[i];++i);
        if(str[i])
            ++c[i];
        else
            continue;
    }
}

void swap1(int& i, int& j){
    int k = i;
    i = j;
    j = k;
}

void quicksort(int a[], int left, int right){
    if (left >= right) return;

    int key = a[left];
    int i = left,j = right;

    while(i != j){

        while(a[j] >= key && i != j) --j;
        while(a[i] <= key && i != j) ++i;

        if(i!=j)
            swap1(a[i], a[j]);

    }
    swap1(a[left], a[i]);

    quickSort(a, left, i-1);
    quickSort(a, i+1, right);
}

//int main() {
//
//    char str1[100], str2[100];
//    cout<<"input str1:"<<endl;
//    cin>>str1;
//    cout<<"input str2:"<<endl;
//    cin>>str2;
//    int count1[26] = {0}, count2[26] = {0};
//
//    getNum(str1, count1);
//    getNum(str2, count2);
//
//
//    cout<<sizeof(count1)/ sizeof(int);
//
//    quickSort(count1, 0, sizeof(count1)/ sizeof(int)-1);
//    quickSort(count2, 0, sizeof(count2)/ sizeof(int)-1);
//
//
//
//    int i;
//
//    for (i = 0; (i<26)&&count1[i] == count2[i]; ++i);
//
//    if (count1[i]||count2[i]) cout<<"NO!";
//    else
//        cout<<"YES!";
//    return 0;
//}
void go(int step, int& pos, int dr, int a[], int n){

    while(step--) {
        do {
            pos = (pos + dr + n - 1) % n + 1;
        } while (a[pos] == 0);
    }
}
//
//int main(){
//
//    int n,m,k;
//
//    int a[21] = {0};
//
//
//    cin>>n>>m>>k;
//    cout<<n<<" "<<m<<" "<<k;
//
//    for (int i = 0; i < n+1; ++i) {
//        a[i] = i;
//    }
//    int p2 = 1, p1 = n;
//    int num = n;
//    while(n){
//
//        go(k, p1, 1, a, num);
//        go(m, p2, -1, a, num);
//
//        printf("%3d", p1); n--;
//        if(p2 != p1) { printf("%3d", p2); n--; }
//        a[p1] = a[p2] = 0;
//        if(n) printf(",");
//    }
//
//
//    return 0;
//}


//双向链表
//void linkd(int i, int j, vector<int> &l, vector<int>& r){
//
//    r[i] = j;
//    l[j] = i;
//}
//
//int main(){
//
//    int n, m;
//    cin>>n>>m;
//
//
//    vector<int> left(n+2, 0);
//    vector<int> right(n+2, 0);
//
//    for (int i = 1; i < n+1; ++i) {
//        left[i] = i-1;
//        right[i] = i+1;
//    }
//    left[n+1] = n;
//    right[0] = 1;
//
//    while(m--){
//        int a;
//        cin>>a;
//
//        if (a == 4){
//            // 反转
//            for (int i = 0; i < n+2; ++i) {
//                int m = left[i];
//                left[i] = right[i];
//                right[i] = m;
//            }
//        }else{
//
//            int b,c;
//            cin>>b>>c;
//
//            if (a == 1){
//                // b 移到 c的左边
//                if (left[c] == b) continue;
//
//                linkd(left[b], right[b], left, right);
//
//                linkd(left[c], b, left, right);
//
//                linkd(b, c, left, right);
//
//
//            }else if (a == 2){
//                // b c的右边
//                if (right[c] = b) continue;
//
//                linkd(left[b], right[b], left, right);
//
//                linkd(b, right[b], left, right);
//
//                linkd(c, b, left, right);
//
//            }else{
//                // 交换
//                if(right[b] == c) { link(Lb, c); link(Y, X); link(X, RY); }
//                else { link(LX, Y); link(Y, RX); link(LY, X); link(X, RY); }
//            }
//
//        }
//
//        for (int i = 1; i < n+1; ++i) {
//            cout<<left[i]<<" ";
//        }
//
//        cout<<endl;
//
//        for (int i = 1; i < n+1; ++i) {
//            cout<<right[i]<<" ";
//        }
//    }
//
//
//}

