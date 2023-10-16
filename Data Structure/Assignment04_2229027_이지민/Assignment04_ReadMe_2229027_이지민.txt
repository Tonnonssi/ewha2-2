#1 
Problem : Change linked stack code implemented as a simple linked list to use a doubly linked list. 

Functions : 
init(LinkedStackType) : Initialize the LinkedStackType. 
is_empty(LinkedStackType): Returns True if the LinkedStackType is an empty stack, False otherwise. 
push(LinkedStackType, data) : Adds a new node to the LinkedStackType. 
pop(LinkedStackType) : Pops the most recent node value of a LinkedStackType.
peek(LinkedStackType): Peek the most recent node value of a LinkedStackType. 

How to run: 
1. push the value you want to add to the stack. 
2. use pop to get the most recent node, or peek to check the value if you just want to see it. 
3. compile the file and check the result. 

# 2
Problem: Increase the number of tellers from one to two in a banking simulation where customers are represented by queues. 

Variables 
element(id, arrival_time, service_time)
QueueType(queue arr, front, rear)
duration: the total time to run the simulation
arrival_prob: Probability that a customer will arrive
max_serv_time : Maximum time to receive service
clock: variable containing the current time
customers : Total number of customers 
served_customers: Number of customers served
waited_time: Total time customers have been waiting

Functions
random_num(): generates a random number between 0-1
is_empty(QueueType): Checks if the queue is empty.
is_full(QueueType): Checks if the queue is full.
enqueue(QueueType, item): adds a new node to the queue
dequeue(QueueType): deletes the oldest node
is_customer_arrived(): Returns True or False if the customer has arrived compared to arrival_prob.
insert_customer(arrival_time) : Assigns a unique number to a customer according to the arrival time, adds the arrival time, randomizes the service time, and puts it in the queue. Outputs information about the customer after this process. 
remove_customer(i) : Displays the arrival time, duration, and teller information for the customer who has finished the service and returns the remaining service time.
print_stat(): print the total number of customers served, the total time they have been waiting, the average time per person, and the number of customers still waiting.

How to run : 
1. design the simulation by customizing duration, arrival_porb, and max_serv_prob. 
2. Compile the file and check the result. 