import java.util.Scanner;

class DemonetizationException extends Exception{
    float amount;
    DemonetizationException(float amount)
    {
        this.amount=amount;
    }
    public String toString(){
        return "Deposit of OLD currency of Rs:"+amount+" crosses Rs:5000 and hence cannot be deposited";
    }
}

class Account{
    float balance;

    Account(){
        balance=500;
    }
    void deposit(float amount,String CurrencyType)
    {
        String currency=CurrencyType.toUpperCase();
        try {
            if (currency.equals("OLD") && amount > 5000)
                throw new DemonetizationException(amount);
            balance+=amount;
        }catch (Exception e)
        {
            System.out.println(e);
        }
    }
    void currentBalance()
    {
        System.out.println("A/C balance is: "+balance);
    }
    void withdraw(float amount){
        if(amount<balance&&balance>500) {
            balance -= amount;
            System.out.println("Rs:" + amount + " is withdrawn");
        }
        else if(balance-amount<0)
            System.out.println("No min balance");
    }
}

public class Program6 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        Account acc=new Account();
        byte choice;
        float amount;
        String currencyType;
        while(true)
        {
            System.out.println("1:Deposit\t2:CurrentBalance\t3:Withdraw\t4:Exit");
            System.out.println("Enter your choice: ");
            choice=sc.nextByte();
            switch (choice)
            {
                case 1:
                    System.out.println("Enter the amount to be deposited: ");
                    amount=sc.nextFloat();
                    System.out.println("Enter the currency type: ");
                    currencyType=sc.next();
                    acc.deposit(amount,currencyType);
                    break;
                case 2:
                    acc.currentBalance();
                    break;
                case 3:
                    System.out.println("Enter the amount to be withdrawn: ");
                    amount=sc.nextFloat();
                    acc.withdraw(amount);
                    break;
                default:
                    System.exit(0);
            }
        }
    }
}


/*

Output of the code:

1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
2
A/C balance is: 500.0
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
1
Enter the amount to be deposited: 
5000
Enter the currency type: 
old
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
2
A/C balance is: 5500.0
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
3
Enter the amount to be withdrawn: 
4500
Rs:4500.0 is withdrawn
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
2
A/C balance is: 1000.0
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
3
Enter the amount to be withdrawn: 
5000
No min balance
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
2
A/C balance is: 1000.0
1:Deposit	2:CurrentBalance	3:Withdraw	4:Exit
Enter your choice: 
4

*/
