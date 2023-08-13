#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr || head==nullptr) {
            return NULL;
        }
        // since fast pointer moves twice as fast, it will reach the end by the time slow one will reach half.
        auto slow = head;
        auto fast = head->next->next;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }

public:
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->val << "->";
            current = current->next;
        }
        cout << endl;
    }

public:
    ListNode* createLinkedListFromArray(vector<int>& arr) {
        int n=arr.size();
        if(n==0) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        for(int i = 0; i<n; i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }

        return head;
    }

public:
    ListNode* insertNodeAtEnd(ListNode*& head, int x) {
        ListNode* newNode = new ListNode(x);
        if(head==nullptr) {
            return newNode;
        }

        ListNode* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;

        return head;
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head; //because here we can think of indexing from 1, 2, ..
        ListNode* even = head->next; //so even will be the second node
        ListNode* connect_this_even_to_odd = head->next;
        while(odd->next && even->next) {
            // the next odd number will be next to even
            odd->next = even->next;
            odd = odd->next;

            // and the next even will be one after the current even, ie after the next odd element.
            even->next = odd->next;
            even = even->next;
        }
        // finally we make the last odd element point to first even node.
        odd->next = connect_this_even_to_odd;
        return head;
    }
};

int main() {
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    sol.printList(node1);

    node1 = sol.oddEvenList(node1);
    sol.printList(node1);
    return 0;
}