package Java8_Programs;

public class SecondLargestWord {
    public static void main(String[] args){
        String str = "We have to find even lngth second asghhhhh length word in string";
        String[] arrStr = str.split(" ");
        String largestElement= "";
        String secondLargestElement = "";
        for(int i =0; i<arrStr.length; i++){
            if(arrStr[i].length()%2==0 && arrStr[i].length()>largestElement.length()) {
                secondLargestElement = largestElement;
                largestElement = arrStr[i];
            }
        }
        System.out.println("Largest Element " +largestElement);
        System.out.println("Second Largest Element " +secondLargestElement);

    }
}
