#include <bits/stdc++.h>
using namespace std;

// Cach 1: Dung pair<int, int>
// Moi event: pair<int, int> {time, type}
// type = 0: su kien dong
// type = 1: su kien mo

// Cach 2: Tao mot CTDL rieng
// Tao phep so sanh cho 2 event
//   + Cach 1: operator overload (tao phep < cho event)
//   + Cach 2: viet 1 function 
struct Event {
    int time;
    bool isOpen; // 1: mo, 0: dong

    bool operator < (Event other) {
        // return true if this < other
        // return false if this >= other
        if (time == other.time) {
           return isOpen < other.isOpen;
        }
        return time < other.time;
    }
};

// return true if a < b
bool cmp(Event a, Event b) {
    if (a.time == b.time) {
       return a.isOpen < b.isOpen;
    }
    return a.time < b.time;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 1; i <= n; i++) {
        int s, f;
        cin >> s >> f;

        events.push_back({s, true});
        events.push_back({f, false});
    }

    //sort(events.begin(), events.end());
    sort(events.begin(), events.end(), cmp);

    int numEvents = 0, res = 0; // so luong su kien
    for (auto e: events) {
        // e.time: thoi gian
        // e.isOpen: loai su kien

        if (e.isOpen == false) { // su kien dong
            numEvents--;    
        }        
        else if (e.isOpen == true) { // su kien mo
            numEvents++;
        }
        res = max(res, numEvents);
    }
    cout << res << endl;


    return 0;
}
