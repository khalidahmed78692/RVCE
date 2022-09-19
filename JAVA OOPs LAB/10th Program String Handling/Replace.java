package Program10;

import java.util.*;

public class Replace {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the sentence: ");
        String sentence=sc.nextLine();

        String[] words=sentence.split(" ");
        System.out.println("The replace words in sentence is: ");
        for(byte i=0;i<words.length;i++) {
            if (words[i].toLowerCase().equals("java"))
                words[i] = "Python";
            else if (words[i].toLowerCase().equals("python"))
                words[i] = "Java";
            System.out.print(words[i]+" ");
        }
    }
}


/*

Output of the code:

Enter the sentence: 
Java helps in ML but not python
The replace words in sentence is: 
Python helps in ML but not Java

*/
