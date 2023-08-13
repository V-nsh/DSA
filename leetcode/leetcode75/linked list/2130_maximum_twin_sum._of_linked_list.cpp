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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *nextNode, *curr = head;
        while(curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
// the LL will always be even length here, so a twin is symmetrically on it's opposite side, for a 6 length ll, 0 and 5th nodes are twins, 1 and 4th and so on
// therefore the relation is n-i-1
// so look at this: 0 1 2 3 4 5
// now reverse from half since it's symmetric: 0 1 2 5 4 3
//  break it down into two: 0 1 2
//                   see :  5 4 3
    int pairSum(ListNode* head) {
        int maxSum = INT_MIN;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(slow && fast) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = slow;
        list2 = reverseList(list2);
        while(list1 && list2) {
            maxSum = max(maxSum, list1->val+list2->val);
            list1 = list1->next;
            list2 = list2->next;
        }
        return maxSum;
    }
};

int main() {
    ListNode* node6 = new ListNode(4);
    ListNode* node5 = new ListNode(2, node6);
    ListNode* node4 = new ListNode(2, node5);
    ListNode* node3 = new ListNode(3, node4);
    // ListNode* node2 = new ListNode(2, node3);
    // ListNode* node1 = new ListNode(1, node2);

    Solution sol;
    sol.printList(node3);

    // node1 = sol.oddEvenList(node1);
    // node1 = sol.reverseList(node1);
    // sol.printList(node1);
    cout << sol.pairSum(node3);
    return 0;
}