// Linked List in JavaScript

class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

class List {
    constructor() {
        this.head = null;
    }

    is_empty() {
        return this.head == null;
    }

    get_length() {
        if (this.is_empty) {
            return 0;
        }

        counter = 0;
        tmp = this.head;
        while (tmp != null) {
            counter += 1;
            tmp = tmp.next;
        }

        return counter;
    }

    push_back(node) {
        if (this.is_empty()) {
            this.head = node;
        }

        tmp = this.head;
        while(tmp.next != null) tmp = tmp.next;

        tmp.next = node;
    }

    push_front(node) {
        if (this.is_empty()) {
            this.head = node;
        }

        node.next = this.head
        this.head = node
    }

    pop_front() {
        if (this.is_empty()) {
            return null;
        }

        target = this.head;
        this.head = this.head.next;

        return target;
    }

    pop_val(target) {
        if (this.is_empty()) {
            return null;
        }

        curr = this.head;
        prev = null;

        while(curr != null) {
            if (curr.val == target) {
                prev.next = curr.next;
            }

            prev = curr;
            curr = curr.next;
        }
    }

    pop_back() {
        if (this.is_empty()) {
            return null;
        }

        tmp = this.head;
        while(tmp.next.next != null) tmp = tmp.next;

        target = tmp.next.val;
        tmp.next = null;

        return target;
    }
}