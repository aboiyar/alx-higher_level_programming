#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints basic information about a Python list object
 * @p: A PyObject pointer to the list to be printed
 *
 * Description: This function checks if the input PyObject is a valid
 * Python list. If valid, it prints the size and allocated size of the
 * list, and details of each element, calling appropriate functions 
 * for bytes and float elements.
 */
void print_python_list(PyObject *p)
{
    if (!PyList_Check(p))  // Check if p is a valid PyListObject
    {
        printf("[ERROR] Invalid List Object\n");
        return;  // Exit if not a valid list
    }

    Py_ssize_t size = PyList_Size(p);  // Get the size of the list
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;  // Get allocated size

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++)  // Iterate through each element
    {
        PyObject *item = PyList_GetItem(p, i);  // Get the item at index i
        const char *type_name = Py_TYPE(item)->tp_name;  // Get the type name
        printf("Element %zd: %s\n", i, type_name);  // Print element index and type

        // Print additional info for bytes
        if (PyBytes_Check(item))
        {
            print_python_bytes(item);  // Call function for bytes
        }
        // Print additional info for floats
        else if (PyFloat_Check(item))
        {
            print_python_float(item);  // Call function for floats
        }
    }
}

/**
 * print_python_bytes - Prints basic information about a Python bytes object
 * @p: A PyObject pointer to the bytes to be printed
 *
 * Description: This function checks if the input PyObject is a valid
 * Python bytes object. If valid, it prints the size, string representation,
 * and the first 10 bytes in hexadecimal format.
 */
void print_python_bytes(PyObject *p)
{
    if (!PyBytes_Check(p))  // Check if p is a valid PyBytesObject
    {
        printf("[ERROR] Invalid Bytes Object\n");
        return;  // Exit if not a valid bytes object
    }

    Py_ssize_t size = PyBytes_Size(p);  // Get the size of the bytes
    const char *bytes_str = PyBytes_AsString(p);  // Get string representation of bytes

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", bytes_str);

    printf("  first %zd bytes: ", (size < 10 ? size : 10));  // Print first bytes
    for (Py_ssize_t i = 0; i < (size < 10 ? size : 10); i++)
    {
        printf("%02x ", (unsigned char)bytes_str[i]);  // Print bytes in hex
    }
    printf("\n");
}

/**
 * print_python_float - Prints basic information about a Python float object
 * @p: A PyObject pointer to the float to be printed
 *
 * Description: This function checks if the input PyObject is a valid
 * Python float object. If valid, it retrieves and prints the float value.
 */
void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p))  // Check if p is a valid PyFloatObject
    {
        printf("[ERROR] Invalid Float Object\n");
        return;  // Exit if not a valid float object
    }

    double value = PyFloat_AsDouble(p);  // Get the double value from the float
    printf("[.] float object info\n");
    printf("  value: %f\n", value);  // Print the float value
}
