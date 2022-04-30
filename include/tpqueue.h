// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first;
    int last;

 public:
    TPQueue() :first(0), last(0) { }
    void push(T element) {
        if (last - first >= size) {
            throw std::string("Full!!!");
        } else {
            bool flag = false;
            int step = last;
            while (step != first) {
                if (el.prior > arr[(step - 1) % size].prior && step > first) {
                    arr[step % size] = arr[(step - 1) % size];
                    if (!flag) {
                        last++;
                        flag = true;
                    }
                } else {
                    if (!flag) {
                        last++;
                    }
                    arr[step % size] = el;
                    break;
                }
                step--;
            }
        }
    }
    T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
