class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """
        Approach:
        - Handle edge case: overflow when dividend = -2^31 and divisor = -1
        - Work with absolute values to simplify calculation.
        - Use bit manipulation (left shifts) to speed up repeated subtraction:
            - Keep doubling the divisor until it exceeds dividend.
            - Subtract the largest multiple of divisor from dividend and accumulate quotient.
        - Apply sign at the end based on the input signs.

        Intuition:
        - Division is repeated subtraction.
        - Using bit shifts allows us to subtract large chunks at once, reducing complexity from O(n) to O(log n)^2.

        Time Complexity: O(log(dividend)^2), because we double the divisor each time and subtract in a loop.
        Space Complexity: O(1), only constant extra variables are used.
        """
        # 32-bit integer limits
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Edge case for overflow
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        # Determine the sign of the result
        negative = (dividend < 0) != (divisor < 0)

        # Work with absolute values
        dividend, divisor = abs(dividend), abs(divisor)
        quotient = 0

        # Repeated subtraction using bit shifts
        while dividend >= divisor:
            temp_divisor, multiple = divisor, 1
            while dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            dividend -= temp_divisor
            quotient += multiple

        # Apply sign
        if negative:
            quotient = -quotient

        return quotient
