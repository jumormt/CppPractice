//
// Created by 76947 on 2018/3/6.
//
#include <vector>
#include "Sort.h"

void swap1(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void swap2(int &left, int &right)
{
    int temp = left;
    left = right;
    right = temp;
}

void swap3(int &left, int &right)
{
    if (&left != &right)
    {
        left ^= right;
        right ^= left;
        left ^= right;
    }
}


// 直接插入排序
void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; ++i){
        if(a[i] < a[i-1]){
            int j = i - 1;
            int key = a[i];
//        for (; j>=0 ; --j) {
//
//            if( a[j] <= key) break;
//            a[j+1] = a[j];
//        }
            a[i] = a[i-1];
            while (a[j] > key) {
                a[j + 1] = a[j];
                --j;
            }
            a[j + 1] = key;
        }
    }

    for(int i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }


}

// 希尔排序
void ShellInsertSort(int n,int a[], int dl){

    for (int i = dl; i < n; ++i) {

        if (a[i] < a[i-dl]){

            int j = i-dl;

            int key = a[i];

            a[i] = a[i-dl];

            while(a[j] > key){

                a[j+dl] = a[j];

                j -= dl;

            }

            a[j+dl] = key;
        }

    }

//    for (int k = 0; k < n; ++k) {
//        cout<<a[k]<<" ";
//    }

}

void ShellSort(int a[], int n){
    int dl = n/2;

    while (dl >= 1){
        ShellInsertSort(n,a,dl);
        dl = dl/2;
    }

    for(int i = 0; i < n; ++i){
        cout<<a[i]<<" ";
    }
}

/****************************************************************************/

/*希尔排序:先将整个待排元素序列分割成若干子序列（由相隔某个“增量”的元素组成的）分别进行
直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，
再对全体元素进行一次直接插入排序（增量为1）。其时间复杂度为O(n^3/2),要好于直接插入排序的O(n^2) */
void ShellSort2(int *arr, int N)
{
    int i, j, increment;
    int tmp;
    for (increment = N / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < N; i++)
        {
            tmp = arr[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (arr[j - increment] > tmp)
                    arr[j] = arr[j - increment];
                else
                    break;
            }
            arr[j] = tmp;
        }

    }
}


// 桶排序
void TongSort(int a[], int n)
{
    // 寻找a[]中最大的元素
    int max = a[0];
    for (int j = 1; j < n; ++j) {
        if (max<a[j]) max = a[j];
    }

    int b[max+1] = {0};

    for (int i = 0; i < n; ++i) {
        ++b[a[i]];
    }

    for (int k = 0; k <= max; ++k) {
        for (int i = 0; i < b[k]; ++i) {
            cout<< k << " ";
        }
    }
}

// 冒泡排序
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (a[j+1] < a[j]){
                a[j] = a[j]^a[j+1];
                a[j+1] = a[j]^a[j+1];
                a[j] = a[j]^a[j+1];
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        cout << a[k] << " ";
    }
}

// 快速排序
void quickSort(int a[], int left, int right)
{

    if (left >= right)
        return;

    int key = a[left];
    int i = left, j = right;

    while(i < j){

        while ((i < j)&&(a[j] >= key))--j;
        while ((i < j)&&(a[i] <= key))++i;

        if (i < j) {
            int k = a[i];
            a[i] = a[j];
            a[j] = k;
        }

    }

    int k = a[i];
    a[i] = a[left];
    a[left] = k;

    quickSort(a, left, i-1);
    quickSort(a, i+1, right);

}

/************************************************************************************/
/* 堆是具有下列性质的完全二叉树:每个节点的值都大于或等于其左右孩子节点的值,称为大顶堆；
* 或者每个节点的值都小于或等于其左右孩子节点的值,称为小顶堆*/

/*堆排序就是利用堆进行排序的方法.基本思想是:将待排序的序列构造成一个大顶堆.此时,整个序列的最大值就是堆顶
* 的根结点.将它移走(其实就是将其与堆数组的末尾元素交换, 此时末尾元素就是最大值),然后将剩余的n-1个序列重新
* 构造成一个堆,这样就会得到n个元素的次大值.如此反复执行,便能得到一个有序序列了
*/
/* 时间复杂度为 O(nlogn),好于冒泡,简单选择,直接插入的O(n^2) */
#define leftChild(i) (2*(i) + 1)

void percDown(int *arr, int i, int N){
    int tmp = arr[i];
    int child;
    // 为了找到arr[i]的位置
    while(leftChild(i) < N){
        child = leftChild(i);

        if (child != N - 1 && arr[child+1] > arr[child]){
            ++child;
        }
        if (arr[child] > tmp){
            arr[i] = arr[child];
        } else{
            break;
        }
        i = child;
    }
    arr[i] = tmp;
}

void HeapSort(int *arr, int N){

    for (int i = N/2; i >= 0; --i) {
        percDown(arr, i, N);
    }

    // 每次把最大值放在树尾，并整理剩下的堆
    for (int j = N-1; j >= 0 ; --j) {
        swap2(arr[0], arr[j]);
        percDown(arr, 0, j);
    }
}

/**************************************************************************/

/* 简单选择排序(simple selection sort) 就是通过n-i次关键字之间的比较,从n-i+1
* 个记录中选择关键字最小的记录,并和第i(1<=i<=n)个记录交换之
* 尽管与冒泡排序同为O(n^2),但简单选择排序的性能要略优于冒泡排序 */

void SelectSort(int arr[], int num)
{
    int i, j, Mindex;
    for (i = 0; i < num; i++)
    {
        Mindex = i;
        for (j = i + 1; j < num; j++)
        {
            if (arr[j] < arr[Mindex])
                Mindex = j;
        }

        swap1(&arr[i], &arr[Mindex]);
    }
}

// 归并排序
//https://blog.csdn.net/morewindows/article/details/6678165

//将有二个有序数列a[first...mid]和a[mid+1...last]合并。
void mergearray(int a[], int first, int mid, int last)
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    vector<int> temp;
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m)
        temp.push_back(a[i++]);

    while (j <= n)
        temp.push_back(a[j++]);

    for (i = 0; i < temp.size(); i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid);    //左边有序
        mergesort(a, mid + 1, last); //右边有序
        mergearray(a, first, mid, last); //再将二个有序数列合并
    }
}

bool MergeSort(int a[], int n)
{
//    int *p = new int[n];
//    if (p == NULL)
//        return false;
    mergesort(a, 0, n - 1);
//    delete[] p;
    return true;
}
