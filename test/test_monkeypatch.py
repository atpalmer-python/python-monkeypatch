import pytest
from monkeypatch import monkeypatch


def test_monkeypatch_hello():
    with pytest.raises(TypeError):
        str.hello = "world"
    monkeypatch(str, "hello", "world")
    assert str.hello == "world"


def test_monkeypatch_str():
    def rev_up(self):
        return self[::-1].upper()
    monkeypatch(str, "rev_up", rev_up)
    assert "abc".rev_up() == "CBA"


def test_monkeypatch_int():
    def upto(self, value):
        return tuple(range(self, value + 1))
    monkeypatch(int, "upto", upto)
    assert (1).upto(10) == (1,2,3,4,5,6,7,8,9,10)


def test_monkeypatch_tuple():
    def mult_by(self, value):
        return tuple(x * value for x in self)
    monkeypatch(tuple, "mult_by", mult_by)
    assert (1,2,3).mult_by(10) == (10,20,30)
