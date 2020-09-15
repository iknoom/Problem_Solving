#include <bits/stdc++.h>

using namespace std;
int n, q;
set<int> pos;
multiset<int> heap;

void insert_pos(int p) {
    auto upper = pos.upper_bound(p);
    if (pos.empty()) {
        pos.insert(p);
        return;
    }
    else if (pos.size() == 1){
        if ((*pos.begin()) < p) {
            heap.insert(p - (*pos.begin()));
        }
        else {
            heap.insert((*pos.begin()) - p);
        }
        pos.insert(p);
        return;
    }
    else if (upper == pos.begin()) {
        heap.insert((*upper) - p);
    }
    else if (upper == pos.end()) {
        upper--;
        heap.insert(p - (*upper));
    }
    else {
        auto lower = upper;
        lower--;
        int tmp = (*upper) - (*lower);
        heap.erase(heap.find(tmp));
        heap.insert((*upper) - p);
        heap.insert(p - (*lower));
    }
    pos.insert(p);
}

void del_pos(int p) {
    pos.erase(p);
    if (pos.empty()) {
        heap.clear();
        return;
    }
    else if (pos.size() == 1) {
        if ((*pos.begin()) < p) {
            heap.erase(heap.find(p - (*pos.begin())));
        }
        else {
            heap.erase(heap.find((*pos.begin()) - p));
        }
        return;
    }
    auto upper = pos.upper_bound(p);
    if (upper == pos.begin()) {
        heap.erase(heap.find((*upper) - p));
    }
    else if (upper == pos.end()) {
        upper--;
        heap.erase(heap.find(p - (*upper)));
    }
    else {
        auto lower = upper;
        lower--;
        int tmp = (*upper) - (*lower);
        heap.insert(tmp);
        heap.erase(heap.find((*upper) - p));
        heap.erase(heap.find(p - (*lower)));
    }
}

void debug(){
    for (auto iter = pos.begin(); iter != pos.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';
    for (auto iter = heap.begin(); iter != heap.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';
}

int get_val() {
    if (heap.empty()) {
        return 0;
    }
    int ret = (*pos.rbegin()) - (*pos.begin());
    return ret - (*heap.rbegin());
}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        insert_pos(p);
    }
    cout << get_val() << '\n';

    while (q--) {
        int t, p;
        cin >> t >> p;

        if (t == 0) {
            del_pos(p);
            cout << get_val() << '\n';
        }
        else {
            insert_pos(p);
            cout << get_val() << '\n';
        }
    }
}