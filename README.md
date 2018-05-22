# Arduino_Pd

Arduino_Pd

This repository is a set of Pd abstractions (both vanilla and extended) and Arduino code that facilitates the communication between the two platforms.

`[serial_print]` (and its extended counterpart `[serial_print_extended]`) works with the `Serial.print()` and `Serial.println()` functions of the Arduino.  
Even though Pd-extended is not developed or supported in any way any more, I'm still including an extended version of `[serial_print]` for those who still use this software. This version is in the Pd-extended_version/ directory of this repository.

`[serial_write]` works with the `Serial.write()` function of the Arduino.

Check their help patches and Arduino code for more information.

`[serial_print13]` is a version of `[serial_print]` for systems that can't get the number 13 passed from an Arduino to Pd. To test if this is the one you need, load the 13bug.ino sketch to your Arduino, then in Pd, connect `[comport]` to `[print]`. If Pd prints 13, you don't need this version, but it it prints 10, then use this instaed of `[serial_print]`.

Written by Alexandros Drymonitis




Update December 2015: enabled sending lists including symbols under one tag

Update December 2015: corrected the issue with sending a bang while there is data saved in the abstraction

Update December 2015: enabled the word "float" to be used as a tag in "serial_print_extended" (although it's probably not a good idea to use this word in Pd...)
