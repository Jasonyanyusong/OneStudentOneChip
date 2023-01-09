import random
print("Verilog HDL & Verilator Simulation Generate Tool")

class TestVariable:
    def __init__(self, name, min, max):
        self.variable_name = name
        self.minimum_possible_value = min
        self.maximum_possible_value = max
    def print_info(self):
        return "Variable Name: " + self.variable_name + " Minimum Possible Value: " + str(self.minimum_possible_value) + " Maximum Possible Value: " + str(self.maximum_possible_value)

class TestBench:
    def __init__(self, varname, varvalue):
        self.variable_name_list = varname
        self.variable_value_list = varvalue

functionselect = int(input("Function Select:\n0: Exit\n1: Generate C++ sim file (single clock per bench)\n2: Generate C++ sim file (multi clock per bench)\n3: Display Help Manual\n"))
if functionselect == 0:
    print("Exiting ......")
    exit()
if functionselect == 1:
    print("Please enter informations below")
    module_name = str(input("Please enter the module name (make sure be same with what it is in the Verilog HDL (.v) file: "))
    module_directory = str(input("Please enter the directory of the module (use command \"pwd\" in the working directory if you don't know): "))
    include_Vhead_file_directory = module_directory + "/obj_dir/V" + module_name + ".h" 
    print("Please check the information below:", "\n1: Module Name : ", module_name, "\n2: Module Directory: ", module_directory, "\n3: Include Vhead File Directory: ", include_Vhead_file_directory)
    input_count = int(input("Please enter the number of input signals: "))
    input_array = []
    for i in range (1, input_count + 1, 1):
        print("Signal No.", i, ". ", end="")
        input_array.append(str(input("Please enter the name of this signal: ")))
    print("Inputs are: ", input_array)
    test_variable_list = []
    for i in range (1, input_count + 1, 1):
        print("Signal No.", i, ". Please Enter the minimum possible value in simulation: ", end="")
        this_min = bin(int(input()))
        print("Signal No.", i, ". Please Enter the maximum possible value in simulation: ", end="")
        this_max = bin(int(input()))
        test_variable_list.append(TestVariable(input_array[i - 1], this_min, this_max))
        print(test_variable_list[i - 1].print_info())
if functionselect == 2:
    print("Please enter informations below")
if functionselect == 3:
    print("Manual of Verilog HDL & Verilator Simulation Generate Tool")
    exit()