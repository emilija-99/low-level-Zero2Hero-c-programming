# LowLevel---Zero2Hero-C-Programming
### Tools 
installation of build-essential for debian using fedora install tools for gcc
```
sudo dnf group install c-development development-tools
```

Running dnf5 you will run new dnf5 that is default in fedora +41 versions.
DNF is written (dnf4) in python and dnf5 is written in C++ - is rewrite of old pkg manager dnf4.

### What is C programming language?
General Purpose Language 
1972. C programming base C
C89 and C90 - standards
C89 - standard that is globally use and it means it is a base
Writing in C you can menage memory space, how to program behaves and memory usage while running C program
C language do not have garbage collector and if you need to clean heap manually.

### C vs Other Languages
Human Readable Language that is translate into machine readable code - assembly.
There is not middleware when C code is compiled.
C compile language, it gets compiled down to the machine code of the architecture that you're on.
Writing C code and you use the GCC compiler you are turning readable source does in intel op codes that tell your processor what to do. 
Types are strong and compile in runtime, you can change how the compiler or how the program looks at those types. 

C do not have garbage collector and pros for this is that it does not suffer from overhead of running garbage collector.

C is not memory safe. Memory safe language is a language that gives the programmer the ability  to write code freely and not violate the bounds of the memory that they're given. If you have a buffer of memory in rust, a memory safe language, if I try to index outside of that array, if i try to access memory that was not allocated to me, the rust runtime will yell at me. C will let you do anything you want and try to access that memory.

Garbage collector overhead refers to the proportion of CPU time a program spends on garbage collection activities rather then executing application logic. In GO, the garbage collector can consume 20% or more of CPU time in some programs.
In Java applications, GC overhead is measure as the percentage of time spent on garbage collection. A threshold of 5% is considered optimal, while values above 10% indicate potential performance issues.
For .Net application, GC overhead is generally considered negligible in typical scenarios, especially with modern GC implementations that run on separate threads to minimize application interruption.

### Variables
Variable in C is just a location where you put some kind of memory. You have some information that you what to use in your program. This information is putting into variable. 
**Variable declaration:** `type name = initial value;`

```
#include <stdio.h>
int main(){
// type name = initial value;
    int personID = 0; // init value
    int person2ID = personID + 1; // expression

    
}
```

#### Variable Scope
Variable scope is basically a definition of who is able to access variables you've defined or where in your code you're able to access. Variable can have the same name if they're within different scopes. Main function can exists in main function. Updating the main function variable will update local scope variable.

```
#include <stdio.h>
// global scope
int g_NumPersons = 0;

void some_other_function(){
    int personID = 1;
}

int main(){
    // in scope - local scope
    int personID = 0;
    personID += 1;

    {
        int personID = 0;
        personID += 1;
    }
}

```

### Processor
The pre-processor is all of these things here that start with the pound sign `#define, #include` 
What happens when compiler actually converts human readable code in code that can be run on computer.
1. Preprocessor
   It takes directives and copy and paste whatever is meant to happens in this directive into your code. `#include` directive literally reaches out to the global standard IO header file and copy and paste that into your code. Allowing us to do function that we didn't write like printf, scanf or put other functions in the standard glib C runtime that we didn't create.
   The `#define` is tool pre-processor directive that allows us to create variables that act as constants where we can control how our function behaves through these variables at compile time.
```
   #define DEBUG
   #ifdef DEBUG
   printf("in debug mode: %s:%d", __FILE__, __LINE__);
   #endif
   
   return 0;
   
```
2.  Compilation - translates the code int assembly
3. Assembly - converts assembly to machine code
4. Linking - connects all obejct files and libraries into a final executable.

#####  Common Preprocessor Directives
1. `#define` > defines a macro
   `#define PI ` This is useful for constants that you want to control at compile time. This also can be used to enable or disable certain features
2. `#include ` > contents of a file
3. `#if, #elif, #else, #endif` >controls compilation
4. `#ifdef #ifndef` - check if a macro is defined or not
5. `#error` produces a compile-time error
6. `#pragma` > provides compiler-specific instructions
7. `#line` – Changes the compiler’s idea of the line number and filename.
8. `#warning` – Produces a compiler warning (GCC specific).

https://cplusplus.com/doc/tutorial/preprocessor/
https://gcc.gnu.org/onlinedocs/cpp/

##### Arrays
Technical debt - which is this idea that updating your code and maintain your code and kind of making it do what you wanna do.
Array is a block of memory that contains same type. [] - hard bracket
```
#define MAX_IDS 32
int ids[MAX_IDS]; // array of 32 elements, int elements
// or
int ids[] = {1,2,3}; // compailer will make room for 3 elements

// best approach
int ids[MAX_IDS] = {0,1,2};

// first element 
printf("%d \n",ids[0]); - print decimal that is integer
ids[3] = 0x41; // 65 decimal value of 0x41 hex
 

```

##### Strings
A string is a just a array of characters. How computer know how to print string and now where is the end of string? Actually in this array above there is a small vulnerability where you have to have a zero at the end of array - null terminated, it will stop when there is a zero.
```
char mystr[] = {'h','e','l','l','o'};
printf("%s\n",mystr);

// correct - null terminated
char mystr[] = {'h','e','l','l','o',0};
printf("%s\n",mystr);
```

By default string in double quotes `char *myotherstr = "hello";` as opposed to single quotes and making your own array, the compiler knows by default to null terminate this. 

##### Conditional Statements
```
int main(){
	int temp;
	scanf("%d\n", &temp);
	if(temp >= 70)
		printf("dang bruther, it's hot\n");
	else if(temp >= 30 && temp < 70){
		printf("dang bruter, its mild\n");
	}else{
		printf("dang bruther, it's cold\n");
	}
	
	return 0;
}
```

An if statement says, "only do this thing if the following condition is true"

`if(x == 42) printf("You said 42\n!");` 

In the above code, we created a conditional statement that will only run if the value from the user is 42. Computers run on binary, which is a 1 or 0, effectively it can only take action if things are true or not true. And if statement does just that: it runs some statement and if the result is true it takes action.

Two standalone `if` blocks execute independently. Both conditions are evaluated, and both bodies can run. If the logic requires mutual exclusivity—only one branch should fire—use `if … else if … else`.

`scanf("%d\n",&temp);` > scanf treats white-space as "skip util non-white-space" by default for %d. 
1. `\n` tells scanf to keep waiting until it sees a non-white-space character is typed. This creates input-hang issue.
2. Expect the function to return after the user hits Enter, but `\n` fores scanf to wait for more input.

#### Loops
Loop means do the same thing, over and over util some condition is met. 
- for loops > iterator `int i = 0;` first parameter is iterator, then we have what is called truth clause > thing that is going to be evaluated to see if we have to run again. Last part is take action clause that means action we do in every iteration.
```
int i = 0; 
for(i = 0; i < MAX_IDS; i++){
	ids[i] = i;
	printf("%d: %d\n", i, ids[i]);
};
```
- while loops > it just runs the program inside the loop while the condition is true.
- do while loops > is the same as while loop, but the code inside the loop will ALWAYS execute once regardless of the condition (first run, then check)

#### Functions
Main function is block of code that will run every time your program starts. The compiler expects main to exists. Function parameters are arguments that are given to function. `int main(int argc, char *args[])`.
Syntax of the function,  `return_type, name_of_function(list_of_arguments)`. In main function return type is integer that tells if our program failed or not, and we give the argument parameter list, the list of things that the function needs to behave - our input from the user. Return is result of the function.
```
int add(int x, int y){
	int z = x+y;
	return z;
}
int main(int argc, char *argv[]){
	int other_int = add(1,2);
	printf("%d\n", other_int); 
	
	return 0;
}
```


#### Structures
Organize data that was same type together into a continuous block of memory - **array** and gave us the **power to store and modify a lot of data at the same time pragmatically**. In array we can combine only the same data types, but I want to join multiple data types together > this is where a **structure** comes in.
A **structure** is a **block of memory that contains variables of different or same types that represents a logical representation of memory.** 

note: `#include <stdbool.h> > library for bool usage`
```
#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEE 10
struct employee_t{
	int id;
	char first_name[64];
	char last_name[64];
	float income;
	bool is_manager;
};

int main(int argc, char* argv[]){

	// struct employee_t Fred;
	// Fred.income = 10000;
	// Fred.is_manager = true;

	// Array of employees
	struct employee_t employees[MAX_EMPLOYEE];

	int i = 0;
	for(i = 0; i < MAX_EMPLOYEE; i++){
	    employees[i].income = 0;
		employees[i].is_manager = false;
	}

	for(i = 0; i < MAX_EMPLOYEE; i++){
	    printf("%f\n",employees[i].income);
	}
}

```
Structures allows you to organize your data in a way that you would logically excepted and use the control state to edit it.

##### Initializing a Structure
When creating a structure, you need to give it life in the form of values. You have a few options.
- **Not Initializing it** > the problem with this is the `mystruct` values will be determined by whatever values used to be in the slots of memory prior to it existence.  Basically, you can't determine what will be there and it's therefore bad practice.
```
struct mystruct{
	int i;
	char c;
};
int main(){
	struct mystruct;
}
```
- **Initialize to Zero** > this will set all field to zero;
```
struct mystruct{
	int i;
	char c;
};
int main(){
	struct mystruct = {0};
}
```
- **Initialize the structure** > this will set all the fields in the struct. This is best if you know the values beforehand.
```
struct mystruct{
	int i;
	char c;
};
int main(){
	struct mystruct = {
		.i = 1;
		.c = 'A';
	};
}
```

#### Unions
in struct, a struct will allocate enough memory to contain all these elements. I want to have enough room for an ID and then 64 bytes for a first name buffer and 64 bytes for character buffer... so it's gonna allocate all the memory for all of these types. Union type is different. It will create a enough room for the biggest element!
```
union myunion u {
	int x;
	char c;
};
```
The union will be only x which is 4 bytes on the system. The reason for the union type and why it kind of exists is if, for example you were doing embedded stuff and you wanted to have access to all four bytes within the four byte in type and didn't want to have to do the manual math every time - looking to a value c you would get access to the first byte of the four byte character x. Union creates enough memory for the biggest element and you're allowed to access all the sub elements.
```
union my_union{
	int x;
	char c;
	short s;
};

int main(){
	union my_union u;
	u.x = 0x31324344;
	printf("%hx %hhx\n", u.s, u.c);
}
```
By setting the large value and by using `s` and `c` i'm accessing internally the smaller parts of the bigger x.

Unions are a field that assign multiple labels of multiple types to the same memory location.
#### Special Struct Modifiers
```
#define MAX_EMPOYEE 1000
__attribute__((__packed__)) struct employee{
	int id;
	char first_name[64];
	char last_name[64];
	float income;
	bool is_manager;
};

int main(){
	struct empoyee empoyees[MAX_EMPOYEE];
	printf("Size of empoyee: %ld\n:", sizeof(struct empoyee));
}
```
Creating the structure  we're creating enough memory for all of these types. The size of struct is equal to the sum of all of the sizes of the parts. Well, not actually true. Depending on the system that your code gets compiled and run on it may add additional optimizations under the hood that add padding characters in between these field that you're not aware of that are there. The problem with this is that if you have two different copies of this code that gets compiled on two different systems, but you expect them to talk to each other externally the issue is that of they're optimized for different reasons, the structure begins to look a little different and you can't actually expect the offset of ID on one system to be the offset to ID on another system. To prevent this issue we can use special struct modifies. 

`__attribute__((__packed__))` > is GCC compiler-specific attribute used to instruct the compiler to pack a structure of union without inserting padding bytes between its members. This ensure that the members are places consecutively in memory, minimizing the total memory footprint. 

#### Memory 
Memory management is a critical aspect of C programming, giving developers direct control over how and where data is stored and accessed. We have **hard drives** that are **physical**, **permanent** memory. You also have your **random access memory which is middle layer between CPU and processor and the inside the processor we have cache memory that is small but extremely fast memory that is used to kind the buffer the access to the ram because ram is slower then the CPU**

When you write code, `int x = 4` you have to **create space for that number four to go into and that all happens in RAM** - **random access memory.**  
**Random access memory is temporary place that is used to store information for running process.** It's temporary and what this means is  when the *process exists there will ultimately be no record of that memory begin there.* The reason being, the memory that is used  by a process is being shared with other processes once the process ends. If you have a page of memory, which is a block of memory that is used by kernel once you put your program i there, **you run some code and your program leaves, that page of memory will go be used by somebody else and it'll not have the memory values** 
**that were there during you program execution.** 

Getting direct access to the memory and gives us the ability to write not only fast code  but also unsafe code. **Direct access memory is not directly direct access.** In terms of **random access memory** there are actually two terms we used to refer to it.
**There is virtual memory and physical memory.** 
When we say **virtual memory,** we have **virtual addresses,** which are a **logical addresses that is used by the kernel to refer to a location and physical memory that has to be translated to a physical address at runtime**. So we have these virtual addresses that are how your process views that access that it has to ram, **but you do not have access to that specific location that location that virtual address or that logical address gets translated to a physical address that is actually addressable in the stick of ram that you have > physical address.**

![[virual-vs-physical-addr.excalidraw]]
The virtual memory model is important to the current architecture of process and kernel based computing in the process.
Basically there are multiple processes, process A and process B that have this illusion that they own the entirety of memory space on the computer they own from zero all the way up to the kernel border, which is 7FFF.. in 64 bit land. But in reality, they map to different physical addresses. By doing this we give the process illusion that it has  the entire memory map, but also give it different locations so that they're not colliding with each other they're not writing to the same physical location.

![[memory.excalidraw]]This is the memory map from zero all the way up to max int on a 64bit computer from zero up to roughly 400.000 in hex there's noting that none of that is paged by the kernel, like no access is given to you but without a SLR which is a memory protection concept by default your program, the physical program that you compile will live at this address 0x400000 and the inside of that binary of that program that you run, there is different segments, pieces of the memory that have  to get put into the process image when we running the program. There is `.text` section  that is code you write, `dart.ro`section there is read only string, read-write segment there is data which are when you have global variables that are initialized they will got into the data segment, there is also DO BSS section, which are global variables that are initializes to zero and after that we have run time heaps > when you make a piece of dynamic memory that is created in this function called `malloc` and the `malloc` run time is gonna allocate the heap and it's gonna grow up towards this region that will contain the memory for libraries. The stack is a piece of memory that is used to contain all of the memory that your program is using at any given time. When program calls function, as your call stack gets bigger this user region of ram will grow throws down to shared-libraries.

**A simplified map looks like:**

```
|-----------------------------|
| Stack (grows downward)      |
|-----------------------------|
| Memory-mapped segments      |
|-----------------------------|
| Heap (grows upward)         |
|-----------------------------|
| Uninitialized Data (BSS)    |
|-----------------------------|
| Initialized Data            |
|-----------------------------|
| Text Segment (code)         |
|-----------------------------|
```
##### View memory process
`car /proc/self/maps` > in shell, cat creates new process and kernel create new process. 
```
emilija@fedora:~/Documents/zero2_hero_c$ cat /proc/self/maps
562beebf6000-562beebfb000 r-xp 00000000 00:22 745077                     /usr/bin/cat
562beebfb000-562beebfe000 r--p 00005000 00:22 745077                     /usr/bin/cat
562beebfe000-562beebff000 r--p 00007000 00:22 745077                     /usr/bin/cat
562beebff000-562beec00000 rw-p 00008000 00:22 745077                     /usr/bin/cat
562bfde01000-562bfde22000 rw-p 00000000 00:00 0                          [heap]
7f1d897be000-7f1d89800000 rw-p 00000000 00:00 0
7f1d89800000-7f1d97670000 r--p 00000000 00:22 700358                     /usr/lib/locale/locale-archive
7f1d9768a000-7f1d9768d000 rw-p 00000000 00:00 0
7f1d9768d000-7f1d977fd000 r-xp 00000000 00:22 700565                     /usr/lib64/libc.so.6
7f1d977fd000-7f1d97873000 r--p 00170000 00:22 700565                     /usr/lib64/libc.so.6
7f1d97873000-7f1d97877000 r--p 001e5000 00:22 700565                     /usr/lib64/libc.so.6
7f1d97877000-7f1d97879000 rw-p 001e9000 00:22 700565                     /usr/lib64/libc.so.6
7f1d97879000-7f1d97881000 rw-p 00000000 00:00 0
7f1d978a3000-7f1d978a5000 rw-p 00000000 00:00 0
7f1d978a5000-7f1d978a9000 r--p 00000000 00:00 0                          [vvar]
7f1d978a9000-7f1d978ab000 r--p 00000000 00:00 0                          [vvar_vclock]
7f1d978ab000-7f1d978ad000 r-xp 00000000 00:00 0                          [vdso]
7f1d978ad000-7f1d978d7000 r-xp 00000000 00:22 700562                     /usr/lib64/ld-linux-x86-64.so.2
7f1d978d7000-7f1d978e2000 r--p 0002a000 00:22 700562                     /usr/lib64/ld-linux-x86-64.so.2
7f1d978e2000-7f1d978e4000 r--p 00035000 00:22 700562                     /usr/lib64/ld-linux-x86-64.so.2
7f1d978e4000-7f1d978e5000 rw-p 00037000 00:22 700562                     /usr/lib64/ld-linux-x86-64.so.2
7f1d978e5000-7f1d978e6000 rw-p 00000000 00:00 0
7ffc703b5000-7ffc703d7000 rw-p 00000000 00:00 0                          [stack]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]
emilija@fedora:~/Documents/zero2_hero_c$ which cat
/usr/bin/cat
emilija@fedora:~/Documents/zero2_hero_c$
```

#### Pointers
The pointer is literally just a value that happens to be address. Creating value `int x = 3;` what the compiler does is it makes room on what's called the stack. It's basically just a memory location in the program that you put things that you're using at runtime. When i make room for `x` the place the place that i put it is the address of x. It's the place of address that x lives. So, if i were to make a pointer to `x` all the pointer is gonna to be is value that equals the address of `x` 

```
int x = 3;
int *pX = &x; // pointer to address of int x

printf("%d\n", *pX); // derefrent pX -> this literally says get the value pointed to by pX.
printf("%p\n", pX); // print out the pointer value of pX 
```

```
#include <stdio.h>
#include <stdbool.h>

struct employee_t{
	int id;
	float income;
	bool stuff;
};
// address of empoyee
void initialize_employee(struct employee_t *e){
    e->id = 0;
    e->income = 0;
    e->stuff = false;

    return;
};

int main(int argc, char* argv[]){
    struct employee_t Ralph;
    // setting the default value for Ralph
   // Ralph.id = 1;
    //Ralph.income = 0;

// send address of Ralph that will be used to initilize values
    initialize_employee(&Ralph);

    printf("%d %.2f %b\n", Ralph.id, Ralph.income, Ralph.stuff);
}
```

#### Dynamic Memory Allocation
```
#include <stdio.h>
#include <stdbool.h>

struct employee_t{
	int id;
	float income;
	bool stuff;
};
// address of empoyee
void initialize_employee(struct employee_t *e){
    e->id = 0;
    e->income = 0;
    e->stuff = false;

    return;
};

int main(int argc, char* argv[]){
    struct employee_t Ralph;
    // setting the default value for Ralph
   // Ralph.id = 1;
    //Ralph.income = 0;

// send address of Ralph that will be used to initilize values
    initialize_employee(&Ralph);

    printf("%d %.2f %b\n", Ralph.id, Ralph.income, Ralph.stuff);
}

```

There is a issue with this code from a performance and optimization standpoint where every time we run this code despite the amount of employee space that we need, we are always allocating a thousand employee structures on the stack. This limit us to the amount of employees that we can allocate, we can only allocate 100. And we are wasting memory because we allocate for 100, and use one.

```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct employee_t{
	int id;
	float income;
	bool stuff;
};


void initialize_employee(struct employee_t *e){
    e->id = 0;
    e->income = 0;
    e->stuff = false;

    return;
};

int main(int argc, char* argv[]){
    int n = 3;

	struct employee_t *employee = malloc(sizeof(struct employee_t)*n);
	if(!employee){
		printf("allocator failed");
		return -1;
	}

	initialize_employee(&employee[0]);

	printf("id: %d\n", employee[0].id);
	free(employee);
	employee = NULL;

	return 0;
}

```
We can use pointer type, it may point to one element but we actually can use this pointer to point to infinite number of elements further out from the base element. Instead of employee being array, `emplyees` is now pointer. So `malloc` is memory allocator  we're asking lib.c to return to us a pointer to some amount of memory - in this case `(sizeof(struct employee_t)*MAX_EMPLOYEES`.  When code is over we need to free that memory. If we do not free used memory this can lead to memory leak.

##### Heap
The heap is a data region in ELF(Linux) memory that is managed by a memory allocator. Instead of using statically defined arrays or structure, we can ask the memory allocator via a function called malloc to get us a certain amount of memory.

##### Allocating Memory
To use this memory, we need to assign it to variable for use later. Also, it's important that we check the return value from `malloc` to make sure that we got a value from the allocator. Sometime, allocators fails.

##### Freeing Memory
We must give the memory back to the system. If we fail to free memory that we allocate, over time we will leak memory, and could possibly use up all available system memory and eventually have our process be killed by the operating system karnel. To avoid this, free your memory like so:
`free(employee)`
`employee = NULL`

#### Static Memory Allocation
Global variables are kind of a no-no in programming for a few reasons. The main reason being it's hard to track exactly where this piece of data is accessed and control who has control over it at any given time. When we do multi-threaded code it gets really difficult to make sure that this is accessed in a way that's sane, that there's no data races, etc. 
So, instead of using global data we can use static variable > `static keyword`.
What the static keyword will actually do is it initializes the variable in global scope, but we are the only ones that have access to it. Every time the function `initilize_employee` is called this variable doesn't change his value. Static value is initialized in first call.

```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
// global variables
int global_n_employees = 0;

struct employee_t{
	int id;
	float income;
	bool stuff;
};


void initialize_employee(struct employee_t *e){
// static variables
    static int numEmployees = 0;
    numEmployees++;

    e->id = 0;
    e->income = 0;
    e->stuff = false;
    printf("numEmployees: %d\n", numEmployees);
    return;
};

int main(int argc, char* argv[]){
    int n = 3;

	struct employee_t *employee = malloc(sizeof(struct employee_t)*n);
	if(!employee){
		printf("allocator failed");
		return -1;
	}

	initialize_employee(&employee[0]);
	initialize_employee(&employee[1]);
/*
    numEmployees: 1
    numEmployees: 2
    id: 0
 */

	printf("id: %d\n", employee[0].id);
	free(employee);
	employee = NULL;

	return 0;
}
```
`    numEmployees++;` this will increment the number of employees variable to one plus the previous value even though it gets set to zero at begin of function.
What actually is happening is this variable lives in what's called the data section > so it's not being put on the stack, is being put in a location that does not get destroyed when the function returns and then updating that variable to us > data hiding.

##### Static Variables
A static variable is a variable that exists in a static lifetime, but does not have global scope. By creating a static variable, we are able to create variables that out live the lifetime of a function call and track data over multiple calls to the same function.

#### Pointers to Pointers
Pointers to pointers or double pointers. 
A pointer is just a variable that contains an address of another variable.
```
int i;
int *pi = &i; // address of i

int **ppi = &pi; 
```
`int **ppi = &pi;` > create a variable that is a pointer to a pointer whose name is `ppi` and it's value is address of `pi`. 
Double pointers are used to update pointers outside of function scope.
`int *data = malloc(BIG_SIZE);` > Well take for example the case where we are getting pointer back from some kind of dynamic memory. We have `malloc`, this is gonna give us a pointer to data that lives in the heap and we are gonna use that in the employee database to store our employees. 
If this pointer to the data lives in one function but i want to use it in a different function and more important if we change the value of data, how do we update it?
`data = realloc(data, BIG_SIZE);` 
The double pointer will give us a power to put the data pointer somewhere else. We're able to use a pointer to a pointer to update the pointer with a new address. 

```
status_t foo(int **data_out){
	*data_out = malloc(BIG_SIZE);
}
```
In this example we have this function called foo and inside of foo we call `malloc`, `malloc` return a pointer and we want to extract that pointer of the foo function so that we can use it. What we are able to do, instead of calling malloc getting the variable out and then returning it by the return value, which we can't do cause this is a `status_t` here, we're able to overwrite the value at data out by saying `*data_out = malloc(BIG_SIZE);` . We're using this double pointer as a way to extract data from the function and se the value at `data_out` to this new malloc location.  

```
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum{
    STATUS_GOOD,
    STATUS_BAD
} status_t;
/**
 * Funtion taks double pointer arr and a new size as parameter
 *
 */
status_t foo(int **arr, size_t new_size){

    // the realloc function attempts to resize the mermoy block
    // pointed to by *arr to new_size elements
    int *temp = realloc(*arr, new_size*sizeof(int));
    if(temp == NULL){
        printf("Memory allocation failed\n");
        return STATUS_BAD;
    }

    // update the original pointer *arr to point to the
    // new memory block
    *arr = temp;
    return STATUS_GOOD;
}
int main(){
    size_t initial_size = 5;
    size_t new_size = 10;

    int *arr = malloc(initial_size * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for(size_t i = 0; i < initial_size; i++){
        arr[i] = i;
    }

    printf("initial array: \n");
    for(size_t i = 0; i < initial_size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    if(STATUS_BAD == foo(&arr, new_size)){
        printf("oh no.");
        return -1;
    }

    for(size_t i = initial_size; i < new_size; i++){
        arr[i] = i;
    }

    printf("Resized array\n");

    for(size_t i = 0; i < new_size; i++){
        printf("%d  ",arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}

```

#### Testing for Memory Leaks
**Documentation**: https://valgrind.org/docs/manual/manual.html

**Usage:**
`emilija@fedora:~/Documents/zero2_hero_c$ gcc -o double double_pointer.c -g`
`emilija@fedora:~/Documents/zero2_hero_c$ valgrind --leak-check=full ./double`

**Output:**
```
==9949==
==9949== HEAP SUMMARY:
==9949==     in use at exit: 40 bytes in 1 blocks
==9949==   total heap usage: 3 allocs, 2 frees, 1,084 bytes allocated
==9949==
==9949== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9949==    at 0x4847897: realloc (vg_replace_malloc.c:1804)
==9949==    by 0x4004D3: foo (double_pointer.c:17)
==9949==    by 0x4005DA: main (double_pointer.c:49)
==9949==
==9949== LEAK SUMMARY:
==9949==    definitely lost: 40 bytes in 1 blocks
==9949==    indirectly lost: 0 bytes in 0 blocks
==9949==      possibly lost: 0 bytes in 0 blocks
==9949==    still reachable: 0 bytes in 0 blocks
==9949==         suppressed: 0 bytes in 0 blocks
==9949==
==9949== For lists of detected and suppressed errors, rerun with: -s
==9949== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```


#### Introduction to File Descriptors
In Linux everything is file > file descriptor. File descriptor is just an integer or a number that represents a handle in Win terminology to a file. When we open files we will get numbers put in these variables here that will represents out way of describing to the kernel what file we're talking about.
By default when you write code, there are already three file descriptors open for every single program.
- 0 = a file that represents the input to your program from the command line > `stdin`
- 1 = a file that represents the output of your program to the command line > `stdout`
- 2 =  a file that represents the output of your program, but containing only errors > `stderr`

```
int fd = open("./file.txt", O_RDONLY);
if(fd == -1){
	perror("Open");
	return -1; // error executed and delete file!
}
```


#### File output 
When you accessing the files in C you get these file descriptors and the file descriptor is just a number that represents to the kernel a  file that it has opened for you via assist call which is given to you through libs. 
In main function we have parameters `int argc, char *argv[]`, where `argc` represent the number of command line argument and a vector of command line argument that are given to the program on the command line. 
If we type `./myprogram file.db`, this file.db what actually  populate is the `argv[1]` parameter > we want to make sure that our `argc` is actually equals to 2, because the first one is the command line name of the program but the second argument itself is argument (`file.db`).  

```
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    // int open(const char *pathname, int flags);
    // flags -> O_WRONLY, O_RDWR..
    // for opening file need to be specified premmisions
    // of the file 0644 > go to non private files
    // this create and write file > does not work on existng file!!!
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if(fd == -1){
        perror("Open;");
        return -1;
    }

    char *mydata = "hello there!\n";
    write(fd, mydata, strlen(mydata));

    close(fd);

// only function allocated by malloc, calloc and realloc
// need to be free and NULL to memory > dynamic allocation
// using only *pointer is static allocation that doesn't
// implycitly means that is heap allocation
// POINTER !== ALLOCATION
// pointer only > an address holder
// it says noting about: where the memory lives, who owns it, whether it can be freed
// what happends actually
// - pointer to variable, static / read only memory > no heap involved,
// allocation not happend!!!!

// ISSUE WITH UNDERSTANDING:
    // free(mydata);
    // mydata = NULL;
    return 0;
}

```

#### File Input
Creating dump db file using command line:
``echo -ne "\x01\x00\xff\x00\x08\x00\x00\x00" > ./my-db.db``
Hexadecimal dump, oftern called a hex dump is representation of binary data in a human-readable format using hex notatiton. Each byte of binary data is displayed as a pair of hex digits.
```
emilija@fedora:~/Documents/zero2_hero_c$ xxd my-db.db
00000000: 0100 ff00 0800 0000                      ........
emilija@fedora:~/Documents/zero2_hero_c$
```
##### Read
Read > read from a file descriptor
`ssize_t read(int fd, void *buf, size_t count)` > 
- `fd` > we can specified the file descriptor to read from the buffer to read into

#### Reading File Metadata
##### Stat
Stat is a linux system call that asks the karnel to report inomration about a specific file. 
`stat ./my-db.db`

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// in db header we describe 3 things
struct database_header{
    unsigned short version; // of file type we are using
    unsigned short employees; // how much we can interrate
    unsigned int filesize; // maybe our ffile is corrupter, to prevent this we will do checkers
};
//  Create db file
// echo -ne "\x01\x00\xff\x00\x08\x00\x00\x00" > ./my-db.db


int main(int argc, char *argv[]){

    struct database_header head = {0};
    struct stat dbStat = {0}; // information about db file

    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
// opening a file db using command line input
    int fd = open(argv[1],O_RDWR | O_CREAT , 0664);
    if(fd == -1){
        perror("Open a file.");
        return -1;
    }

// read from a file descriptor
    if(read(fd, &head, sizeof(head)) != sizeof(head)){
        perror("Head file.");
        close(fd);
        return -1;
    }

    printf("DB verions: %u",head.version);
    printf("DB Number of Employees: %u\n", head.employees);
    printf("DB File Length: %u\n",head.filesize);

    if(fstat(fd, &dbStat) < 0){
        perror("fStat");
        return -1;
    }

    printf("DB File Length: %lu\n", dbStat.st_size);

    if(dbStat.st_size != head.filesize){
        printf("GET OUT :)");
        close(fd);
        return -2;
    }
    close(fd);
    return 0;


}

```


#### Variable Types
When you give it a certain type and this integer type is a type that can store a number but there are actually a ton of modifiers and other types that allow us to change the purpose and the size of that variable. In C, there is `int, char, short, long, long int` > all of these contains a variables with different lengths. 
```
char y; // 1 byte, 8 bits
short s; 2 bytes, 16 bits
int i; // 4 bytes, 32 bits
long long int l; // 8 byte, 64 bits

unsigned int xx = -4; // for int > any number that includes negative numbers in range of 32bits


```
When  you have a `signed` variable you actually limit the amount of numbers that variable can represent. 
When you write `char s` > `00000000` what the compiler is going to do internally is use this first bit to determine if the variable is negative or positive.  Signed character can represent from -128 to 127, and enabling first bit means that this is -128 in which way compiler knows if this positive or negative variable.
Unsigned values are values that are only positive and putting the negative value will executed will compiler error. That is actually difference between unsigned and signed values.

##### **C Data Type:** 
- `char`
    
    - **Signed/Unsigned:** Signed
    - **Bit Length:** 8 bits
    - **Minimum Value:** -128
    - **Maximum Value:** 127
-  `unsigned char`
    
    - **Signed/Unsigned:** Unsigned
    - **Bit Length:** 8 bits
    - **Minimum Value:** 0
    - **Maximum Value:** 255
-  `short`
    
    - **Signed/Unsigned:** Signed
    - **Bit Length:** 16 bits
    - **Minimum Value:** -32,768
    - **Maximum Value:** 32,767
-  `unsigned short`
    
    - **Signed/Unsigned:** Unsigned
    - **Bit Length:** 16 bits
    - **Minimum Value:** 0
    - **Maximum Value:** 65,535
-  `int`
    
    - **Signed/Unsigned:** Signed
    - **Bit Length:** 16 or 32 bits
    - **Minimum Value:** -2,147,483,648 (32-bit)
    - **Maximum Value:** 2,147,483,647 (32-bit)
-  `unsigned int`
    
    - **Signed/Unsigned:** Unsigned
    - **Bit Length:** 16 or 32 bits
    - **Minimum Value:** 0
    - **Maximum Value:** 4,294,967,295 (32-bit)
-  `long`
    
    - **Signed/Unsigned:** Signed
    - **Bit Length:** 32 bits
    - **Minimum Value:** -2,147,483,648
    - **Maximum Value:** 2,147,483,647
-  `unsigned long`
    
    - **Signed/Unsigned:** Unsigned
    - **Bit Length:** 32 bits
    - **Minimum Value:** 0
    - **Maximum Value:** 4,294,967,295
-  `long long`
    
    - **Signed/Unsigned:** Signed
    - **Bit Length:** 64 bits
    - **Minimum Value:** -9,223,372,036,854,775,808
    - **Maximum Value:** 9,223,372,036,854,775,807
-  `unsigned long long`
    
    - **Signed/Unsigned:** Unsigned
    - **Bit Length:** 64 bits
    - **Minimum Value:** 0
    - **Maximum Value:** 18,446,744,073,709,551,615
-  `float`
    
    - **Bit Length:** 32 bits
    - **Minimum Value:** ~ -3.4 x 10^38
    - **Maximum Value:** ~ 3.4 x 10^38
-  `double`
    
    - **Bit Length:** 64 bits
    - **Minimum Value:** ~ -1.7 x 10^308
    - **Maximum Value:** ~ 1.7 x 10^308
#### Type Casting 

Signedness Casting
```
unsigned int bigX = 0xfffffefe; // 4bytes
short kindabig = (shor)bigX;
```
Casting unsigned int to short > unsigned int is 4 bytes and we want to cast into 2 bytes value. Compiler will probably going ti warn us that we're cutting off the TOP 32 bits of information because we are asking 32 bits to get stuffed into 16 bits. 

```
short short2 = -1; // 0xffff
int wasashort = (int)short2;
```
Short is 16 bits and we want to store into 32 bits. Because these two values is both signed what will actually happen when we create this extra room for this new variable it's going to slide out leading one to make the entire variable negative. This variable will become the `0xffff > 0xffffffff`

```
(char *) > (short *)
short *nydata = (short*)argv[1];
```
What this does, it says take care of pointer `argv[1]` and treat that like a short pointer.

Floats or doubles can be cast to other variable types. It's important to understand that under the hood, assembly instruction are generated in FPU of the processor to execute this conversion. In other casts the data has not been significantly manipulated to enable that cast. In this case, the IEEE704 type must be manipulated to reveal the scalar value.

The CPU has a special helper called the FPU - Float Point Unit it runs special assembly instructions. These instructions decode the float and rebuild the number.

Integers are stored directly, so casting just changes the box. Float are stored as pieces, so casting must rebuild the number first.

#### Multi Module Programming
A module in programming refers to something that is wholly separate, does not depend on coupled dependencies and performs a function. We can think of db as a set of modules that interfaces with the user.

Maybe we have: 
- the main module > interfaces via stdin and stdout
- the file module > interfaces with the main module via an exposed interface and the file system
- the parsing module > reads data from opened files and parses them for the user

**Header Files**
Interfaces between the main module and the other modules are exposed in header files. Header files revels the declarations, but not necessarily the definitions, for function that we use in a module. Inside of a C file for a module, we will define the function, but the main module does not need to know about the internal functionality: just the inputs and outputs.

```
#idnef FILE_H
#define FILE_H

int open_rw_file(char *path);

#endif
```
In this file, file.h, we expose the interface to the file module, without giving the definition of the function. To access these functions we use headers in main.c
`#inlude 'file.h'`


#### Build Systems
- https://makefiletutorial.com/
Make it a tool that, when ran, finds a Makefile and executes the instructions to build a particular target.
What Make actually does is it goes into the make file in the current directory and executes the script against whatever target you specified. If you do not specify the target it'll go forward and it'll run the make file default target. 
```
TARGET = bin/final
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default: $(TARGET)

clean: rm -f obj/*.o
	   rm -f bin/*
$(TARGET): $(OBJ)
	gcc -o $@ $?

obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude
	
```
The default is target, that says to be complete, first the $(TARGET) binary must be complete. Once that is complete, the instructions within default will be ran.

**Symbols:**
- $? represents a list of all input files given as a target
- $< represent a single file given as a target
- $@ represents the target of the rule

```
GNU nano 8.5                                       Makefile                                                    

NAME = EMILIJA  
FILE = demo.txt  
  
.DEFAULT_GOAL := help  
  
help:  
       @echo "Available commands:"  
       @echo " make hello - print greeting"  
       @echo " make create - create a demo.txt"  
       @echo " make clean - deletes demo.txt"  
hello:  
       @echo "Hello $(NAME)"  
  
create:    
       echo "File is created by make!" > $(FILE)  
clean:  
       rm -f $(FILE)
```

#### Creating Libraries
How to write code and see as library how to transport from one program to another and includes into code.
There are two kinds of libraries and see there's one that's called a shared library / object or a static library / object > `/¬.a`also referred to as a dot archive to an archive file.  The primary difference between the two is that when you run your program in the case of shared object what actually happening is your program runs in blob > .elf executable and linkable format and represent code that is written. A shared object gets loaded outside of your elf, they're separated elf's in the same memory space and the loader will build a link between the two at runtime that tells your code how to get to the elf and vice versa. That is a shared object. Glib C runs as shared object.

Difference between shared object and static object is how it is compiled. Shared object actually gets enabled at runtime, your program specifies and it needs it. And that's put in at compile time, but shared object gets loaded at runtime into memory whereas a static object all code run in compile time. Linker for static object will compile all elf files and link into one file. When it gets run at runtime all files exists in one file. The primary difference is that one happens at compile time and another in runtime. Shared object will always exists as one exact file that will be shared across.

A shared object, shared library or `.so` file is a compiled ELF file that is linked into your program at run time. The benefit of a shared object is that the code is transported outside your final product meaning your ELF will be smaller without the duplicated code inside. however, this means that for your code to run, you will need to install library in the system root library directory, such as `/lib` or `/usr/lib`

```
# compiling the library
gcc -o shared libteehee.so ./lib.c

# adding the library to a project
gcc -o main main.c -lteehee -L$(pwd)/lib
```
