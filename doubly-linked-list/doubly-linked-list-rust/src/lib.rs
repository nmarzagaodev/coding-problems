mod doubly_linked_list;
use crate::doubly_linked_list::DoublyLinkedList;
// https://rtoch.com/posts/rust-doubly-linked-list/

#[test]
fn is_working() {
    let mut list = DoublyLinkedList::new();
    for i in 0..10 {
        list.push_back(i);
    }
}
