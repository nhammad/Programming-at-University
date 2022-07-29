

# importing the functions from mod_convo file

import mod_conversion

start = int(input("Enter Starting Length = "))
end = int(input("Enter Ending Length = "))
step = int(input("Enter Step Size = "))
place = input("Screen or File? " )

# printing on standard output
if place == 's':
        mod_conversion.in2cm_table(start, end, step)
        
# printing in HTML file
# file is opened and closed in the
# conversion func
else:
    mod_conversion.in2cm_table2(start, end, step)






