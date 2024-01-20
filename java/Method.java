public class Method{
    static void myMethod(){
        System.out.println("myMethod just got executed.");
    }

    static void info(String name, int age){
        System.out.println(name + " is " + age + ".");
    }
    public static void main(String[] args){
        myMethod();
        info("Sahil",19);
        myMethod();
    }
}