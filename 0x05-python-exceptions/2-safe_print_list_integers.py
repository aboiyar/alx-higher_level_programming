#!/usr/bin/python3
def safe_print_list_integers(my_list=[], x=0):
    count = 0
    for i in range(x):
        try:
            print("{:d}".format(my_list[i]), end="")
            count += 1
        except (ValueError, TypeError):
            continue  # Skip non-integer values silently
        except IndexError:
            break  # Stop if index goes out of range
    print()  # Move to a new line after printing
    return count
