import ctypes
from dataclasses import dataclass
from tkinter import*


@dataclass
class Graphic:
    """
        Constants for the graphics module.
    """

    font = "Garamond 12 bold"
    color = "LightBlue1"
    size = "1000x900"

    min_size = 1


def create_set():
    """
        Create set from array.
    """

    str_array = entry_input_array.get()
    str_array = str_array.split()
    arr = [int(num) for num in str_array]

    lib = ctypes.CDLL("./libarray.so")

    func = lib.create_set
    func.argtypes = [ctypes.POINTER(ctypes.c_int),
                     ctypes.POINTER(ctypes.c_int),
                     ctypes.c_int,
                     ctypes.c_int]
    func.restype = ctypes.c_int

    array_size = len(arr)

    if array_size < Graphic.min_size:
        print("Invalid array size")
        return

    array = (ctypes.c_int * array_size)(*arr)

    set_size = 0
    array_set = (ctypes.c_int * set_size)()
    set_size = func(array, array_set, array_size, set_size)
    array_set = (ctypes.c_int * set_size)(*array_set)
    func(array, array_set, array_size, set_size)

    str_array = ""
    for num in array_set:
        str_array += str(num)
        str_array += ' '

    set_result.delete(0, END)
    set_result.insert(END, str_array)


def fill_fibonacci_arr(array_size):
    """
        Fill fibonacci array.
    """
    lib = ctypes.CDLL("./libarray.so")

    func = lib.fill_fibonacci_array
    func.argtypes = [ctypes.POINTER(ctypes.c_int),
                     ctypes.c_int]
    func.restype = None

    result = (ctypes.c_int * array_size)()
    func(result, array_size)

    return list(result)


def create_fibonacci_arr():
    """
        Create fibonacci array.
    """

    str_array_size = entry_input_size.get()

    array_size = int(str_array_size)

    if array_size < Graphic.min_size:
        print("Invalid array size")
        return
    
    array = fill_fibonacci_arr(array_size)
    str_array = ""
    for num in array:
        str_array += str(num)
        str_array += ' '
    
    fib_result.delete(0, END)
    fib_result.insert(END, str_array)


window  = Tk()
window.title("Arrays")
window.config(bg = Graphic.color)
window.geometry(Graphic.size)

label_fibonacci = Label(window,
                        text = "Числа Фибоначчи",
                        font = Graphic.font, bg = Graphic.color)
label_fibonacci.place(x = 300, y = 10)
label_input_size = Label(window,
                         text = "Введите размер массива:",
                         font = Graphic.font, bg = Graphic.color)
label_input_size.place(x = 60, y = 60)

entry_input_size = Entry(window,
                         width = 40,
                         font = Graphic.font)
entry_input_size.place(x = 60, y = 120)

button_fib_solve = Button(window, 
                          text = "Решение",
                          command = lambda: create_fibonacci_arr())
button_fib_solve.place(x = 60, y = 180)

label_fib_array = Label(window,
                        text = "Массив из чисел Фибоначчи:",
                        font = Graphic.font,
                        bg = Graphic.color)
label_fib_array.place(x = 60, y = 240)

fib_result = Entry(window, 
                   font = Graphic.font, 
                   width = 40)
fib_result.place(x = 60, y = 300)



label_set = Label(window, 
                  text = "Множество", 
                  font = Graphic.font,
                  bg = Graphic.color)
label_set.place(x = 300, y = 400)
label_input_array = Label(window, 
                          text = "Введите исходный массив:",
                          font = Graphic.font,
                          bg = Graphic.color)
label_input_array.place(x = 60, y = 460)

entry_input_array = Entry(window, 
                          width = 40, 
                          font = Graphic.font)
entry_input_array.place(x = 60, y = 520)

button_set_solve = Button(window, 
                          text = "Решение",
                          command = lambda: create_set())
button_set_solve.place(x = 60, y = 580)

label_set_array = Label(window, 
                        text = "Полученное множество:",
                        font = Graphic.font, 
                        bg = Graphic.color)
label_set_array.place(x = 60, y = 660)

set_result = Entry(window, 
                   font = Graphic.font, 
                   width = 40)
set_result.place(x = 60, y = 720)

window.mainloop()
