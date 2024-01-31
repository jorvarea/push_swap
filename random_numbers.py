import random

def partial_shuffle(lst, shuffle_fraction=0.5):
    """Shuffles part of the list based on the specified shuffle fraction."""
    # Calculate the number of elements to shuffle
    num_elements_to_shuffle = int(len(lst) * shuffle_fraction)
    
    # Extract the elements to shuffle
    elements_to_shuffle = lst[:num_elements_to_shuffle]
    
    # Shuffle the extracted elements
    random.shuffle(elements_to_shuffle)
    
    # Replace the shuffled elements back into the list
    lst[:num_elements_to_shuffle] = elements_to_shuffle
    return lst

# Example usage:
numbers = list(range(500))
shuffled_numbers = partial_shuffle(numbers, shuffle_fraction=0.3)
numbers_str = ' '.join(str(num) for num in shuffled_numbers)
print(numbers_str)
