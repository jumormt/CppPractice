
#include <iostream>

#include <stack>
#include <cstring>

#include "Sort.h"
#include "search.h"
#include <memory>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <stack>
#include "StrBlob.h"
#include "Subject.h"
#include "ConcreteObeserver.h"
#include "ConcreteSubject.h"
#include <unordered_set>
#include <numeric>
#include "allocTest.h"

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = m.size();

        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(m[i][j], m[j][i]);

        for(int i=0; i<n; i++)
            reverse(m[i].begin(), m[i].end());
    }
};

int main()
{


    cout<<"helloppP";
    return 0;

}


