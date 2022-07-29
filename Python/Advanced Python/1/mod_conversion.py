
# for writing on standard output

def in2cm_table(start, end, step):
    print("{0:>7}  {1:>7}".format("inch", "cm"))
    for inch in range (start, end + step, step):
        cm = inch * 2.54
        print("{0:>7.1f}  {1:>7.1f}".format(inch, cm))


# for writing in file
def in2cm_table2(start, end, step):
    f = open("in2cm.html", "w")
    f.write("{0:>7}  {1:>7}".format("inch", "cm"))
    f.write("\n")
    while start <= end:
        cm = start * 2.54
        f.write("{0:>7.1f}  {1:>7.1f}".format(start, cm))
        f.write("\n")
        start += step
    f.close()

