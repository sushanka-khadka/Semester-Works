# Write a program to create a symbol table for the variables (for data types only)
# Example: - Input (int a = 2, float b = 3.5), output will be as
# Variable Name Type Value Address
# a integer 2 100
# b real number 3.5 200


# print("Enter variable declarations (e.g. int a = 2, float b = 3.5): ")
# declarations = input().strip()

declarations = 'int a = 2, float b = 3.5, char c = \'x\', double d = 4.56, long e = 1234567890, short f = 12, byte g = 255, bool h = true, string i = "hello"'
# declarations = 'int a = 2, float b = 3.5, char c = \'x\''
declarations_list = [decl.strip() for decl in declarations.split(',')]
print("\nVariable Declarations:")
for decl in declarations_list:
    print(decl)

symbol_table = []
address_counter = 100
for decl in declarations_list:
    parts = decl.split()
    var_type = parts[0]
    var_name = parts[1]
    var_value = parts[3]
    symbol_table.append((var_name, var_type, var_value, address_counter))
    address_counter += 100


print("\nSymbol Table:")
print(f"{'Variable Name':<15} {'Type':<15} {'Value':<10} {'Address':<10}")
for entry in symbol_table:
    print(f"{entry[0]:<15} {entry[1]:<15} {entry[2]:<10} {entry[3]:<10}")