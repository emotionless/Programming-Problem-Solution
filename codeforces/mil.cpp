#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

#define dist(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;

int main(){
   double x1,y1,x2,y2,x3,y3,x4,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    double area=1/2.0*dist(x1,y1,x3,y3)*dist(x2,y2,x4,y4);
    double x12=(x1+x2)/2.0;
    double y12=(y1+y2)/2.0;

    double x23=(x3+x2)/2.0;
    double y23=(y3+y2)/2.0;

    double x14=(x1+x4)/2.0;
    double y14=(y1+y4)/2.0;

    double x34=(x3+x4)/2.0;
    double y34=(y3+y4)/2.0;

    double ff,ss,dif=1000000000.0;

    double tmp,rtmp,ans1,ans2;
    //
    tmp=1/2.0*dist(x1,y1,x23,y23)*dist(x14,y14,x2,y2);
    rtmp=area-tmp;
    if(fabs(rtmp-tmp)<dif){
        dif=fabs(rtmp-tmp);
        ans1=tmp;
        ans2=rtmp;
    }

    tmp=1/2.0*dist(x1,y1,x34,y34)*dist(x12,y12,x4,y4);
    rtmp=area-tmp;
    if(fabs(rtmp-tmp)<dif){
        dif=fabs(rtmp-tmp);
        ans1=tmp;
        ans2=rtmp;
    }

    tmp=1/2.0*dist(x1,y1,x3,y3)*dist(x2,y2,x34,y34);
    rtmp=area-tmp;
    if(fabs(rtmp-tmp)<dif){
        dif=fabs(rtmp-tmp);
        ans1=tmp;
        ans2=rtmp;
    }

    tmp=1/2.0*dist(x1,y1,x3,y3)*dist(x4,y4,x23,y23);
    rtmp=area-tmp;
    if(fabs(rtmp-tmp)<dif){
        dif=fabs(rtmp-tmp);
        ans1=tmp;
        ans2=rtmp;
    }

    tmp=1/2.0*dist(x1,y1,x3,y3)*dist(x4,y4,x23,y23);
    rtmp=area-tmp;
    if(fabs(rtmp-tmp)<dif){
        dif=fabs(rtmp-tmp);
        ans1=tmp;
        ans2=rtmp;
    }

    return 0;
}
