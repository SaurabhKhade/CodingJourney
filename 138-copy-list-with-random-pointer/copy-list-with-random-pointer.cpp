/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;

        map[NULL] = NULL;

        Node* temp = head;
        while (temp != NULL) {
            map[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL) {
            Node* newNode = map[temp];
            newNode->next = map[temp->next];
            newNode->random = map[temp->random];

            temp = temp->next;
        }

        return map[head];
    }
};