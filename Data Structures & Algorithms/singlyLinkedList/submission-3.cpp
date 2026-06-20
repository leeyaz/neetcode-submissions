class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    LinkedList() {

    }

    int get(int index) {
        Node* curr = head;
        for (int i=0; curr != nullptr; i++) {
            if (i==index) {
                return curr->data;
            }
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* next = head;
        head = new Node();
        head->data = val;
        head->next = next;
        if (!next) {
            tail = head;
        }
    }
    
    void insertTail(int val) {
        Node* prev = tail;
        tail = new Node();
        tail->data = val;
        tail->next = nullptr;
        if (prev) {
            prev->next = tail;
        } else {
            head = tail;
        }
    }

    bool remove(int index) {
        if (!head) return false;
        if (index==0) {
            Node* oldhead = head;
            head = head->next; 
            delete oldhead;
            oldhead = nullptr;
            return true;
        }
        
        Node* prev = head;
        for (int i=1; prev->next != nullptr; i++) {
            if (i==index) {
                Node* toDelete = prev->next;
                prev->next = toDelete->next;
                if (toDelete == tail) tail = prev;
                delete toDelete;
                toDelete = nullptr;
                return true;
            }
            prev = prev->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values = {};
        Node* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->data);
            curr = curr->next;
        }
        return values;
    }
};
