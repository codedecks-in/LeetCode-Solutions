//Runtime: 81ms   Memory: 36.68MB
public class Solution {
    public string DefangIPaddr(string address) {
        return new StringBuilder(address).Replace(".","[.]").ToString();
    }
}
