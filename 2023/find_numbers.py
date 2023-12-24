import re

def extract_numbers_with_indices(input_string):
    pattern = r'\d+'
    matches = re.finditer(pattern, input_string)
    result = []

    for match in matches:
        number = match.group(0)
        start_index = match.start()
        end_index = match.end()
        result.append((int(number), (start_index, end_index)))

    return result

# Example usage:
text = "Hello 123, the number is 456 and 789. End."
numbers_with_indices = extract_numbers_with_indices(text)

print("Numbers and their indices:")
for number, indices in numbers_with_indices:
    print(f"Number: {number}, Indices: {indices}")
