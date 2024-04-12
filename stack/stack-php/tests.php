<?php 
include "./stack.php";

$stack = new Stack(6);
$stack->push(new StackNode('A'));
$stack->push(new StackNode('B'));
$stack->push(new StackNode('C'));
$stack->push(new StackNode('D'));
$stack->push(new StackNode('E'));
$stack->push(new StackNode('F'));

echo "Stack Head: {$stack->peek()->value}\n";
echo "Poped Head: {$stack->pop()->value}\n";

echo "Stack Length: {$stack->length}\n";
echo "Max Stack Length: {$stack->max_length}\n";

$stack->echo();
