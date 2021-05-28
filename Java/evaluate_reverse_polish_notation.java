// T.C:- O(n)
//   S.C- O(n)

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        int a,b;
        for(String s: tokens){
            if(s.equals("+")){
                st.add(st.pop()+st.pop());
            }
            else if(s.equals("*")){
                st.add(st.pop() * st.pop());
            }
            else if(s.equals("/")){
                b=st.pop();
                a = st.pop();
                st.add(a/b);
            }
            else if(s.equals("-")){
                b = st.pop();
                a = st.pop();
                st.add(a-b);
            }
            else{
                st.add(Integer.parseInt(s));
            }
        }
        return st.pop();
    }
}
