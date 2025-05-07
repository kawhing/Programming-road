public class people{
    int age;
    void speaking(){
        System.out.println("I am a student");
    }
    public static void main(String[] args) {
        people s1 = new people();
        s1.age = 22;
        s1.speaking();
        System.out.println(s1.age);
    }
}