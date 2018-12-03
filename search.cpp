//
// Created by 76947 on 2018/3/10.
//
#include "search.h"

/***********深度优先搜索***************/
/*采用递归的方法
 * s1 判断边界（step = boundary）
 * s2 尝试当下的每一种可能（枚举，遍历），做出当下的动作
 * s3 递归调用，进行下一步
 * s4 回溯，取消这一步的动作（因为走不通了，所以回到之前的地方，继续别的选择）
 * s5 return */
void dfs(int step, int n, int a[], int book[]){


    //判断边界（step = boundary）
    if (step == n+1){
        for (int i = 1; i < n+1; ++i) {
            cout<<a[i];
        }
        cout<<endl;
        return;
    }

    // 尝试当下的每一种可能（枚举，遍历）
    for (int j = 1; j < n+1; ++j) {
        if (book[j] == 0){

            // 做出当下的动作
            a[step] = j;
            book[j] = 1;

            // 递归调用，进行下一步
            dfs(step+1, n, a, book);

            // 回溯，取消这一步的动作
            book[j] = 0;

            a[step] = 0;
        }

    }
    return;
}


// 二分查找
int DevideSearch(int key, int a[], int left, int right){
    int mid;

    while (left<right){
        mid = (left + right)/2;
        if (a[mid] == key)
        return mid;
        if (a[mid]>key) right = mid;
        else left = mid;
    }
}

