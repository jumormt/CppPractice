//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//const int maxn = 50 + 5;
//const long maxc = 1000 + 1;
//
//int n;
//vector<vector<long>> pos(6, vector<long>(maxn));
//vector<long> uniqx, uniqy, uniqz;
//int color[maxn*2][maxn*2][maxn*2];
//int dx[] = {0, 0, 0, 0, -1, 1};
//int dy[] = {0, 0, -1, 1, 0, 0};
//int dz[] = {-1, 1, 0, 0, 0, 0};
//
//struct Cell
//{
//    int x, y, z;// 序号
//    Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
//
//    // color为2标记为立方体外围
//    void setVis() const {
//        color[x][y][z] = 2;
//    }
//
//    // 计算体积
//    int volume() const {
//        return (uniqx[x+1]-uniqx[x])*(uniqy[y+1]-uniqy[y])*(uniqz[z+1]-uniqz[z]);
//    }
//
//    // 下一步
//    Cell neighbor(int i) const {
//        return Cell(x+dx[i], y+dy[i], z+dz[i]);
//    }
//
//    // 是否越界
//    bool valid() const {
//        return x>=0 && x<uniqx.size()-1 && y>=0 && y<uniqx.size()-1 && z>=0 && z<uniqx.size()-1;
//    }
//
//    // 是否为立方体内部
//    bool solid() const {
//        return color[x][y][z] == 1;
//    }
//
//    // 计算表面积
//    int area(int i) const {
//        if (dx[i] != 0) return (uniqy[y+1]-uniqy[y])*(uniqz[z+1]-uniqz[z]);
//        else if(dy[i] != 0) return (uniqx[x+1]-uniqx[x])*(uniqz[z+1]-uniqz[z]);
//        else return (uniqx[x+1]-uniqx[x])*(uniqy[y+1]-uniqy[y]);
//    }
//
//    // 是否为外部
//    bool getVis() const {
//        return color[x][y][z] == 2;
//    }
//};
//
//// 对每一维进行离散化
//void discretize(vector<long>& vec)
//{
//    sort(vec.begin(), vec.end());
//    vec.erase(unique(vec.begin(), vec.end()), vec.end());
//}
//
//// 找到原坐标离散化后的新坐标
//int ID(vector<long> vec, int x0)
//{
//    return (int)(lower_bound(vec.begin(), vec.end(), x0) - vec.begin());
//}
//
////bfs 统计
//void floodfill(int& s, int& v)
//{
//    s = v = 0;
//    Cell c; c.setVis();
//    queue<Cell> Q; Q.push(c);
//
//    while (!Q.empty())
//    {
//        Cell now = Q.front(); Q.pop();
//        v += now.volume();      //统计雕塑外围的总体积
//        for (int i = 0; i < 6; i++)
//        {
//            Cell nxt = now.neighbor(i);
//            if (!nxt.valid()) continue;     //越界
//            if (nxt.solid()) s += now.area(i);      //now肯定是外围，nxt为内部则统计雕塑外围表面积
//            else if(!nxt.getVis())
//            {
//                nxt.setVis();
//                Q.push(nxt);
//            }
//        }
//    }
//    v = maxc*maxc*maxc - v;     //雕塑体积 ＝＝ 整个空间的体积－雕塑外围体积
//}
//
////int main()
////{
//////    freopen("/Users/apple/Desktop/in.txt", "r", stdin);
////
////    int t;
////    cin>>t;
////
////    while (t--)
////    {
////        cin>>n;
////        //存入边界坐标
////        uniqx.push_back(0);uniqx.push_back(maxc);
////        uniqy.push_back(0);uniqy.push_back(maxc);
////        uniqz.push_back(0);uniqz.push_back(maxc);
////
////        for (int i = 0; i < n; i++)
////        {
////            for (int j = 0; j < 6; ++j) {
////                for (int k = 0; k < n; ++k) {
////                    cin>>pos[j][k];
////                    if ((j == 0)||(j == 3)) uniqx.push_back(pos[j][k]);
////                    if ((j == 1)||(j == 4)) uniqy.push_back(pos[j][k]);
////                    if ((j == 2)||(j == 5)) uniqz.push_back(pos[j][k]);
////                }
////            }
////        }
////
////        discretize(uniqx), discretize(uniqy), discretize(uniqz);
////
////        memset(color, 0, sizeof(color));    //染色
////        for (int i = 0; i < n; i++)
////        {
////            int X1 = ID(uniqx, pos[0][i]), X2 = ID(uniqx, pos[3][i]);
////            int Y1 = ID(uniqy, pos[1][i]), Y2 = ID(uniqy, pos[4][i]);
////            int Z1 = ID(uniqz, pos[2][i]), Z2 = ID(uniqz, pos[5][i]);
////            for (int X = X1; X < X2; X++)       //对离散化后的坐标依次染色
////            {
////                for (int Y = Y1; Y < Y2; Y++)
////                {
////                    for (int Z = Z1; Z < Z2; Z++)
////                    {
////                        color[X][Y][Z] = 1;
////                    }
////                }
////            }
////        }
////
////        int s, v;
////        floodfill(s, v);
////        cout<<s<<" "<<v<<endl;
////    }
////
////    return 0;
////}