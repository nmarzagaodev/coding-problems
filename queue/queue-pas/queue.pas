program QueueImplementation;

uses sysutils;

type
  QueueNodePtr = ^QueueNode;
  QueuePtr     = ^Queue;

  QueueNode = record
    value: string;
    next:  QueueNodePtr;
  end;  

  Queue = record
    first: QueueNodePtr;
    last:  QueueNodePtr;
  end;

function QueueNode_create(node_value: string): QueueNodePtr;
var
  new_queueNode: QueueNodePtr;
begin
  new(new_queueNode);

  if new_queueNode = nil then
  begin
    QueueNode_create := nil;
    exit;
  end;

  with new_queueNode^ do
  begin
    value := node_value;
    next  := nil;
  end;

  QueueNode_create := new_queueNode;
end;

function Queue_create(): QueuePtr;
var
  new_queue: QueuePtr;
begin
  new(new_queue);

  if new_queue = nil then
  begin 
    Queue_create := nil;
    exit;
  end;

  with new_queue^ do
  begin
    first := nil;
    last  := nil;
  end;

  Queue_create := new_queue;
end;

function Queue_isEmpty(my_queue: QueuePtr): boolean;
begin
  if my_queue = nil then
  begin
    Queue_isEmpty := true;
    exit;
  end;

  with my_queue^ do
    if (first = nil) and (last = nil) then
      Queue_isEmpty := true
    else 
      Queue_isEmpty := false;
end;

procedure Queue_enqueue(my_queue: QueuePtr; new_node: QueueNodePtr);
begin
  if Queue_isEmpty(my_queue) then
  begin
    with my_queue^ do
    begin
      first := new_node;
      last  := new_node;
    end;
    exit;
  end;

  with my_queue^ do
  begin
    last^.next := new_node;
    last       := new_node;
  end;
end;

function Queue_dequeue(my_queue: QueuePtr): QueueNodePtr;
var 
  dequeued_value: QueueNodePtr;

begin
if Queue_isEmpty(my_queue) then
  begin
    Queue_dequeue := nil;
    exit;
  end;

  with my_queue^ do
  begin
    dequeued_value := first;
    first := first^.next;
  end;

  Queue_dequeue := dequeued_value;
end;

procedure Queue_print(my_queue: QueuePtr);
var 
  tmp_ptr: QueueNodePtr;
begin
  if Queue_isEmpty(my_queue) then
  begin
    writeln('Error: Cannot print an empty queue!');
    exit;
  end;

  tmp_ptr := my_queue^.first;

  while tmp_ptr <> nil do
  begin
    writeln(tmp_ptr^.value);
    tmp_ptr := tmp_ptr^.next;
  end;
end;

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