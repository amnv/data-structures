#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Heap {
    private:
        vector<T> v;
    public:
       void insert(T t) {
            //insert in the end
            v.push_back(t);

            //reorganize array
            bool flag = false;
            for(int i = v.size() -1; i >= 0; i = (i >> 1) - 1) {
                if (i == 0) {
                    if (flag) break;

                    flag = true;
                }
                int father = ceil(i/2.0) - 1;
                if (v[i] < v[father]) {
                    swap(v[i], v[father]);
                }
            }
            printHeap();
        }        

        T top() {
            return v[0];
        }

        void remove() {
            //remove top
            swap(v.front(), v.back());
            v.pop_back();

            for (int i = 0; i < v.size(); i++) {
                int lower_child = lower((i << 1) + 1, (i << 1) + 2);
                if (lower_child < v.size()
                    && v[i] > v[lower_child]) {
                    swap(v[i], v[lower_child]);
                } else {
                    break;
                }
                
            }

            printHeap();
        }

        int lower(int left_child, int right_child) {
            if (right_child >= v.size()) return left_child;

            if (v[left_child] < v[right_child]) {
                return left_child;
            }

            return right_child;
        }

        void printHeap() {
            for (auto& i : v) {
                cout << i << " ";
            }
            cout << "\n------------------" << endl;
        }
};



int main() {
    
    Heap<int> heap;
    heap.insert(40);//4
    heap.insert(30);//3
    heap.insert(00);//0
    heap.insert(20);//2
    heap.insert(10);//1


    cout << "\nremove\n" << endl;
    heap.remove();
    heap.remove();
    heap.remove();
    heap.remove();
    heap.remove();
}