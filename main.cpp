//
#include <iostream>
//
//#include "variable.h"
//#include <fstream>
//#include "classfile.h"
//#include "ManManager.h"
//#include <cstring>
//
//#include "Sort.h"
//#include "search.h"
//#include <memory>
//#include <unordered_map>
//#include <math.h>
//#include <algorithm>
//#include <set>
//#include <stack>
//#include "StrBlob.h"
//#include "Subject.h"
//#include "ConcreteObeserver.h"
//#include "ConcreteSubject.h"
//#include <unordered_set>
//#include <numeric>
//#include "allocTest.h"
//
//using namespace std;
//
//
//#include <cstdio>
//#include <stack>
//using namespace std;
#include <iostream>

#include <stack>
#include <cstring>
#include <vector>

using namespace std;


//
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    vector<int> v(n, 0);
//
//
//    return 0;
//}



#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n, 0);
    vector<int> ask(m, 0);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }

    vector<int> rank = v;
    sort(rank.begin(), rank.end());

    for (int j = 0; j < m; ++j) {
        cin >> ask[j];
    }

    vector<int> salary(n, 0);
    for (int k = 0; k < n; ++k) {

        salary[k] = v[k]-(find(rank.begin(), rank.end(), v[k])-rank.begin()+1);
    }

    for (int l = 0; l < m; ++l) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (salary[i] == ask[l]){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
