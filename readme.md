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
to simplify the compile process

```bash
function sfml++()
{
	if [ -n "$1" ]
	then
		g++ "$1" -lsfml-graphics -lsfml-window -lsfml-system
	fi
}
```

Now you can use the following command 

`$ sfml++ main.o`

instead the large

```$ g++ main.o -o Demo -lsfml-graphics -lsfml-window -lsfml-system```

To get a cleaner compiling and execution process:

```
$ g++ -c main.cpp
$ sfml++ main.o
$ ./a.out
```
