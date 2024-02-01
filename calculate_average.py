import random
import subprocess

def partial_shuffle(lst, shuffle_fraction=0.5):
    """Shuffles part of the list based on the specified shuffle fraction."""
    num_elements_to_shuffle = int(len(lst) * shuffle_fraction)
    elements_to_shuffle = lst[:num_elements_to_shuffle]
    random.shuffle(elements_to_shuffle)
    lst[:num_elements_to_shuffle] = elements_to_shuffle
    return lst

def execute_push_swap(numbers):
    """Execute the push_swap program with the given numbers and return the number of operations."""
    numbers_str = ' '.join(str(num) for num in numbers)
    result = subprocess.run(f'./bin/push_swap {numbers_str} | wc -l', shell=True, stdout=subprocess.PIPE)
    num_operations = int(result.stdout.strip())
    return num_operations

# Main part of the script
total_operations100 = 0
total_operations500 = 0
iterations = 100
for _ in range(iterations):
    numbers100 = list(range(100))
    numbers500 = list(range(500))
    shuffled_numbers100 = partial_shuffle(numbers100, shuffle_fraction=1)
    shuffled_numbers500 = partial_shuffle(numbers500, shuffle_fraction=1)
    total_operations100 += execute_push_swap(shuffled_numbers100)
    total_operations500 += execute_push_swap(shuffled_numbers500)

average_operations100 = total_operations100 / iterations
average_operations500 = total_operations500 / iterations
print(f'Average number of operations for 100 numbers: {average_operations100}')
print(f'Average number of operations for 500 numbers: {average_operations500}')

