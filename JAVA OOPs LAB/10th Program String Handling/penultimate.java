package Program10;

import java.util.Scanner;

public class Penaultimate {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the sentence: ");
        String input=sc.nextLine();
        String words[]=input.split(" ");

        System.out.println("The penultimate word is: "+words[words.length-2]);
        sc.close();
    }
}


/*

Output of the code:

Enter the sentence: 
Hi this is Khalid
The penultimate word is: is



Enter the sentence: 
JAVA OOPS
The penultimate word is: JAVA



*/
