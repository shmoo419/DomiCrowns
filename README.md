# DomiCrowns
### @hackedbyshmoo

#### I have purposely made this unable to be compiled unless you're familiar with C/C++ datatypes.
#### If you want to go through the trouble of re-creating structs for Dictionary and List, go ahead.

An unpatched crowns hack for Dominations v6.631.632 as of June 12, 2018.
The developers have patched a lot of (but not all) holes in the game relating to crowns.
There is a variable in the game called `STARTING_GEMS`. Default value is 50. This is the amount of crowns you start with.
If you make a new account, you can change the value of that variable to anything and the server will accept it. ¯\_(ツ)_/¯

Why open source something like this? Because this is an amazing example of:
- Using a struct to lay out memory rather than doing ugly pointer arithmetic yourself
- Aligning the sizes of all the members in a struct correctly so the machine assigns all members correct values.
- Hacking a static member
- Using threads to hack said static member

You can find the `GlobalVars` struct I mentioned in the tutorial below in the source folder.

Tutorial: https://iosgods.com/topic/70716-static-members-and-multithreading/

Video: https://www.youtube.com/watch?v=wmyElM6xNZY