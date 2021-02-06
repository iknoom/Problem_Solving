#include <cstdio>
#include <vector>
using namespace std;

void push_heap(vector<int>& heap, int new_value) {
    // 1. 일단 힙의 맨 끝에 원소를 추가한다.
    heap.push_back(new_value);
    // 2. 최대 힙의 성질을 만족할 때까지 부모 노드와 위치를 바꾼다.
    int idx = heap.size() - 1;
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        swap(heap[(idx - 1) / 2], heap[idx]);
        idx = (idx - 1) / 2;
    }
}

void pop_heap(vector<int>& heap) {
    // 1. 일단 힙의 마지막 노드를 루트에 덮어 씌운다.
    heap[0] = heap.back();
    heap.pop_back();
    // 2. 최대 힙의 성질을 만족할 때까지 가장 큰 자식 노드와 위치를 바꾼다.
    int here = 0;
    while (true) {
        int left = here * 2 + 1, right = here * 2 + 2;
        // 리프에 도달한 경우 break
        if (left >= heap.size()) break;
        // 가장 큰 자식 노드를 찾는다
        int next = here;
        if (heap[next] < heap[left])
            next = left;
        if (right < heap.size() && heap[next] < heap[right])
            next = right;
        // 최대 힙의 성질을 만족하므로 break
        if (next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}

int main() {
    int N;
    vector<int> heap;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        // x가 0이면 pop
        if (x == 0) {
            if (heap.empty()){
                printf("0\n");
            }
            else {
                printf("%d\n", heap[0]);
                pop_heap(heap);
            }
        }
        // x가 자연수면 push
        else {
            push_heap(heap, x);
        }
    }
}