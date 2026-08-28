# test_solution.py
from solution import my_atoi

def test_simple_positive_number():
    assert my_atoi("42") == 42

def test_handles_whitespace_and_negative_sign():
    assert my_atoi("   -42") == -42

def test_stops_at_non_digit_characters():
    assert my_atoi("4193 with words") == 4193

def test_clamps_to_max_int_on_overflow():
    INT_MAX = 2**31 - 1
    assert my_atoi("2147483648") == INT_MAX

def test_clamps_to_min_int_on_underflow():
    INT_MIN = -2**31
    assert my_atoi("-2147483649") == INT_MIN