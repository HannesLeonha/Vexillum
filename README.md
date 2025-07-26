<img src="https://raw.githubusercontent.com/HannesLeonha/Vexillum/refs/heads/master/docs/assets/images/hero.svg">
<img src="https://hackatime-badge.hackclub.com/U092HP2LVNU/Vexillum"><br>
This c library takes the arguments which the program received and parses them into a nicely accessible form.

## Demo
Here is a small demonstration of how the library works: <a href="https://hannesleonha.github.io/Vexillum/">https://hannesleonha.github.io/Vexillum/</a>.

## Name
If you are wondering where I got the name from. I remembered that the study of flags is called Vexillology. That name comes from the latin word for flag which is vexillum.

## Form
The form with which the arguments will get converted is based on how shell scripts handle flags.

### Loose arguments
A loose argument is a piece of text that can be anywhere in the program arguments, but it can't start with a dash as that would make it a flag. They are seperated by spaces, but you can have arguments with spaces by using quotes (probably depends on how it is implemented in the terminal)
 - `program.exe path/to/some/file "Argument with spaces" -l "Argument between flags" -s`

### Flags
It starts with a dash and has two variants. Short flags which are just one letter (case-sensitive). They can also be combined by using one dash and putting multiple letters after it. The other variant is a long flag which starts with two dashes and only contains lowercase words seperated by dashes.
 - Short flags: `program.exe -l -s -R`
 - Combined flags: `program.exe -lsR`
 - Long flags: `program.exe -rf --no-preserve-root`

### Options with arguments
When setting the library up you can also specify that the flag has an argument after it. In that case the library expects an argument after the flag. If no argument is found the library will throw an error (see usage). Both long and short flags can have arguments but short flags can't be combined with other flags when this option is used.
 - `program.exe -f path/to/file --username Toast -p 7&NjT%8&`

## Usage
To use the library add the built library in your build system and include it with `#include "Vexillum.h"`.

### Functions
This section will be added in the future as the library has not been implemented yet.
