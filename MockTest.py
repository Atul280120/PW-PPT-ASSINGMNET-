# Q17- Answer

def get_even_numbers(input_list):
    return [num for num in input_list if num % 2 == 0]

# Q18- Answer-
import time

def timer(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        execution_time = end_time - start_time
        print(f"Execution time: {execution_time:.5f} seconds")
        return result
    return wrapper
# to use it 
@timer
def my_function():
    # Function code goes here
    time.sleep(2)

# Q19- Answer

def calculate_mean(numbers):
    total = sum(numbers)
    count = len(numbers)
    mean = total / count
    return mean


# Q20-Answer
from scipy import stats

def perform_hypothesis_test(sample1, sample2):
    t_statistic, p_value = stats.ttest_ind(sample1, sample2)
    return p_value
