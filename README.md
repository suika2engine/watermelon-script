Watermelon Script
=================

Watermelon Script (WMS) is a plugin language for Suika2.
It is designed to be intuitive and easily written by anyone who has any experience with programming.

This repository provides command line interface (CLI) for WMS.
New language features will be tested in this repository and then incorporated into Suika2.

Functions
---------

A program starts from `main()` function.
```
func main() {
    // Print "Hello, world!"
    print("Hello, world!");
}
```

Types and Variables
-------------------

We have integer, floating point, string and array types.
An array element has a key and its type can be integer, floating point and string.
An array of an array is permitted.
```
func main() {
    a = 1;
    b = 1.0;
    c = "1.0";
    d[0] = 0;
    e["key"] = d;
}
```

Loops
-----

We have a syntax for simple integer-range loop.
```
func main() {
    for(i in 0..9) {
        print(i);
    }
}
```

We have for-each style syntax.
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

We have for-each with key style syntax.
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

We have while syntax.
```
func main() {
    a = 10;
    while (a > 0) {
        print(a);
        a = a - 1;
    }
}
```

Branches
--------

We have `if` - `else if` - `else` syntax.
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
