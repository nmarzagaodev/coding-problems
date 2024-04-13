program QueueImplementation;

type
  QueueNodePtr = ^QueueNode;

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

var
  my_queueNode: QueueNodePtr;

begin
  writeln('Testing Creting a Queue Node.');

  my_queueNode := QueueNode_create('A');
  writeln(my_queueNode^.value);

  if my_queueNode^.next = nil then
    writeln('Next is nil!');
end.