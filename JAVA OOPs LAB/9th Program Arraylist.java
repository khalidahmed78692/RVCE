import java.util.*;

class Arrays{
    ArrayList<String> list=new ArrayList<>();

    public void addItems(String color){
        list.add(color);
    }

    public void displayItems(){
        if(list.size()==0)
            System.out.println("Empty list");
        else
            System.out.println("List items are: "+list);
    }

    public void toArray(){
        if(list.size()==0)
            System.out.println("Empty list");
        else{
            String[] array=new String[list.size()];
            list.toArray(array);
            System.out.println("Array contents are: ");
            for(String str:array)
                System.out.println(str);
        }
    }

    public void revList(){
        if(list.size()==0)
            System.out.println("List Empty");
        else{
            ArrayList<String> revlist=new ArrayList<>();
            for(int i=list.size()-1;i>=0;i--)
                revlist.add(list.get(i));
            System.out.println("Reversed list is: "+revlist);
        }
    }

    public void subArray(int start, int end){
        if(start<0||end>list.size())
            System.out.println("Invalid indices");
        else {
            ArrayList<String> newlist=new ArrayList<>(list.subList(start,end));
            System.out.println("Sub Array is of list from "+start+" to end "+end+" is: "+newlist);
        }
    }

    public void sortArray(){
        if(list.size()==0)
            System.out.println("List Empty");
        else{
            Collections.sort(list);
            System.out.println("Sorted array is: "+list);
        }
    }

    public void cloneArray(){
        if(list.size()==0)
            System.out.println("List Empty");
        else {
            ArrayList<String> clonelist=(ArrayList<String>)list.clone();
            System.out.println("Cloned list: "+clonelist);
        }
    }
}

public class Program9 {
    public static void main(String[] args) {
        Arrays obj=new Arrays();
        byte choice,start,end;
        String color;
        Scanner sc=new Scanner(System.in);
        while(true){
            System.out.println("1:Add items to the list");
            System.out.println("2:Display items of the list");
            System.out.println("3:Convert list to Array");
            System.out.println("4:Reverse list");
            System.out.println("5:Print subArray");
            System.out.println("6:Sort the list");
            System.out.println("7: clone list");
            System.out.println("Enter your choice: ");
            choice=sc.nextByte();
            switch (choice)
            {
                case 1:
                    System.out.println("Enter the color: ");
                    color=sc.next();
                    obj.addItems(color);
                    break;
                case 2:
                    obj.displayItems();
                    break;
                case 3:
                    obj.toArray();
                    break;
                case 4:
                    obj.revList();
                    break;
                case 5:
                    System.out.println("Enter the start and end indices: ");
                    start=sc.nextByte();
                    end=sc.nextByte();
                    obj.subArray(start,end);
                    break;
                case 6:
                    obj.sortArray();
                    break;
                case 7:
                    obj.cloneArray();
                    break;
                default:
                    System.exit(0);
            }
        }
    }
}



/*

Output of the code:


1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
1
Enter the color: 
red
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
2
List items are: [red]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
1
Enter the color: 
blue
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
1
Enter the color: 
green
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
2
List items are: [red, blue, green]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
3
Array contents are: 
red
blue
green
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
4
Reversed list is: [green, blue, red]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
2
List items are: [red, blue, green]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
5
Enter the start and end indices: 
1
1
Sub Array is of list from 1 to end 1 is: []
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
5
Enter the start and end indices: 
0
1
Sub Array is of list from 0 to end 1 is: [red]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
6
Sorted array is: [blue, green, red]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
7
Cloned list: [blue, green, red]
1:Add items to the list
2:Display items of the list
3:Convert list to Array
4:Reverse list
5:Print subArray
6:Sort the list
7: clone list
Enter your choice: 
8

	
*/
