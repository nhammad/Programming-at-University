
start = int(input("Enter Starting Length = "))
end = int(input("Enter Ending Length = "))
step = int(input("Enter Step Size = "))

print("{0:>7}  {1:>7}".format("inch", "cm"))

for inch in range (start, end + step, step):
    cm = inch * 2.54
    print("{0:>7.1f}  {1:>7.1f}".format(inch, cm))

# 0:>6.1f = 1 means 1 decimal place
# 0 is for the position in respect w the bracket
# after format
# val will cover total of 6 spaces
# 1 inch = 2.54 cm
