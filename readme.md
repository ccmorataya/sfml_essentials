# Example code about the book SFML Essentials

Develop the diferent examples trought the book using
`c++` and `Vim` of course the SFML library

Everything is tested in **GNU/Linux** Using the **g++** compiler

## Compile and execute
```
$ g++ -c main.cpp
$ g++ main.o -o Demo -lsfml-graphics -lsfml-window -lsfml-system
$ ./Demo
```

### Simplify the compiling

Add to the `.bashrc` or `.zshrc` or whatever shell RC file
to simplify the line of 
`$ g++ main.o -o Demo -lsfml-graphics -lsfml-window -lsfml-system`

**
function sfml++()
{
	if [ -n "$1" ]
	then
		g++ "$1" -lsfml-graphics -lsfml-window -lsfml-system
	fi
}
**
