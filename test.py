import heapq

class TopThreeStream:
    def __init__(self):
        self.heap = []
    
    def process_stream(self, value):
        if len(self.heap) < 3:
            heapq.heappush(self.heap, value)
        elif value > self.heap[0]:
            heapq.heappop(self.heap)
            heapq.heappush(self.heap, value)
    
    def get_top_three(self):
        return sorted(self.heap, reverse=True)

# Example usage
top_three = TopThreeStream()

# Process the stream
stream = [5, 2, 7, 3, 8, 1, 6, 9, 4]

for value in stream:
    top_three.process_stream(value)

# Get the top 3 values
print(top_three.get_top_three())  # Output: [9, 8, 7]
