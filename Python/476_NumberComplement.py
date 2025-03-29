class Solution:
    def findComplement(self, num: int) -> int:
        bin_num = list(bin(num)[2:])
        for i in range(len(bin_num)):
            if bin_num[i] == '1':
                bin_num[i] = 0
            if bin_num[i] == '0':
                bin_num[i] = 1

        s = [str(i) for i in bin_num]
        res = "".join(s)
        return int(res, 2)
