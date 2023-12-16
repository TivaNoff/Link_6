#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head) {
        if (!head) return nullptr;

        head = reverseList(head);

        ListNode* current = head;
        int carry = 0;

        while (current) {
            int sum = current->val * 2 + carry;
            current->val = sum % 10;
            carry = sum / 10;

            if (!current->next && carry > 0) {
                current->next = new ListNode(carry);
                break;
            }

            current = current->next;
        }

        return reverseList(head);
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(8);
    head1->next->next = new ListNode(9);

    Solution solution;
    ListNode* result1 = solution.addTwoNumbers(head1);
    printList(result1);

    ListNode* head2 = new ListNode(9);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);

    ListNode* result2 = solution.addTwoNumbers(head2);
    printList(result2);

    return 0;
}
