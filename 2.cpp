#include<bits/stdc++.h>
using namespace std;
vector<int> A,B,A_color,B_color;

int  main()
{
    char ls[1000];
    int res_=1,res=-1;
    int _res=1,Res=-1;
    int num=0;
    int black,white;
    int black_color,white_color;
    int cnt1=0,cnt2=0;
    
    for(int i=0;i < 32;i ++) cin >> ls[i];

    for(int i=6;i <= 14;i += 2) 
    {
        if(ls[i] == 'T') A.push_back(10);
        else if(ls[i] == 'J')  A.push_back(11);
        else if(ls[i] == 'Q')  A.push_back(12);
        else if(ls[i] == 'K')  A.push_back(13);
        else if(ls[i] == 'A')  A.push_back(14);
        else A.push_back(ls[i]-'0'); 
    }
    
    sort(A.begin(),A.end());
    for(int i=0;i < 5;i ++)
    {
        for(int j=0;j < 5;j ++)
        {
            if(j == i) continue;
            if(A[i] == A[j]) res_++;
        }
        res=max(res,res_);
        res_=1;
    }
    if(res == 1)
    {
        for(int i=0;i <= 3;i ++)
        {
            if(A[i+1]-A[i] == 1) num++;
        }
        if(num == 4) black=5;
        else black=1;
    }
    else if(res == 2)
    {
        for(int i=0;i < 5;i ++)
        {
            for(int j=0;j < 5;j ++)
            {
                if(j == i) continue;
                if(A[j] != A[i] && A[j] != A[j-1]) _res++;
            }
            Res=max(Res,_res);
            _res=1;
        }
        if(Res == 4) black=2;
        else if(Res == 3) black=3;
    }
    else if(res == 3) black=4;
    else if(res == 4)
    {
        cnt1=1;
        black=3;
    }
    res_=1,res=-1;
    _res=1,Res=-1;
    num=0;
    for(int i=22;i <= 30;i += 2) 
    {
        if(ls[i] == 'T') B.push_back(10);
        else if(ls[i] == 'J')  B.push_back(11);
        else if(ls[i] == 'Q')  B.push_back(12);
        else if(ls[i] == 'K')  B.push_back(13);
        else if(ls[i] == 'A')  B.push_back(14);
        else B.push_back(ls[i]-'0'); 
    }
    
    sort(B.begin(),B.end());
    for(int i=0;i < 5;i ++)
    {
        for(int j=0;j < 5;j ++)
        {
            if(j == i) continue;
            if(B[i] == B[j]) res_++;
        }
        res=max(res,res_);
        res_=1;
    }
    if(res == 1)
    {
        for(int i=0;i <= 3;i ++)
        {
            if(A[i+1]-A[i] == 1) num++;
        }
        if(num == 4) white=5;
        else white=1;
    }
    else if(res == 2)
    {
        for(int i=0;i < 5;i ++)
        {
            for(int j=0;j < 5;j ++)
            {
                if(j == i) continue;
                if(B[j] != B[i] && B[j] != B[j-1]) _res++;
            }
            Res=max(Res,_res);
            _res=1;
        }
        if(Res == 4) white=2;
        else if(Res == 3) white=3;
    }
    else if(res == 3) white=4;
    else if(res == 4)
    {
        cnt2=1;
        white=3;
    }

    res_=1,res=0;

    for(int i=7;i <= 15;i += 2) 
    {
        if(ls[i] == 'D') A_color.push_back(1);
        else if(ls[i] == 'S')  A_color.push_back(2);
        else if(ls[i] == 'H')  A_color.push_back(3);
        else if(ls[i] == 'C')  A_color.push_back(4);
    }
    for(int i=0;i < 5;i ++)
    {
        for(int j=0;j < 5;j ++)
        {
            if(j == i) continue;
            if(A_color[i] == A_color[j]) res_++;
        }
        res=max(res,res_);
        res_=1;
    } 
    
    if(res == 5) black_color=6;
    else black_color=0;

    res_=1,res=0;

    for(int i=23;i <= 31;i += 2) 
    {
        if(ls[i] == 'D') B_color.push_back(1);
        else if(ls[i] == 'S')  B_color.push_back(2);
        else if(ls[i] == 'H')  B_color.push_back(3);
        else if(ls[i] == 'C')  B_color.push_back(4);
    }
    for(int i=0;i < 5;i ++)
    {
        for(int j=0;j < 5;j ++)
        {
            if(j == i) continue;
            if(B_color[i] == B_color[j]) res_++;
        }
        res=max(res,res_);
        res_=1;
    } 
    if(res == 5) white_color=6;
    else white_color=0;

    int num1=black+black_color;
    int num2=white+white_color;
    if(num1 > num2) cout<<"Black wins"<<endl;
    if(num2 > num1) cout<<"White wins"<<endl;
    if(num1 == num2)
    {
        if(black == 1)
        {
            int k=0;
            for(int i=4;i >= 0;i --)
            {
                if(A[i] > B[i])
                {
                    cout<<"Black wins"<<endl;
                    break;
                }
                if(A[i] < B[i])
                {
                    cout<<"White wins"<<endl;
                    break;
                }
                else k++;
            }
            if(k == 5) cout<<"Tie"<<endl;
        }
        else if(black == 2)
        {
            int a,b;
            int k=0;
            for(int i=0;i < 5;i ++)
            {
                if(A[i] == A[i+1])
                {
                    a=A[i];
                    A[i]=-1;
                    A[i+1]=-1;
                }
                if(B[i] == B[i+1])
                {
                    b=B[i];
                    B[i]=-1;
                    B[i+1]=-1;
                }
            }
            sort(A.begin(),A.end());
            sort(B.begin(),B.end());
            if(a > b) cout<<"Black wins"<<endl;
            else if(a < b) cout<<"White wins"<<endl;
            else
            {
                for(int i=4;i >= 2;i --)
                {
                    if(A[i] > B[i])
                    {
                        cout<<"Black wins"<<endl;
                        break;
                    }
                    if(A[i] < B[i])
                    {
                        cout<<"White wins"<<endl;
                        break;
                    }
                    else k++;
                }
                if(k == 3) cout<<"Tie"<<endl;
            }
            
        }
        else if(black == 3)
        {
            int a1,a2,b1,b2;
            int k;
            if(cnt1 == 0)
            {
                for(int i=0;i < 5;i ++)
                {
                    if(A[i] == A[i+1])
                    {
                        a1=A[i];
                        A[i]=-1;
                        A[i+1]=-1;
                    }
                    if(B[i] == B[i+1])
                    {
                        b1=B[i];
                        B[i]=-1;
                        B[i+1]=-1;
                    }
                }
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                for(int i=2;i < 5;i ++)
                {
                    if(A[i] == A[i+1])
                    {
                        a2=A[i];
                        A[i]=-1;
                        A[i+1]=-1;
                    }
                    if(B[i] == B[i+1])
                    {
                        b2=B[i];
                        B[i]=-1;
                        B[i+1]=-1;
                    }
                }
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                if(a2 > b2) cout<<"Black wins"<<endl;
                else if(a2 < b2) cout<<"White wins"<<endl;
                else
                {
                    if(a1 > b1) cout<<"Black wins"<<endl;
                    else if(a1 < b1) cout<<"White wins"<<endl;
                    else
                    {
                        if(A[4] > B[4]) cout<<"Black wins"<<endl;
                        else if(A[4] < B[4]) cout<<"White wins"<<endl;
                        else cout<<"Tie"<<endl;
                    }
            
                }
                
            }
            else
            {
                int c,d;
                for(int i=0;i < 5;i ++)
                {
                    if(A[i] == A[i+1])
                    {
                        c=A[i];
                        A[i]=-1;
                        A[i+1]=-1;
                    }
                    if(B[i] == B[i+1])
                    {
                        d=B[i];
                        B[i]=-1;
                        B[i+1]=-1;
                    }
                }
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                if(c > d) cout<<"Black wins"<<endl;
                else if(c < d) cout<<"White wins"<<endl;
                else
                {
                    if(A[4] > B[4]) cout<<"Black wins"<<endl;
                    if(A[4] < B[4]) cout<<"White wins"<<endl;
                    else cout<<"Tie"<<endl;
                }
            }
            
        }
        else if(black == 4)
        {
            int c1,d1;
            for(int i=0;i < 5;i ++)
            {
                if(A[i]==A[i+1]) c1=A[i];
                if(B[i]==B[i+1]) d1=B[i];
            }
            if(c1 > d1) cout<<"Black wins"<<endl;
            else if(c1 < d1) cout<<"White wins"<<endl;
            else cout<<"Tie"<<endl;
        }
        else if(black == 5)
        {
            if(A[4] > B[4]) cout<<"Black wins"<<endl;
            else if(A[4] < B[4]) cout<<"White wins"<<endl;
            else cout<<"Tie"<<endl;
        }
    }

    system("pause");
    return 0;
}