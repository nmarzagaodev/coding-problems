const { List, ListNode } = require('./list.js');

function test_isEmpty() {
    const mylist = new List()
    console.assert(mylist.isEmpty() == true, "isEmpty Failed");
}

function test_pushBack() {
    const mylist = new List()

    for (let i = 1; i < 6; i++) {
        mylist.pushBack(new ListNode(i));
    }

    console.assert(mylist.head.val == 1, "pushBack Failed");
    console.assert(mylist.head.next.val == 2, "pushBack Failed");
    console.assert(mylist.head.next.next.val == 3, "pushBack Failed");
    console.assert(mylist.head.next.next.next.val == 4, "pushBack Failed");
    console.assert(mylist.head.next.next.next.next.val == 5, "pushBack Failed");
}

function test_pushFront() {
    const mylist = new List()

    for (let i = 1; i < 6; i++) {
        mylist.pushFront(new ListNode(i));
    }

    console.assert(mylist.head.val == 5, "pushFront Failed");
    console.assert(mylist.head.next.val == 4, "pushFront Failed");
    console.assert(mylist.head.next.next.val == 3, "pushFront Failed");
    console.assert(mylist.head.next.next.next.val == 2, "pushFront Failed");
    console.assert(mylist.head.next.next.next.next.val == 1, "pushFront Failed");
}

function test_getLength() {
    const mylist = new List()

    for (let i = 1; i < 6; i++) {
        mylist.pushBack(new ListNode(i));
    }

    console.assert(mylist.getLength() == 5, "getLength Failed")
}

function test_forEach() {
    const mylist = new List()
    let total = 0;

    for (let i = 1; i < 6; i++) {
        mylist.pushBack(new ListNode(i));
    }

    mylist.forEach(function(head) {
        total += head.val;
    });

    console.assert(total == 15, "forEach Failed");
}






test_isEmpty()
test_pushBack();
test_pushFront();
test_getLength();
test_forEach();
