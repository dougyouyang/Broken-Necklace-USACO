/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
