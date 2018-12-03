//
// Created by 程潇 on 2018/9/19.
//
#include <vector>
#include "allocTest.h"

void allocTest() {

    const int n = 10;

    allocator<string> alloc;
    auto const p = alloc.allocate(n);


    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hell");
    cout << *(q - 1) << endl;

    //销毁
    while (q != p) alloc.destroy(--q);


    // 将分配的内存归还给系统
    alloc.deallocate(p, n);

//    vector<int> vi{4,2,3};

//    auto p2 = alloc.allocate(vi.size()*2);
//    auto q2 = uninitialized_copy(vi.begin(), vi.end(), p2);
//    uninitialized_fill_n(q2, vi.size(), 47);
//    cout<<*p2;
//    for (auto i = p2;  i != q2 ; ++i) {
//        cout<<*i<<" ";
//    }
    cout << "你好";

}