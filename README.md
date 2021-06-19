# rpc-dice
RPC program for rolling d6 dice with additional settings!

#### Input parameters:
```c
struct inputData{
  int numOfRolls;       // number of rolls
  int threshold;        // [optional] value from which a roll is considered as successfull
  bool hasFullReroll;   // [optional] if full reroll is enabled
  bool hasRerollAtOne;  // [optional] if reroll of 1 is enabled
};
```

#### Output
```c
struct outputData{
  int successfull;  // number of successfull rolls (>= threshold)
  int six;          // number of 6 rolls
  int one;          // number of 1 rolls
};
```

## Run server
```shell
$ make
$ ./server
```

## Run client
```shell
$ make
$ ./client server_address numOfRolls [threshold] [hasFullReroll] [hasRerollAtOne]
```
