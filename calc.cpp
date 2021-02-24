#include <cmath>
#include <iostream>
using namespace std;;
struct floatPOINT{
    double x;
    double y;
};
struct POINT{
    int x;
    int y;
};
int gcd(int m,int n){
if(m<n)swap(m,n); // make n the smallest of the two
    while(n>0){ 
        long r =m%n;
        m=n;
        n=r;
    }
    return m; //m is the g.c.d.
} 
void rop(){
        float rop;
    float bonus;
    float currentx;
    float currenty;
    POINT arr[20];
    int cX;
    int cY;
    bool graph[100][50];
    bool lineUsed;
    cout<<"whats the rate of pay? ";
    cin>>rop;
    cout<<endl<<"is there any bonus at the start (enter 0 if no) ";
    cin>>bonus;
    cout<<endl;
    for (int i = 0;i<20;i++){
        if (i != 1){
            cout<<i<<" Hours $"<<i*rop+bonus<<endl;
        }
        else{
            cout<<i<<" Hour $"<<i*rop+bonus<<endl;
        }
        arr[i].y = i*rop;
        arr[i].x = i;
    }
    currenty = arr[2].y - arr[1].y;
    currentx = arr[2].x - arr[1].x;
    cout<<"x : "<<currenty;
    cout<<endl<<"y : "<<currentx;
    cout<<endl<<"graph"<<endl;
    for(int x = 0;x<=100;x++){
        for(int y = 0;y<=100;y++){
            graph[x][y] = false;
        }
    }
    for (int i = 0; i < 20; i++){
        if (100 - arr[i].x > 0 && 100 - arr[i].y > 0){
        graph[100 - arr[i].x][100 - arr[i].y] = true;
        }
    }
    for (int y = 0; y <= 50; y++){
        for (int x = 100; x >= 0; x--){
            if (graph[x][y]){
                cout<<"0";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void e(){
    POINT compare;
    floatPOINT a;
    floatPOINT b;
    floatPOINT out;
    cout<<"x1 = ";
    cin>>a.x;
    cout<<endl<<"y1 = ";
    cin>>a.y;
    cout<<endl<<"x2 = ";
    cin>>b.x;
    cout<<endl<<"y2 = ";
    cin>>b.y;
    out.x = b.x - a.x;
    out.y = b.y - a.y;
    out.x = (b.x - a.x) / gcd((int)out.x,(int)out.y);
    out.y = (b.y - a.y) / gcd((int)(b.x - a.x),(int)out.y);
    while(fmod(out.x,1)){
        out.x *= 10;
        out.y *= 10;
    }
    while(fmod(out.y,1)){
        out.x *= 10;
        out.y *= 10;
    }
    cout<<out.y<<" over "<<out.x<<endl;
}
int main()
{   
    while(true){
        char in;
        std::cout << "enter r for rate of pay and e for equation (press q to quit)" << std::endl;
        in = getchar();
        if(in == 'r' || in == 'R'){
            rop();
        }
        else if(in == 'e' || in == 'E'){
            e();
        }
        else if(in == 'q' || in == 'Q'){
            return 0;
        }
    }
        
}
