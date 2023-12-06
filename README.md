# Cpp_module_04

## Subject

The `42 school` module of `C++` piscine is about
`polymorphism by subtyping` `abstract class` `Interface`

[42's subject in french](./cpp_04_subject.pdf)

Some helpful links to start with:

[Runtime polymorphism](https://www.geeksforgeeks.org/virtual-function-cpp/)

[Copy constructor - deep and shallow copy](https://www.javatpoint.com/cpp-copy-constructor)

## Usage

Executables test the behavior of the respective classes according to the subject requirements. All classes comply to `Coplean canonical form`.

### Compile

Head-up to the directory and `make` for an executable:
```cd ex00 && make```

### Execute

For ex00 through ex02 :
```./a.out```

For ex03 :
```./a.out verbose```

### Memory management

```make leaks``` for valgrind tests.

## Screens

### Animals with brain

*Exercise 00 to 02* are about building an `abstract class` *AAnimal*.
    - *Cat* and *Dog* classes inherit from *Animal*
    - each possesses a *brain* that can hold up to `100 ideas`.

My idea was to represent each idea as an emoji to make tests more explicit and visual.

```ex02
TEST 2
______________________________________________
🔧 (AAnimal parametric constructor): a new AAnimal was created. it is a Cat ! 
💭 (Brain default constructor): a Brain was created. 
🐱 (Cat default constructor): created a Cat 🐈

🔧 (AAnimal default constructor): a default AAnimal was created. it is a type undefined
💭 (Brain default constructor): a Brain was created. 
🐱 (Cat copy assignment operator):  Cat was updated to another Cat's attributes
💭 (Brain destructor)
💭(Brain copy constructor): brain cloned 
🐱 (Cat copy constructor): a clone of Cat type was created.

🔧 (AAnimal parametric constructor): a new AAnimal was created. it is a Cat ! 
💭 (Brain default constructor): a Brain was created. 
🐱 (Cat default constructor): created a Cat 🐈

kitten1 : 📖  0x7ffe70b70030 : Cat
              0x1ae9300 : 💭 Brain   🐈🐀🔧💥🍴🍖⭐⭐⭐⭐⭐
kitten2 : 📖  0x7ffe70b6ff78 : Cat
              0x1ae9fd0 : 💭 Brain   🐈🐀🔧⭐⭐⭐⭐⭐⭐⭐⭐
kitten3 : 📖  0x1ae9f90 : Cat
              0x1aeac60 : 💭 Brain   ⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐⭐

🐱 (Cat copy assignment operator):  Cat was updated to another Cat's attributes
💭 (Brain destructor)
💭(Brain copy constructor): brain cloned 
kitten3 : 📖  0x1ae9f90 : Cat
              0x1aeac60 : 💭 Brain   🐈🐀🔧💥🍴🍖⭐⭐⭐⭐⭐

______________________________________________
kitten1 : 📖  0x7ffe70b70030 : Cat
              0x1ae9300 : 💭 Brain   ⭐🐀🔧💥🍴⭐⭐⭐⭐⭐⭐
kitten2 : 📖  0x7ffe70b6ff78 : Cat
              0x1ae9fd0 : 💭 Brain   🐈🐀⭐⭐⭐⭐⭐⭐⭐⭐⭐
kitten3 : 📖  0x1ae9f90 : Cat
              0x1aeac60 : 💭 Brain   🐈⭐🔧⭐🍴🍖⭐⭐⭐⭐⭐
💭 (Brain destructor)
🐱 (Cat destructor): RIP little Cat ! 
➖ (AAnimal destructor): RIP little Cat ! 
💭 (Brain destructor)
🐱 (Cat destructor): RIP little Cat ! 
➖ (AAnimal destructor): RIP little Cat ! 
💭 (Brain destructor)
🐱 (Cat destructor): RIP little Cat ! 
➖ (AAnimal destructor): RIP little Cat ! 

```

### Materias

*Exercise 03* consists of a *character* that can `equip` or `unequip` or `use` *Materias* from his *backpack*. These materias are of two kinds : *Cure* and *Ice* that are produced by a *materia source*. The latest can learn new Materia and becomes a source of eithe *Ice* or *Cure*.

**Spoiler : The caracter can use these materia `without unequiping or destroying it`.**

`Character` derives from an `interface` `ICharacter`.
`Ice` and `Cure` derive from an `abstract class` `AMateria`.
`MateriaSource` also derives from an `interface`. 


```ex03
TEST 1
______________________________________________
 MSource default constr. 
🔧 AMat. param. 💠 def.          MSource[0] learned ice
🔧 AMat. param. 💖 def.          MSource[1] learned cure
🙅 Param. me

🕵        me  🆓 🆓 🆓 🆓 

 MSource[0] = ice 
💠 ice clone 🔧 AMat. def. 💠 copy  = ice 
equip :  + 1 ice to backpack[0]
 MSource[1] = cure 
💖 cure clone 🔧 AMat. def. 💖 copy  = cure 
equip :  + 1 cure to backpack[1]

🕵        me  💠 💖 🆓 🆓 

🙅 Param. bob

* shoots an ice bolt at bob *

🕵        me  💠 💖 🆓 🆓 

* Heals bob's wounds *

🕵        me  💠 💖 🆓 🆓 


➖ 🙅 bob
➖ ice ➖
➖ cure ➖
➖ 🙅 me
➖ ice ➖
➖ cure ➖
➖ MSource destruction

```

## Emojis

Emojis were used. The `ANSI unicode` was obtained from the following repo [Unicode Emoji](https://github.com/99x/emojicpp).
