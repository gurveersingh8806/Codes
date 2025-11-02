class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        if (size == 0) tail = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if (size == 0) head = node;
        else tail->next = node;
        tail = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) return addAtHead(val);
        if (index == size) return addAtTail(val);

        Node* temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            if (--size == 0) tail = nullptr;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* del = temp->next;
        temp->next = del->next;
        if (index == size - 1) tail = temp;
        delete del;
        size--;
    }
};
