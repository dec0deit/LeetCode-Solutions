class Node:

	def __init__(self, data):
		self.data = data 
		self.next = None 


class LinkedList:

	def __init__(self):
		self.head = None
		self.max_size = 10

	def is_empty(self):
		if self.head is None:
			return True
		
		return False

	def insert_node_at_position(self,data, position):
		new = Node(data)
		pointer = self.head
		counter = 1

		while pointer.next is not None:
			if counter == position:
				new.next = pointer.next
				pointer.next = new
				break
		
			counter += 1
			pointer = pointer.next

	def get_copy_data_at_front(self):
		if self.is_empty():
			return -1
		
		return self.head.data

	def get_copy_data_at_back(self):
		if self.is_empty():
			return -1
		head = self.head
		while head.next is not None:
			head = head.next
		
		return head.data

	def remove_node_at_begin(self):
		if self.is_empty():
			return False
		self.head = self.head.next
		return True

	def remove_node_at_end(self):
		if self.is_empty():
			return False
		head = self.head 
		if head.next is None:
			self.head = None
			return 
		while head.next.next is not None:
			head = head.next
		head.next = None
		return True

	def remove_node_at_specific_pos(self, position):
		if self.head is None:
			return
		if position == 0:
			self.head = self.head.next
			return self.head
		index = 0
		current = self.head
		prev = self.head
		temp = self.head
		while current is not None:
			if index == position:
				temp = current.next
				break
			prev = current
			current = current.next
			index += 1
		prev.next = temp
		return prev

	def push_at_start(self, new_data):
		new_nod = Node(new_data)
		new_nod.next = self.head
		self.head = new_nod
 
	def push_at_end(self, new_data):
		if self.head is None:
			self.push_at_start(new_data)
			return

		head = self.head
		while head.next is not None:
			head = head.next
		
		new_nod = Node(new_data)
		head.next = new_nod

	def printList(self):
		temp = self.head
		while (temp):
			print(temp.data,end=" ")
			temp = temp.next

	def node_contains_data(self,data):
		head = self.data
		while head is not None:
			if head.data == data:
				return head
			head = head.next

		return None

	def get_value_at_specific_index(self,index):
		head = self.head
		while head is not None and index > 0 :
			head = head.next
			index = index -1
		
		return -1 if head is None else head.data

	def check_linklist_full(self):
		head = self.head
		count = 0
		while head is not None:
			head = head.next
			count += 1
		
		if count >= self.max_size:
			return True

		return False


if __name__=='__main__':

	# Start with the empty list
	l = LinkedList()

	l.push_at_end(6)

	l.push_at_start(7)

	l.push_at_end(1)

	l.push_at_start(4)
	l.printList()
	print(l.is_empty())
	l.insert_node_at_position(8,2)
	l.printList()
	l.remove_node_at_specific_pos(2)
	print("After Removal")
	l.printList()
	print("Get value at front : ",l.get_copy_data_at_front())
	print("Get value at back : ",l.get_copy_data_at_back())
	print("Get value at 2 : ",l.get_value_at_specific_index(2))
	print(l.check_linklist_full())

