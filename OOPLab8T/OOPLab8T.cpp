#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class ParametrizedQueue {
private:
    queue<T> elements;

public:
    void push(const T& item) {
        elements.push(item);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop();
        }
        else {
            cout << "Queue is empty. Cannot pop." << endl;
        }
    }

    T front() const {
        if (!elements.empty()) {
            return elements.front();
        }
        else {
            throw runtime_error("Queue is empty.");
        }
    }

    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

int main() {
    ParametrizedQueue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);

    while (!intQueue.empty()) {
        cout << intQueue.front() << " ";
        intQueue.pop();
    }

    cout << endl;

    ParametrizedQueue<string> stringQueue;
    stringQueue.push("Hello");
    stringQueue.push("World");
    stringQueue.push("!");

    while (!stringQueue.empty()) {
        cout << stringQueue.front() << " ";
        stringQueue.pop();
    }

    return 0;
}