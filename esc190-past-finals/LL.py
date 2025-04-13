class Node: 
	def __init__(self, data): 
		self.data = data
		self.next = None 

class LL: 
	def __init__(self):
		self.head = None 
		
	def insert(self, ind, data):
		new_node = Node(data) 
		
		if self.head is None:
			self.head = new_node
		else: 
			if ind == 0: 
				head_save = self.head 
				self.head = new_node 
				self.head.next = head_save 
			else: 
				cur = self.head
				for i in range(ind -1):
					cur = cur.next 
					cur.next, new_node.next = new_node, cur.next
	def is_in(self, data):
		cur = self.head 
		while cur: 
			if cur.data == data: 
				return True 
			cur = cur.next 
		return False 
	
	def remove(self, data):
		#removes the first node with data = data in the list 
		if self.head.data == data: 
			self.head = self.head.next 
			return 
		cur = self.head 
		#keep traversing the nodes 
		#if it hits cur.next != None -> did not find data
		#if cur.next.data = data -> val found! 
		while cur.next is not None and cur.next.data != data:
			cur = cur.next
		
		if cur.next is None: 
			print("error trying to remove") 
			return 
		
		#skips a node 
		cur.next = cur.next.next 
	