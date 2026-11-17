
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = nullptr;   
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;
        while(second != nullptr){
            nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        ListNode* lijay = nullptr;
        ListNode* likbl = nullptr;
        ListNode* y = head;
        ListNode* x = prev;
        while(x != nullptr){
            likbl = y;
            lijay = y->next;
            y->next = x;
            y = lijay;
            lijay = x->next;
            x->next = y;
            x = lijay;
        }
    }
};

ListNode* createList(const vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    for (int x : values) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return dummy.next;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }
    cout << " -> nullptr\n";
}
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};

    ListNode* head = createList(values);

    cout << "Before: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "After:  ";
    printList(head);

    deleteList(head);

    return 0;
}
