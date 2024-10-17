//cho n gói kẹo, mỗi gói kẹo có a[i] số kẹo. Hỏi có thể chia gói kẹo thành 2 phần với độ chênh lệch nhỏ nhất là bao nhiêu? không đc bóc gói kẹo ra
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> li;
int main()
{
    //freopen("thu.inp","r",stdin);
    int n;
    cin>>n;
    long long a[n+1];
    long long ma=0;
    vector<li> tong; //mảnh chứa các tổng có thể được tạo thành
    tong.push_back(li(0,-1));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ma+=a[i]; //tìm tổng lớn nhất
    }

    int nua=ma/2,giua=0; //nua là lượng kẹo chia đều lớn nhất

    for(int i=0;i<n;i++)
    {
        int x=tong.size();
        for(int j=0;j<x;j++)
            {
                long long y=a[i]+tong[j].first;
                tong.push_back(li(y,i));        //tính các tổng có thể đc tạo thành
                if(y==nua) {cout<<y<<" "<<ma-y;return 0;} //nếu tổng bằng nua -> cout luôn
                if(y<nua&&y>giua) giua=y;  //nếu ko có số gói kẹo bằng nửa thì tìm cái gần nửa nhất
            }

    }

    cout<<giua<<" "<<ma-giua;
    return 0;

}
