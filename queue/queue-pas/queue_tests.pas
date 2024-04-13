program queue_tests;

uses 
  queue_functions,
  sysutils;

var
  my_queue: QueuePtr;
  first_value: QueueNodePtr;

begin
  writeln('Testing Creting a Queue.');

  my_queue := Queue_create();

  Queue_enqueue(my_queue, QueueNode_create('A'));
  Queue_enqueue(my_queue, QueueNode_create('B'));
  Queue_enqueue(my_queue, QueueNode_create('C'));

  Queue_print(my_queue);

  first_value := Queue_dequeue(my_queue);
  writeln(format('Dequeued Value: %s', [first_value^.value]));

  Queue_print(my_queue);

  dispose(my_queue);
end.