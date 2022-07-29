

id = (47, 3, 2, 51, 5)
name = ("apple", "banana", "peach", "orange", "kiwi")
quantity = (1, 31, 5, 12, 5)
price = (400.35, 1100.25, 21145.05, 141.01, 1478.2)
location = ("Bremen", "Karachi", "Berlin", "Lahore", "Munich")

# zipping tupules
articles = zip(id, name, quantity, price, location)  

# < for left aligned and > for right aligned
heading = "{0:<4}   {1:<6} {2:>4} {3:>12}         {4:>9}"
print(heading.format("ID", "Name", "#", "Price", "Location"))

# printing empty line for ease while reading
print()

# for values under the heading
fm_pattern = "{0:04d}   {1:<6} {2:>4d} {3:>12,.2f} Euros   {4:>9}"  
for i in articles:  
    print(fm_pattern.format(i[0], i[1], i[2], i[3], i[4]))
