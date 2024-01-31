import random

def partial_shuffle(lst, shuffle_fraction=0.5):
    """Shuffles part of the list based on the specified shuffle fraction."""
    num_elements_to_shuffle = int(len(lst) * shuffle_fraction)
    elements_to_shuffle = lst[:num_elements_to_shuffle]
    random.shuffle(elements_to_shuffle)
    lst[:num_elements_to_shuffle] = elements_to_shuffle
    return lst

numbers = list(range(100))
shuffled_numbers = partial_shuffle(numbers, shuffle_fraction=1)
numbers_str = ' '.join(str(num) for num in shuffled_numbers)
print(numbers_str)
