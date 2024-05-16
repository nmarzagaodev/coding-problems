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

    isEmpty() {
        return this.head == null;
    }

    getLength() {
        if (this.isEmpty()) {
            return 0;
        }

        let counter = 0;
        let tmp = this.head;
        while (tmp != null) {
            counter += 1;
            tmp = tmp.next;
        }

        return counter;
    }

    pushBack(node) {
        if (this.isEmpty()) {
            this.head = node;
            return;
        }

        let tmp = this.head;
        while(tmp.next != null) tmp = tmp.next;

        tmp.next = node;
    }

    pushFront(node) {
        if (this.isEmpty()) {
            this.head = node;
            return
        }

        node.next = this.head
        this.head = node
    }

    popFront() {
        if (this.isEmpty()) {
            return null;
        }

        let target = this.head;
        this.head = this.head.next;

        return target;
    }

    popVal(target) {
        if (this.isEmpty()) {
            return null;
        }

        let curr = this.head;
        let prev = null;

        while(curr != null) {
            if (curr.val == target) {
                prev.next = curr.next;
                return target;
            }

            prev = curr;
            curr = curr.next;
        }
        return null;
    }

    popBack() {
        if (this.isEmpty()) {
            return null;
        }

        let tmp = this.head;
        while(tmp.next.next != null) tmp = tmp.next;

        let target = tmp.next.val;
        tmp.next = null;

        return target;
    }

    forEach(func) {
        for (let current = this.head; current != null; current = current.next) func(current); 
    }
}

module.exports = { List, ListNode };