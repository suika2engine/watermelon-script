Watermelon Script
=================

Watermelon Script (WMS) is a plugin language for Suika2.
It is designed to be intuitive and easily written by anyone who has any experience with programming.

This repository provides command line interface (CLI) for WMS.
New language features will be tested in this repository and then incorporated into Suika2.

## Syntax and Usage

### Defining and Calling Functions

A program starts from `main()` function.
```
func main() {
    // Print "Hello, world!"
    print("Hello, world!");
}
```

You can call other functions.
```
func main() {
    foo(0, 1 2);
}

func foo(a, b, c) {
    return a + b + c;
}
```

### Types and Variables

We have types for integer, floating point, string and array.
An array element has a key and the key must be integer, floating point or string.
```
func main() {
    // Integer
    a = 1;

    // Floating point
    b = 1.0;

    // String
    c = "str";

    // Array (integer key)
    d[0] = 0;

    // Array (string key)
    e["abc"] = 0;

    // Array of array
    f["key"] = e;
}
```

### Loops

We have a simple integer-range loop syntax.
```
func main() {
    for(i in 0..9) {
        print(i);
    }
}
```

We also have a for-each style syntax.
```
func main() {
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;

    for(v in a) {
        print(v);
    }
}
```

We can get key-value pair in for-each loop.
```
func main() {
    a["key1"] = 0;
    a["key2"] = 1;
    a["key3"] = 2;

    for(k, v in a) {
        print(k + "=" + v);
    }
}
```

We have a normal `while` syntax.
```
func main() {
    a = 10;
    while (a > 0) {
        print(a);
        a = a - 1;
    }
}
```

Note that we can use `break` and `continue` in loops.
```
func main() {
    for(i in 0..9) {
        if(i == 2) {
            continue;
        }
        if(i == 7) {
            break;
        }
        print(i);
    }
```

### Branches

We can make branches by `if` - `else if` - `else` syntax.
```
func main() {
    a = foo();
    if(a > 10) {
        print("a > 10");
    } else if(a > 5) {
        print("a > 5");
    } else {
        print("else");
    }
}

func foo() {
    return 6;
}
```
