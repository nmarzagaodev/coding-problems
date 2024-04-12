<?php
class StackNode {
    function __construct($value = null, $next = null) {
        $this->value = $value;
        $this->next  = $next;
    }
}

class Stack {
    function __construct(int $max_length) {
        $this->head = null;
        $this->length = 0;
        $this->max_length = $max_length; 
    }

    private function is_empty(): bool {
        return $this->head == null && $this->length == 0;
    }

    function peek(): StackNode {
        return $this->head;
    }

    function push(StackNode $new_node): void {
        if ($this->length == $this->max_length) {
            echo "\nError: Stack is full!\n";
            return;
        }

        $new_node->next = $this->head; 
        $this->head = $new_node;
        $this->length += 1;
    }

    function pop(): StackNode {
        if ($this->is_empty()) {
            echo "\nError: Stack is already empty!\n";
            return new StackNode();
        }

        $target = $this->head;
        $this->head = $this->head->next;

        return $target;
    }

    function echo(): void {
        echo "Echoing Stack: ";
        $tmp = $this->head;

        echo "[ head -> ";
        while ($tmp != null) {
            echo "{$tmp->value}, ";
            $tmp = $tmp->next;
        }
        echo "]\n";
    }
}
