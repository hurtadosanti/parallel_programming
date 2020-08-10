import concurrent.futures
# %%
"""Function to calculate primes using a value

"""


def is_prime(value: int) -> bool:
    if value < 2:
        return False
    elif value == 2:
        return True
    elif value % 2 == 0:
        return False
    else:
        for i in range(3, value):
            if i % value == 0:
                return False
    return True

#%%




values = [1, 2, 3, 4, 5]


def concurrent_prime(workers: int):
    with concurrent.futures.ProcessPoolExecutor(max_workers=workers) as executor:
        futures = [executor.submit(is_prime, i) for i in values]
        complete_futures = concurrent.futures.as_completed(futures)
        for i, future in enumerate(complete_futures):
            print(future.result())
    pass


concurrent_prime(2)

#%%


# %%
print(is_prime(3))
'''Documentation '''
