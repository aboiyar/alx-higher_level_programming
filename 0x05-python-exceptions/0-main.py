#!/usr/bin/python3
my_list = [1, 2, 3, 4, 5]

nb_print = safe_print_list(my_list, 2)
print("nb_print: {:d}".format(nb_print))

nb_print = safe_print_list(my_list, 5)
print("nb_print: {:d}".format(nb_print))

nb_print = safe_print_list(my_list, 7)
print("nb_print: {:d}".format(nb_print))
