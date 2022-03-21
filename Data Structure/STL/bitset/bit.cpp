#include<bits/stdc++.h>
using namespace std;
long long cnt[10000005];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s,b;

    cin>>s;
    long long n = s.size(), vt, dem = 0;
    bool done = 0;
    for (int i =0 ; i < n; i++) {
        cnt[s[i]] ++;
    }
    for (int i = 'a'; i<= 'z'; i++) {
        if (cnt[i] % 2 == 1) {
            dem++;
            vt = i;
        }
    }

    cout << dem << endl;

    if (dem > 1) cout<<"NO SOLUTION";
    else {
        cout << vt << endl;
        for (int i = 1; i<= cnt[vt]; i++) b = b + (char)vt ;
    
        return 0;

        for (int i = 'a'; i<= 'z'; i++) {
            if ( i != vt && cnt[i] != 0 ) {
                for (int j = 1; j<= cnt[i]/ 2; j++) {
                    b = b + (char)i;
                    b = (char)i + b;
                }
            }
        }
        for (int i = 0; i< n; i++) cout<<b[i];
    }
    return 0;
}