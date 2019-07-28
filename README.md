# monkeypatch

The `monkeypatch` package provides an interface to add user-defined methods to built-in types.


## The wish!

Sadly, in Python, this code raises `TypeError: can't set attributes of built-in/extension type 'str'`:

```
    str.hello = "world"
```

Although you can easily add attributes to your custom types, modifying built-in types, like `str`, is usually off-limits in Python.

Until now...


## Examples

Here are some interesting possibilities:

Add a `str` method to, say, reverse and uppercase strings:

```
    from monkeypatch import monkeypatch

    def rev_up(self):
        return self[::-1].upper()

    monkeypatch(str, "rev_up", rev_up)

    assert "abc".rev_up() == "CBA"
```

Add a method to Python's `int` to work like Ruby's [upto](https://ruby-doc.org/core-2.5.0/Integer.html#method-i-upto):

```
    from monkeypatch import monkeypatch

    def upto(self, value):
        return tuple(range(self, value + 1))

    monkeypatch(int, "upto", upto)

    assert (1).upto(10) == (1,2,3,4,5,6,7,8,9,10)
```

Add a method to `tuple` to multiply all items by some value:

```
    from monkeypatch import monkeypatch

    def mult_by(self, value):
        return tuple(x * value for x in self)

    monkeypatch(tuple, "mult_by", mult_by)

    assert (1,2,3).mult_by(10) == (10,20,30)
```
