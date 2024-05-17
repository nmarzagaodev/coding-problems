use std::{cell::RefCell, rc::Rc};
// https://rtoch.com/posts/rust-doubly-linked-list/

// List Node:
pub struct ListNode<T> {
    data: T,
    next: Link<T>,
    prev: Link<T>,
}

impl<T> ListNode<T> {
    pub fn new(data: T) -> Self {
        Self {
            data,
            next: None,
            prev: None,
        }
    }
}

type Link<T> = Option<Rc<RefCell<ListNode<T>>>>;

// List:
#[derive(Default)]
pub struct DoublyLinkedList<T> {
    head: Link<T>,
    tail: Link<T>,
    size: usize,
}

impl<T> DoublyLinkedList<T> {
    pub fn new() -> Self {
        Self {
            head: None,
            tail: None,
            size: 0,
        }
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    pub fn push_back(&mut self, data: T) {
        let new_node = Rc::new(RefCell::new(ListNode::new(data)));
        if let Some(prev_tail) = self.tail.take() {
            prev_tail.borrow_mut().next = Some(Rc::clone(&new_node));
            new_node.borrow_mut().prev = Some(prev_tail);
            self.tail = Some(new_node);
            self.size += 1;
        }
        else {
            self.head = Some(Rc::clone(&new_node));
            self.tail = Some(new_node);
            self.size = 1;
        }
    }

    pub fn push_front(&mut self, data: T) {
        let new_node = Rc::new(RefCell::new(ListNode::new(data)));
        if let Some(prev_head) = self.head.take() {
            prev_head.borrow_mut().prev = Some(Rc::clone(&new_node));
            new_node.borrow_mut().next = Some(prev_head);
            self.head = Some(new_node);
            self.size += 1;
        }
        else {
            self.head = Some(Rc::clone(&new_node));
            self.tail = Some(new_node);
            self.size = 1;
        }
    }

    pub fn pop_back(&mut self) -> Option<T> {
        self.tail.take().map(|prev_tail| {
            self.size -= 1;
            match prev_tail.borrow_mut().prev.take() {
                Some(node) => {
                    node.borrow_mut().next = None;
                    self.tail = Some(node);
                }
                None => {
                    self.head.take();
                }
            }
            Rc::try_unwrap(prev_tail).ok().unwrap().into_inner().data
        })
    }

    pub fn pop_front(&mut self) -> Option<T> {
        self.head.take().map(|prev_head| {
            self.size -= 1;
            match prev_head.borrow_mut().next.take() {
                Some(node) => {
                    node.borrow_mut().prev = None;
                    self.head = Some(node);
                }
                node => {
                    self.head.take();
                }
            }
            Rc::try_unwrap(prev_head).ok().unwrap().into_inner().data
        })
    }
}

impl<T> Drop for DoublyLinkedList<T> {
    fn drop(&mut self) {
        while let Some(node) = self.head.take() {
            let _ = node.borrow_mut().prev.take();
            self.head = node.borrow_mut().next.take();
        }
        self.tail.take();
    }
}


