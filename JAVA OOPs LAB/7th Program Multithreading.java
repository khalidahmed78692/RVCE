import java.util.Random;
import java.util.LinkedList;

class Market{
    LinkedList<String> list=new LinkedList<>();
    final int capacity=5;
    String[] fruits={"Apple","Orange","Grapes","Watermelon"};
    Random random=new Random();

    public void produce() throws InterruptedException{
        while (true) {
            synchronized (this) {
                while (list.size() == capacity)
                    wait();
                String fruit = fruits[random.nextInt(4)];
                System.out.println("Farmer Produced: " + fruit);
                list.add(fruit);
                notifyAll();
                Thread.sleep(500);
            }
        }
    }

    public void consume()throws InterruptedException{
        while (true) {
            synchronized (this) {
                while (list.size() == 0)
                    wait();
                String fruit = list.removeFirst();
                System.out.println("Consumer bought: " + fruit);
                notifyAll();
                Thread.sleep(500);
            }
        }
    }
}

public class Program7{
    public static void main(String[] args) throws InterruptedException{
        final Market market=new Market();

        Thread t1=new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    market.produce();
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        });

        Thread t2=new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    market.consume();
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        });

        t1.start();
        t2.start();
        t1.join();
        t2.join();
    }
}



/*

Output of the code

"C:\Users\MOHAMMED KHALID\Downloads\openjdk-18.0.1.1_windows-x64_bin\jdk-18.0.1.1\bin\java.exe" "-javaagent:C:\Program Files\JetBrains\IntelliJ IDEA Community Edition 2022.1.1\lib\idea_rt.jar=49186:C:\Program Files\JetBrains\IntelliJ IDEA Community Edition 2022.1.1\bin" -Dfile.encoding=UTF-8 -classpath "D:\Code with Harry\Java materials\LABPrograms\out\production\LABPrograms" Program7
Farmer Produced: Watermelon
Farmer Produced: Orange
Farmer Produced: Watermelon
Consumer bought: Watermelon
Consumer bought: Orange
Farmer Produced: Watermelon
Farmer Produced: Apple
Consumer bought: Watermelon
Consumer bought: Watermelon
Consumer bought: Apple
Farmer Produced: Apple
Consumer bought: Apple
Farmer Produced: Watermelon
Farmer Produced: Grapes
Consumer bought: Watermelon
Consumer bought: Grapes
Farmer Produced: Grapes
Farmer Produced: Apple
Consumer bought: Grapes
Consumer bought: Apple
Farmer Produced: Apple
Farmer Produced: Orange
Farmer Produced: Watermelon
Farmer Produced: Watermelon
Farmer Produced: Watermelon
Consumer bought: Apple
Consumer bought: Orange
Consumer bought: Watermelon
Consumer bought: Watermelon
Consumer bought: Watermelon
Farmer Produced: Apple
Farmer Produced: Grapes
Farmer Produced: Watermelon
Farmer Produced: Watermelon
Farmer Produced: Grapes
Consumer bought: Apple
Consumer bought: Grapes
Farmer Produced: Orange
Farmer Produced: Watermelon
Consumer bought: Watermelon
Consumer bought: Watermelon
Consumer bought: Grapes
Consumer bought: Orange
Farmer Produced: Apple
Farmer Produced: Orange
Farmer Produced: Apple
Farmer Produced: Grapes
Consumer bought: Watermelon
Consumer bought: Apple
Consumer bought: Orange
Consumer bought: Apple
Consumer bought: Grapes
Farmer Produced: Apple
Farmer Produced: Apple
Farmer Produced: Grapes
Farmer Produced: Orange
Farmer Produced: Grapes
Consumer bought: Apple
Consumer bought: Apple
Consumer bought: Grapes
Consumer bought: Orange
Consumer bought: Grapes
Farmer Produced: Apple
Farmer Produced: Watermelon
Consumer bought: Apple
Consumer bought: Watermelon
Farmer Produced: Watermelon
Farmer Produced: Apple
Consumer bought: Watermelon
Consumer bought: Apple
Farmer Produced: Grapes
Farmer Produced: Apple
Consumer bought: Grapes
Consumer bought: Apple
Farmer Produced: Grapes
Farmer Produced: Watermelon
Farmer Produced: Grapes
Farmer Produced: Grapes
Consumer bought: Grapes
Consumer bought: Watermelon
Consumer bought: Grapes
Farmer Produced: Watermelon
Farmer Produced: Grapes
Consumer bought: Grapes
Consumer bought: Watermelon
Consumer bought: Grapes
Farmer Produced: Watermelon
Farmer Produced: Orange
Farmer Produced: Orange
Farmer Produced: Orange
Farmer Produced: Orange
Consumer bought: Watermelon
Consumer bought: Orange
Farmer Produced: Apple
Farmer Produced: Grapes
Consumer bought: Orange
Consumer bought: Orange
Consumer bought: Orange
Consumer bought: Apple
Farmer Produced: Apple
Farmer Produced: Watermelon
Consumer bought: Grapes
Consumer bought: Apple
Consumer bought: Watermelon
Farmer Produced: Orange
Farmer Produced: Orange
Farmer Produced: Orange

Process finished with exit code -1



*/
