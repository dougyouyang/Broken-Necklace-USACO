//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string>

using namespace std;
int a[700];

int decidea(int n){
    if(n==1){
        return false;
    }
    else if(n==2){
        return true;
    }
    return -1;
}

int main()
{
    char b;
    int n, sum, biggest=0;
    int i, j;
    bool blue, dou, decide;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> b;
        if(b=='r'){
            a[i]++, a[n+i]++;
        }
        else if(b=='b'){
            a[i]+=2, a[n+i]+=2;
        }
    }
    
    for(i=0;i<n;i++){
        sum=0;
        dou=false;
        decide=false;
        for(j=i;j<n+i;j++){
            if(a[j]==0 && !decide){
                sum++;
                continue;
            }
            else if(!decide){
                blue=decidea(a[j]);
                decide=true;
            }
            if(a[j]==1){
                if(blue&&!dou){
                    dou=true;
                    blue=false;
                }
                else if(blue&&dou){
                    break;
                }
            }
            else if(a[j]==2){
                if(!blue&&!dou){
                    dou=true;
                    blue=true;
                }
                else if(!blue&&dou){
                    break;
                }
            }
            sum++;
        }
        if(sum>biggest){
            biggest=sum;
        }
    }
    
    cout << biggest << endl;
    
    return 0;
}
