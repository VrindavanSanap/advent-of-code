def surrounding_coordinates(start, end):
    if start[1] != end[1]:
        raise ValueError("Start and end coordinates do not form a horizontal line.")

    coordinates = []
    for y in range(start[1] - 1, start[1] + 2):
        min_x = min(start[0], end[0])
        max_x = max(start[0], end[0])

        for x in range(min_x - 1, max_x + 2):
            coordinates.append((x, y))

    return coordinates

# Example usage:
start_coords = (2, 3)
end_coords = (2, 3)  # Line length of one
horizontal_line_coords = surrounding_coordinates(start_coords, end_coords)
print("Coordinates surrounding the horizontal line:")
print(horizontal_line_coords)

