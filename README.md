# atm

This code is implemented as a ATM contoller.
It would be used API.

It could check the card number validation and verify pin number.
You could see the account number related the card.
After select account, you could see the balance, deposit and withdraw.

## Build & Test
* clone this repository
* open this solution in the visual studio (I used visual studio 2022)
* build solution with below setting
  * setting > c/c++ > code generator(?) > runtime library > MDd(debug mode) or MTd(release mode)
* run to test

*Note*

I already make the json file for the test.
The test file is atm_test.json. You could make the json your own.
Just run the test.cpp file and it will load json and read data.
If you want other data, you need to edit the test.cpp file.

