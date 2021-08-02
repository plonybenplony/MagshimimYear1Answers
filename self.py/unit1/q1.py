import random
import termcolor

print("""
  _    _                                         
 | |  | |                                        
 | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
 |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
 | |  | | (_| | | | | (_| | | | | | | (_| | | | |
 |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
					  __/ |                      
					 |___/
	""")

print(random.randint(5, 10))

termcolor.cprint("""
picture 1:
	x-------x

picture 2:
	x-------x
	|
	|
	|
	|
	|

picture 3:
	x-------x
	|       |
	|       0
	|
	|
	|

picture 4:
	x-------x
	|       |
	|       0
	|       |
	|
	|

picture 5:
	x-------x
	|       |
	|       0
	|      /|\\
	|
	|

picture 6:
	x-------x
	|       |
	|       0
	|      /|\\
	|      /
	|

picture 7:
	x-------x
	|       |
	|       0
	|      /|\\
	|      / \\
	|
""", 'green')