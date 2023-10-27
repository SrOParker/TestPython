###########################
###       HP TEST       ###
### INCREASING FUNCTION ###
###   LAUREANO CANTO    ###
###########################


""" 
f
    description
        function to change the type of val (int) to a floating point value
    param 
        val -> number
"""
def f(val):
    return val * 1.0

""" 
find
    description
        function to find a number in a range of values. Giving a function
    param
        f -> function
        y -> element to find in range [a,b]
        a -> minimum element in range
        b -> maximum element in range
"""
def find(f, y:float, a:int, b:int):
    for element in range(a,b):
        if f(element) == y:
            return element
    return -1

""" 
check
    description
        function to check the result of function find
    param
        result -> return value from function find()
"""
def check(result):
    if result != -1:
        print("In range")
    else:
        print("Not in range")

## Example of use
# finding element 10 
print("Checking example 1:")
test = find(f, 10.0, 0, 100)
check(test)

# not finding element 10.0
print("Checking example 2:")
test = find(f, 10.0, 30, 100)
check(test)

# finding element 100000000.0
print("Checking example 3:")
test = find(f, 100000000.0, 0, 10000000000)
check(test)




## Testing with unittest
import unittest
class TestForFind(unittest.TestCase):

    def test_correct(self):
        a = 1
        b = 11
        y = 2.0
        result = find(f, y, a, b)
        self.assertNotEqual(result, 10)  

    def test_invalid(self):
        a = 1
        b = 8
        y = 7.0  
        result = find(f, y, a, b)
        self.assertNotEqual(result, -1)

    def test_all_0_values(self):
        a = 0
        b = 0
        y = 0.0
        result = find(f, y, a, b)
        self.assertNotEqual(result, 0)

if __name__ == '__main__':
    unittest.main()