import re

temp_cata_file = "/sys/bus/w1/devices/28-0120597725ab/w1_slave"

with open(temp_cata_file, 'r') as f:
    contents = f.read()

temp_datum = contents.split()[-1]
celcius = float(temp_datum.replace("t=", ""))

print(celcius/1000)
