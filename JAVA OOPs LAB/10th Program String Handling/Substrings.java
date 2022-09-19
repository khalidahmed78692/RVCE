package Program10;

import java.util.*;

public class Substring {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the sentence: ");
        String sentence=sc.nextLine();

        System.out.println("Enter the character/s from which the sentence has to be divided into substrings: ");
        String substring=sc.next();

        String[] words=sentence.split(substring);

        System.out.println("The resulting substrings are: ");
        for(String str:words)
            System.out.println(str);
    }
}




/*

Output of the code:

Enter the sentence: 
Hi this is intelliJ
Enter the character/s from which the sentence has to be divided into substrings: 
 
i
The resulting substrings are: 
H
 th
s 
s 
ntell
J



Enter the sentence: 
Java help for android development
Enter the character/s from which the sentence has to be divided into substrings: 
for
The resulting substrings are: 
Java help 
 android development

*/
